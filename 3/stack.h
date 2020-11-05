#ifndef STACK3_HW3_H
#define STACK3_HW3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_CAPACITY 20


// stack of bounded capacity 
typedef struct {
    int capacity;
    int* ar;
    int head;
} stack3_t; 

// creates a new stack
stack3_t* stack_create();

// pushes a given item to the stack
// Returns item if the operation is successful
int stack_push(stack3_t* s, int item);

// pops the top element from the stack
// Pre condition: stack is not empty
int stack_pop(stack3_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack3_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
void stack_free(stack3_t* s);


// returns the number of elements in the stack
int stack_length(stack3_t* s);


// checks if all elements in s1 are < than all elements in s2
bool stack_strictly_less(stack3_t* s1, stack3_t* s2);


#endif