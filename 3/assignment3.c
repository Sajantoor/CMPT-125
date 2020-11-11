#include "assignment3.h"
#define QUICK

// swaps 2 elements
void swap(int* a, int* b) {
  int tmp = *a; 
  *a = *b; 
  *b = tmp;
 }

// everything to the left of the pivot is smaller than the pivot
// everything to the right is larger than the pivot
int rearrange(int* ar, int n, int pivot_index) {
  // validate parameters -> null, out of bounds
  if (ar == NULL || n < 0 || pivot_index < 0 || pivot_index > n) {
    #ifdef QUICK 
      printf("error returned \n");
    #endif
    return -1;
  } 

  // Requires 2 "pointers", one for left and one for right
  int left = 0; 
  int right = n; 
  int pivot = ar[pivot_index];

  // While right pointer is greater than or equal to left
  while (left <= right) {
    // find first element greater than the pivot and less than the pivot
    // skip pivot index as it's important to not move the pivot early 
    while ((ar[left] < pivot) || (left == pivot_index)) left++; 
    while ((ar[right] > pivot) || (right == pivot_index)) right--;

    // swaps first element greater than the pivot, with first element less than the pivot
    if (left <= right) {
      #ifdef QUICK 
        printf("Swap %d with %d \n", ar[left], ar[right]); 
        printf("Result: ");
        for (int i = 0; i < n; i++) {
          printf("%d ", ar[i]);
        }
        printf("\n");
      #endif

      swap(&ar[left], &ar[right]);
      left++; right--;
    }
  }
  // Once the left has the all the small elements and right has all the big elements, swap the pivot with the right pointer
  swap(&ar[pivot_index], &ar[right]);
  #ifdef QUICK
    printf("%d, %d \n", right, left);  
    printf("\n------------ Rearranged list --------- \n"); 
    for (int i = 0; i < n; i++) {
      printf("%d ", ar[i]);
    }
    printf("\n");

  #endif

  // return the new index of the pivot
  return right;
}

void quick_sort(int* ar, int n) {
  // implement me
}


// Merge subroutine:
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
