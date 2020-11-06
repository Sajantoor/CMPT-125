#include "assignment3.h"

int rearrange(int* ar, int n, int pivot_index) {
  // implement me
  return -1;
}

void quick_sort(int* ar, int n) {
  // implement me
}


void merge(int* ar, int n, int mid) {
  
}

void merge_sort(int* ar, int n) {
  if (n > 1) {
    int m = n / 2; 
    merge_sort(ar, m); // sort the first half 

    // seg fault check
    if ((ar + m + 1) >= n) {
      return;
    }

    merge_sort(ar + m + 1, n); // sort the second half 

    merge(ar, n, m); // merge halfs
  } 
}
