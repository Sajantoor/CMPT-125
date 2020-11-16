#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"

my_array* create_my_array(int length) {
  return NULL;
}
 
int my_ar_get_length(const my_array* ar) {
  return 0;
}
 

int my_ar_set_value(my_array* ar, int index, int item)  {
  return 0;
}
 
 
int my_ar_get_value(const my_array* ar, int index) {
  return 0;
}
 
 
void my_ar_free(my_array* ar) {

}
 
 
 
/*** Part 2 [20 points] ***/

int my_ar_resize(my_array* ar, int new_size) {
  return 0;
}
 
my_array* my_ar_copy(const my_array* src) {
  return NULL;
}

my_array* my_ar_append(my_array* dest, const my_array* src) {
  return NULL;
}

/*** Part 3 [30 points] ***/

int my_ar_find(const my_array* ar, int element) {
  return 0;
}
 
void my_ar_map(my_array* ar, int (*f)(int)) {
}

int my_ar_reduce(const my_array* ar, int (*f)(int,int)) {
    return -1;
}
 
my_array* my_ar_filter(my_array* src, bool (*f)(int)) {
  return NULL;
}
