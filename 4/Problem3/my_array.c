#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"

my_array* create_my_array(int length) {
  my_array* arr = malloc(sizeof(my_array));
  if (arr == NULL)
    return NULL;
  
  // BUG: If length is 0 will be NULL, need to test that edge case
  arr->arr = malloc(sizeof(int) * length);
  if (arr == NULL) {
    return NULL;
  }

  arr->len = length;
  return arr;
}
 
int my_ar_get_length(const my_array* ar) {
  return ar->len; 
}
 

int my_ar_set_value(my_array* ar, int index, int item)  {
  ar->arr[index] = item;
  return item;
}
 
 
int my_ar_get_value(const my_array* ar, int index) {
  return ar->arr[index];;
}
 
 
void my_ar_free(my_array* ar) {
  free(ar->arr);
  ar->arr = NULL; 
  free(ar);
  ar = NULL; 
}
 
/*** Part 2 [20 points] ***/

int my_ar_resize(my_array* ar, int new_size) {
  ar->arr = realloc(ar->arr, sizeof(int) * new_size);
  if (ar->arr == NULL) 
    return -1; 
  
  ar->len = new_size; 
  return new_size;
}
 
my_array* my_ar_copy(const my_array* src) {
  my_array* copy = create_my_array(src->len);
  if (copy == NULL)
    return NULL; 
  
  for (int i = 0; i < src->len; i++) {
    copy->arr[i] = src->arr[i];
  }

  return copy;
}

my_array* my_ar_append(my_array* dest, const my_array* src) {
  if (src->len == 0) {
    return dest;
  }

  int len = src->len + dest->len;
  dest->arr = realloc(dest->arr, sizeof(int) * len);
  if (dest->arr == NULL) 
    return NULL; 

  for (int i = 0; i < src->len; i++) {
    dest->arr[i + dest->len] = src->arr[i];
  }

  dest->len = len;

  return dest;
}

/*** Part 3 [30 points] ***/

int my_ar_find(const my_array* ar, int element) {
  for (int i = 0; i < ar->len; i++) {
    if (ar->arr[i] == element) {
      return i;
    }
  }

  return -1;
}
 
void my_ar_map(my_array* ar, int (*f)(int)) {
}

int my_ar_reduce(const my_array* ar, int (*f)(int,int)) {
    return -1;
}
 
my_array* my_ar_filter(my_array* src, bool (*f)(int)) {
  return NULL;
}
