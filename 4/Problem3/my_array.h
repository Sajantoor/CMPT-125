#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The struct represents an array with indices 0..length-1
// The length of the array can be set in create_my_array().
// The length can be obtained using my_ar_get_length.
// The length can be modified using my_ar_resize.
typedef struct {
  // implement me
} my_array;
 
// Creates a new my_array of the given length.
// The entries of the array are not initialized.
// If memory allocation fails, returns NULL.
// Assumption: length>0.
my_array* create_my_array(int length);
 
 
// Returns the length of the array.
// Assumption: ar has been created correctly.
int my_ar_get_length(const my_array* ar);
 

// Sets the value in the array at the specified index.
// Returns the item that was added.
// Assumption: ar has been created correctly and 0<=index<=length.
int my_ar_set_value(my_array* ar, int index, int item);
 
 
// Returns the value from the array at the specified index.
// Assumption: ar has been created correctly and 0<=index<=length.
int my_ar_get_value(const my_array* ar, int index);
 
 
// Frees the array
// Assumption: ar has been created correctly
void my_ar_free(my_array* ar);
 
 
 
/*** Part 2 [20 points] ***/

// Changes the size of the array.
// If new_size is greater than the original length
// it copies the original content into the new array
// and leaves the remaining entries uninitialized.
// If new_size is smaller than the original length
// it copies the first new_size elements into the new array.
// Returns new_size if all is ok. If memory allocation fails returns -1
// Assumption: ar has been created correctly
int my_ar_resize(my_array* ar, int new_size);
 
// Creates a copy of the given my_array and returns it.
// Returns NULL if memory allocation fails.
// Assumption: src has been created correctly.
my_array* my_ar_copy(const my_array* src);
 
// Appends src to the end of dest.
// Returns the pointer to the resulting dest.
// Returns NULL if memory allocation fails.
// Assumption: dest, src have been created correctly.
my_array* my_ar_append(my_array* dest, const my_array* src);
 
 
/*** Part 3 [30 points] ***/

// Returns the first index of the array containing the element.
// If element not found, returns -1.
// Assumption: ar has been created correctly.
int my_ar_find(const my_array* ar, int element);
 
// For each index i=0..length-1 applies the function f to ar[i]
// and stores f(ar[i]) in ar[i].
// Assumption: ar has been created correctly.
void my_ar_map(my_array* ar, int (*f)(int));
 
// Start with accumulator = ar[0]
// For i=1...length-1 compute accumulator=f(accumulator, ar[i])
// Return accumulator.
// For example, if f computes the sum of two input,
// then reduce will compute the sum of the entire array.
// Assumption: ar has been created correctly.
int my_ar_reduce(const my_array* ar, int (*f)(int,int));
 
// Returns a new my_array containing only the elements of src
// satisfying f(element)==true.
// The length of the new array is adjusted accordingly.
// The order of the elements in the resulting array might change!
// Assumption: src has been created correctly.
my_array* my_ar_filter(my_array* src, bool (*f)(int));

#endif
