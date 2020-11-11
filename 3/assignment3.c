#include "assignment3.h"

int rearrange(int* ar, int n, int pivot_index) {
  // implement me
  return -1;
}

void quick_sort(int* ar, int n) {
  // implement me
}


// assumption [0 - (mid-1)] is sorted
// assumption [mid - (n-1)] is sorted 
// merge both
void merge(int* ar, int n, int mid) {
  // validate parameters
  if (ar == NULL || n <= 0 || mid <= 0) {
    return; 
  }

  // validate params more!
  if (mid > n) {
    return; 
  }

  // create 2 subarrays to store [0 - (mid -1)]: size mid & [mid - (n-1)]: (n) - mid
  int leftSize = mid; 
  int leftHalf[leftSize]; 
  int rightSize = n - mid;
  int rightHalf[rightSize];

  // copy data to subarray
  #ifdef TEST 
     printf("storing left half: ---------- \n");
  #endif
  
  for (int i = 0; i < leftSize; i++) {
    leftHalf[i] = ar[i];

    #ifdef TEST 
      printf("%d ", ar[i]);
    #endif
  }

  #ifdef TEST
     printf("\n----------------------\n");
    printf("\nstoring right half: \n");
  #endif

  for (int i = 0; i < rightSize; i++) {
    rightHalf[i] = ar[i + mid];

    #ifdef TEST
      printf("%d ", ar[i+mid]);
    #endif
  }

  #ifdef TEST
    printf("\n ------------- \n");
  #endif


  // compare data and sort
  int a = 0; // array incrementer
  int i = 0; // left half incrementer
  int j = 0; // right half incrementer

  while (i < leftSize && j < rightSize) {
    // if left is smaller or equal -> put left in array 
    if (leftHalf[i] <= rightHalf[j]) {
      ar[a] = leftHalf[i];
      i++;
    } else { // right half was bigger -> put right in the array
      ar[a] = rightHalf[j]; 
      j++;
    }

    a++;
  }

  // for remaining elements -> one half is done at this point 
  while (i < leftSize) {
    ar[a] = leftHalf[i];
    a++;
    i++; 
  }

  while (j < rightSize) {
    ar[a] = rightHalf[j]; 
    a++;
    j++;
  }

  #ifdef TEST
    printf("\n -------- Resulting merge------ \n");
    for (int i = 0; i < n; i++) {
      printf("%d ", ar[i]);
    }
     printf("\n ------------------ \n");
  #endif 
}

void merge_sort(int* ar, int n) {
  // validate params 
  if (ar == NULL) {
    return;
  }
  
  // BASE CASE:
  // arrays less than zero are invalid 
  // arrays of 0 or 1 ore already sorted
  if (n <= 1) {
    #ifdef MERGE_SORT
      printf("sorted: %d \n", ar[0]);
    #endif
    return; 
  }
  
  // RECURSIVE STEP: 
  int mid = n / 2; 
  // Number of elements is 
  merge_sort(ar + mid, n - mid); // right half of the array
  merge_sort(ar, mid); // left half of the array
  merge(ar, n, mid);
  #ifdef MERGE_SORT 
    // printf("----------- Final sorted array ---------- \n");
    for (int i = 0; i < n; i++) {
      printf("%d ", ar[i]);
    }

    printf("\n ------------------- \n");
  #endif
}
