#include <stdlib.h>

#include "my_array.h"

my_array* create_my_array(int length) {
  // creates a new my array struct
  my_array* arr = malloc(sizeof(my_array));
  if (arr == NULL)
    return NULL;
  
  // creates a new array of length
  arr->arr = malloc(sizeof(int) * length);
  // if OS cannot allocate memory return NULL and free
  if (arr->arr == NULL && length != 0) {
    free(arr);
    return NULL;
  }

  arr->len = length;
  return arr;
}
 
int my_ar_get_length(const my_array* ar) {
  return ar->len; 
}
 

int my_ar_set_value(my_array* ar, int index, int item) {
  ar->arr[index] = item;
  return item;
}
 
 
int my_ar_get_value(const my_array* ar, int index) {
  return ar->arr[index];
}
 
 
void my_ar_free(my_array* ar) {
  free(ar->arr);
  ar->arr = NULL; 
  free(ar);
  ar = NULL; 
}
 
/*** Part 2 [20 points] ***/

int my_ar_resize(my_array* ar, int new_size) {
  // realloc more space
  ar->arr = realloc(ar->arr, sizeof(int) * new_size);
  // if realloc fails 
  if (ar->arr == NULL) 
    return -1; 
  
  ar->len = new_size; 
  return new_size;
}

my_array* my_ar_copy(const my_array* src) {
  // creates a copy of the same length
  my_array* copy = create_my_array(src->len);
  // if copy fails
  if (copy == NULL)
    return NULL; 
  
  // copy all the values over
  for (int i = 0; i < src->len; i++) {
    copy->arr[i] = src->arr[i];
  }

  return copy;
}

my_array* my_ar_append(my_array* dest, const my_array* src) {
  // if the length is 0 then, it's just the dest array
  if (my_ar_get_length(src) == 0) {
    return dest;
  }

  // get new length for destination and resize
  int orignalLen = my_ar_get_length(dest); // length gets updated in reize function
  int len = my_ar_get_length(src) + orignalLen;
  int res = my_ar_resize(dest, len);
  if (res == -1) {
    return NULL;
  }

  // copy all items over starting from the end of the array of dest to the end of the array
  for (int i = 0; i < src->len; i++) {
    dest->arr[i + orignalLen] = src->arr[i];
  }

  dest->len = len;
  return dest;
}

/*** Part 3 [30 points] ***/

int my_ar_find(const my_array* ar, int element) {
  // linear search
  for (int i = 0; i < ar->len; i++) {
    if (ar->arr[i] == element) {
      return i;
    }
  }

  return -1;
}
 
void my_ar_map(my_array* ar, int (*f)(int)) {
  // go through all elements and update
  for (int i = 0; i < ar->len; i++) {
    ar->arr[i] = f(ar->arr[i]);
  }
}

int my_ar_reduce(const my_array* ar, int (*f)(int,int)) {
  // init accumlator as array 0
  int accumulator = ar->arr[0];
  // go through remaining elements and accumalate  
  for (int i = 1; i < ar->len; i++) {
    accumulator = f(accumulator, ar->arr[i]);
  }
  
  return accumulator;
}
 
my_array* my_ar_filter(my_array* src, bool (*f)(int)) {
  // create duplicate array of original length
  my_array* duplicate = create_my_array(src->len);
  if (duplicate == NULL) 
    return NULL; 
  
  int j = 0; // counts length of filter "pass" elements
  // goes through all elements and see if the filter func is true before adding to array
  for (int i = 0; i < src->len; i++) { 
   bool flag = f(src->arr[i]);
 
    if (flag) {
      duplicate->arr[j] = src->arr[i];
      j++;
    }
  }
  // sets length and cuts the size of filtered array to appropriate size
  duplicate->len = j;
  duplicate->arr = realloc(duplicate->arr, duplicate->len * sizeof(int));
  // if realloc fails 
  if (duplicate->arr == NULL) {
    free(duplicate);
    return NULL;
  }

  return duplicate;
}
