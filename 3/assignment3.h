#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// used for QuickSort:
// the function rearranges the elements, and
// returns the index of the pivot after the rearrangement
int rearrange(int* ar, int n, int pivot_index);

// QuickSort algorithm
void quick_sort(int* ar, int n);


// used for MergeSort:
// the function gets an array of length n
// and the index of the midpoint.
// the assumption is that ar[0...mid-1] is sorted
// and ar[mid...n-1] is sorted
// the function merges the two halves into assorted array
void merge(int* ar, int n, int mid);

// MergeSort algorithm
void merge_sort(int* ar, int n);


#endif
