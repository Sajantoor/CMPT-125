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

bool stack_strictly_less(stack3_t* s1, stack3_t* s2) {
  // implement me
  return false;
}

