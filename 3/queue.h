#ifndef QUEUE_HW3_H
#define QUEUE_HW3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  // implement me
} queue_t;


// creates a new queue
// if malloc fails, returns NULL
queue_t* queue_create();

// add a given item to the queue
// if everything works ok, returns same q as the input
// if malloc fails, returns NULL
queue_t* enqueue(queue_t* q, int item);

// removes an element from the queue
// Pre condition: queue is not empty
int dequeue(queue_t* q);

// checks if the queue is empty
bool queue_is_empty(queue_t* q);

// returns the length of the queue
// if q==NULL, returns -1
int queue_length(queue_t* q);

// frees the queue
// if q==NULL, returns -1
void queue_free(queue_t* q);



#endif