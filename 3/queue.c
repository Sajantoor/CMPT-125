#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#define QUEUE = 1;


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

  queue->arr = (int *) malloc(sizeof(int) * 5); // intialize array with size of 5
  if (queue->arr == NULL) {
    return NULL;
  }

  // init head and tail 
  queue->head = 0; 
  queue->tail = 0;
  queue->size = 5;
  #ifdef QUEUE
    printf("Created queue successfully! \n");
  #endif

  return queue;
}

// add a given item to the queue
// if everything works ok, returns same q as the input
// if malloc fails, returns NULL

// add item to tail 
queue_t* enqueue(queue_t* q, int item) {
  // validate parameters 
  if (q == NULL) {
    return NULL;
  }

  // add element to array
  // move tail++ if not end of array
  // tail is circular is head is greater than 0 and tail is equal to the size of the array
  // Expanded if tail == head -> gotta move everything from head -> end of array -> tail 
      // head = 0, tail is the last element in the array + 1 -> the enqueued element
  
  // regular adding of items 
  // q->tail == 0 because if empty both gonna be zero so need to fix that
  if (q->tail != (q->size -1) && (q->tail != q->head || q->tail == 0)) {  
    q->arr[q->tail] = item; 
    #ifdef QUEUE
     printf("Added item (%d) to array normally at ar[%d]!\n", item, q->tail);
    #endif
    q->tail++;
  // circular adding of items 
  } else if (q->tail == (q->size - 1) && q->head > 0) {
    q->arr[q->tail] = item; 
    q->tail = 0;
  // expand array and copy 
  } else if (q->tail == (q->size -1) || q->tail == q->head) {
    // create new array 
    int* newArray = (int*) malloc(sizeof(int) * q->size*2); 
    // OS cannot allocate memory for new array
    if (newArray == NULL) {
      queue_free(q);
      return NULL; 
    }

    #ifdef QUEUE
     printf("Reallocate successful!\n");
    #endif
    
    int head = q->head; 
    int tail = q->tail; 
    int size = q->size;
    int i = 0; 
    // copies all items from original array to new array 
    do {
      newArray[i] = q->arr[head];

      #ifdef QUEUE
        printf("Copied item(%d)(%d) to ar[%d] \n", q->arr[head], head, i);
      #endif
      // run through array normally 
      if (head != size - 1) {
        head++;
      // go to beginning of array and copy those items 
      } else {
        head = 0;
      }

      i++;
    } while(head != tail);

    // set queue struct to new array 
    q->size *= 2; 
    q->head = 0; 
    q->tail = i + 1; 
    // free old array -> fix memory leak 
    free(q->arr);
    // set pointer to new array 
    q->arr = newArray; 

    // add item
    #ifdef QUEUE
      printf("Added item (%d) to array expansively at ar[%d]!\n", item, q->tail);
    #endif

    q->arr[q->tail] = item; 
    q->tail++; 
  } else {
    #ifdef QUEUE
      printf("I didn't enter anything \n");
    #endif
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
    #ifdef QUEUE
      printf("Array is empty, returning \n"); 
    #endif
    return 0;
  }

  // dequeued value 
  int value = q->arr[q->head];
  // if reach end, circle around 
  if (q->head == q->size -1) {
    #ifdef QUEUE
      printf("Head reached end: Dequeue array by going to start of array \n"); 
    #endif
    q->head = 0;
  // else dequeue normally 
  } else {
    #ifdef QUEUE
      printf("Dequeue array normally \n"); 
    #endif
    q->head++;
  }

  #ifdef QUEUE
    printf("Dequeue value: %d \n", value); 
  #endif
  return value;
}

// checks if the queue is empty
bool queue_is_empty(queue_t* q) {
  if (q == NULL) {
    return true;
  }

  // empty if BOTH head and tail are 0
  // fix this
  if (q->head == q->tail) {
    #ifdef QUEUE
      printf("Array IS EMPTY \n"); 
    #endif

    return true;
  } 

  #ifdef QUEUE
    printf("Array is NOT empty \n"); 
  #endif

  return false;
}

// returns the length of the queue
// if q==NULL, returns -1
int queue_length(queue_t* q) {
  // validate parameters
  if (q == NULL) {
    return -1;
  }
  int value = 0; 
  // if head is less than the tail, length is head - tail -1; 
  if (q->head < q->tail) {
    #ifdef QUEUE
      printf("Calc length: Tail (%d) is greater than head (%d) \n", q->tail, q->head);
    #endif
    value = q->tail - q->head; 
    // if head is equal to the tail, length is the size of the array
  } else if (q->head > q->tail) {
      #ifdef QUEUE
      printf("Calc length: Head (%d) is greater than tail (%d) \n", q->head, q->tail);
    #endif
    value = q->size - q->head + q->tail;
    // if head is greater than the tail-> length = ar->len - head + tail 
  } else if (q->head == 0 && q->tail == 0) {
    #ifdef QUEUE
      printf("Head tail both 0, therefore empty \n");
    #endif
    value = 0;
  } 

  #ifdef QUEUE
    printf("Length of array is %d \n", value);
  #endif

  return value;
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
