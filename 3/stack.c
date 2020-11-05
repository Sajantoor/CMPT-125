#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


// creates a new stack
stack3_t* stack_create()
{
    stack3_t* s = (stack3_t*) malloc(sizeof(stack3_t));
    if (s == NULL)
      return NULL;

    s->ar = (int*) malloc(INIT_CAPACITY*sizeof(int));
    if (s->ar == NULL)
      return NULL;

    s->capacity = INIT_CAPACITY;
    s->head = 0;
    return s;
}

// pushes a given item to the stack
// Returns item if the operation is successful
int stack_push(stack3_t* s, int item)
{

    if (s->head == s->capacity)
    {
        s->ar = (int*) realloc(s->ar, (s->capacity)*2*sizeof(int));
        if (s->ar == NULL)
          return 0;

        s->capacity = (s->capacity)*2;

        printf("increase size --> %d\n", s->capacity);
    }

    (s->ar)[s->head] = item;
    (s->head)++;

    return item;
}

// pops the top element from the stack
// Pre condition: stack is not empty
int stack_pop(stack3_t* s)
{
    if (stack_is_empty(s))
    {
      printf("STACK IS EMPTY!");
      return -1;
    }
    (s->head)--;
    return (s->ar)[s->head];
}

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack3_t* s)
{
    return (s->head==0);
}

// releases the memory used by stack
void stack_free(stack3_t* s)
{
    free(s->ar);
    free(s);
}


// ---------------- Question 3a -------------------
// returns the number of elements in the stack
int stack_length(stack3_t* s) {
  // validating parameters 
  if (s == NULL) {
    return -1; 
  }

  // empty stack return 0
  if (stack_is_empty(s)) {
    return 0;
  }
  
  // cannot modify stack directly, create duplicate of stack, to recreate stack 
  // values can only be read using pop and push
  stack3_t * duplicate = stack_create();
  int popVal = 0; // pop returns the item or -1 if empty
  int counter = 0; // gets length of stack 

  // while stack is not empty 
  while (popVal != -1) {
    popVal = stack_pop(s);
    if (popVal == -1) {
      break; 
    }

    // pushes the value to duplicate 
    stack_push(duplicate, popVal);
    counter++;
  }

  // recreates the original stack
  for (int i = 0; i < counter; i++) {
    popVal = stack_pop(duplicate); 
    // check for -1 => possibly unneccessary    
    stack_push(s, popVal);
  }

  // duplicate is not needed, memory leak
  stack_free(duplicate); 
  return counter;
}

// -------------- Queston 3b ------------------------------ 

typedef struct {
  int* data;
  unsigned int len;
} arr;

// converts stack to array using stack functions
arr* stackToArray(stack3_t* s) {
    // creates an array for the stack
  int popVal = 0; 
  arr* ar = malloc(sizeof(arr)); 
  ar->data = malloc(sizeof(int));
  ar->len = 0;

  while (popVal != -1) {
    popVal = stack_pop(s); 
    
    if (popVal == -1) {
      break;
    }

    ar->len++;
    ar->data = realloc(ar->data, sizeof(int) * ar->len);
    // OS cannot allocate memory
    if (ar->data == NULL) {
      return NULL;
    }

    ar->data[ar->len] = popVal;
  }

  return ar;
}


// All elements must be checked so O(n^2) 
bool stack_strictly_less(stack3_t* s1, stack3_t* s2) {
  // probably easier to create 2 arrays and loop through
  // stacks cannot be modified, once item is removed must be added back later

  // validate parameters 
  if (s1 == NULL || s2 == NULL) {
    return false;
  }

  // true if either one of the stacks is empty
  if (stack_is_empty(s1) || stack_is_empty(s2)) {
    return true;
  }

  arr * s1Array = stackToArray(s1);
  arr * s2Array = stackToArray(s2);

  bool result = false; 

  // loops through both arrays and check if s1Array > s2Array
  for (int i = 0; i < s1Array->len && !result; i++) {
    for (int j = 0; j < s2Array->len && !result; j++) {
      if (s2Array->data[j] > s1Array->data[i]) {
        result = true; 
      }
    }
  }

  // puts data back in stack
  for (int i = s1Array->len; i > 0; i--) {
    stack_push(s1, s1Array->data[i]); 
  }

  for (int i = s2Array->len; i > 0; i--) {
    stack_push(s2, s2Array->data[i]); 
  }

  return result;
}

