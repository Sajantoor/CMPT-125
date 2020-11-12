#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

///////////////////////////////////////
//////// queue  implementation ////////
///////////////////////////////////////

// creates a new queue
// if malloc fails, returns NULL
queue_t* queue_create() {
  queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
  // if OS cannot allocate memory
  if (queue == NULL) {
    return NULL;
  }

  // intialize array with size of 5
  queue->arr = (int *) malloc(sizeof(int) * 5);
  // os cannot allocate memory
  if (queue->arr == NULL) {
    return NULL;
  }

  // init head and tail 
  queue->head = 0; 
  queue->tail = 0;
  queue->size = 5;
  return queue;
}


// add a given item to the queue
// if everything works ok, returns same q as the input
// if malloc fails, returns NULL
queue_t* enqueue(queue_t* q, int item) {
  // validate parameters 
  if (q == NULL) {
    return NULL;
  }

  // add element to array
  // add item normally 
  if (q->tail != (q->size -1) && (q->tail != q->head || q->tail == 0)) {  
    q->arr[q->tail] = item; 
    q->tail++;
  // circular adding of items 
  } else if ((q->tail == (q->size - 1)) && (q->head > 0)) {
    q->arr[q->tail] = item; 
    q->tail = 0;
  // expand array and copy 
  } else if (q->tail == (q->size -1)) {
    // create new array 
    int* newArray = (int*) malloc(sizeof(int) * q->size*2); 
    // OS cannot allocate memory for new array
    if (newArray == NULL) {
      queue_free(q);
      return NULL; 
    }

    // temp "pointers"
    int head = q->head; 
    int tail = q->tail; 
    int size = q->size;
    int i = 0; 

    // copies all items from original array to new array 
    // do while as it needs to execute at least once as head == tail at start
    do {
      newArray[i] = q->arr[head];
      // run through array normally 
      if (head != size - 1) {
        head++;
      // go to beginning of array and copy those items -> in out of bounds
      } else {
        head = 0;
      }

      i++;
    } while(head != tail);

    // set queue struct to new array 
    q->size *= 2; 
    q->head = 0; 
    q->tail = i; 
    // free old array
    free(q->arr);
    // set pointer to new array 
    q->arr = newArray; 
    // add item newest ite
    q->arr[q->tail] = item; 
    q->tail++; 
  }

  return q;
}

// removes an element from the queue
// Pre condition: queue is not empty
int dequeue(queue_t* q) {
  // validate parameters 
  if (q == NULL) {
    return 0; 
  }

  // to dequeue: queue must not be empty 
  if (queue_is_empty(q)) {
    return 0;
  }

  // dequeued value 
  int value = q->arr[q->head];

  // if reach end, circle around 
  if (q->head == q->size -1) {
    q->head = 0;
  // else dequeue normally 
  } else {
    q->head++;
  }

  return value;
}

// checks if the queue is empty
bool queue_is_empty(queue_t* q) {
  // validate params
  if (q == NULL) {
    return true;
  }

  // head == tail then empty list
  if (q->head == q->tail) {
    return true;
  } 

  return false;
}

// returns the length of the queue
// if q==NULL, returns -1
int queue_length(queue_t* q) {
  // validate parameters
  if (q == NULL) {
    return -1;
  }
  // empty list = 0  
  // if q->head == q->tail
  if (queue_is_empty(q)) {
    return 0; 
  }
 
  if (q->head < q->tail) {
    return q->tail - q->head; 
  // if q->head > q->tail 
  } else {
    return q->size - q->head + q->tail;
  }

  return 0;
}

// frees the queue
// if q==NULL, returns -1
void queue_free(queue_t* q) {
  // don't need to validate q->arr since in the implementation if arr is NULL returns NULL
  if (q == NULL) {
    return; 
  }
  
  // free array in queue 
  free(q->arr); 
  q->arr = NULL; 
  free(q); 
  q = NULL; 
}
