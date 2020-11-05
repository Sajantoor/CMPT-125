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


int stack_length(stack3_t* s) {
  // implement me
  return false;
}

bool stack_strictly_less(stack3_t* s1, stack3_t* s2) {
  // implement me
  return false;
}

