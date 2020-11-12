#include "assignment3.h"

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
    return -1;
  } 
  // if array is 1 the pivot will be located at the index 0, return the array, it's sorted.
  if (n == 1) {
    return 0;
  }

  // Requires 2 "pointers", one for left and one for right
  int left = 1; 
  int right = n - 1;
  int pivot = ar[pivot_index]; 
  // set pivot to be the first element in the array
  swap(&ar[0], &ar[pivot_index]);

  // While right pointer is greater than or equal to left
  while (left <= right) {
    // find first element greater than the pivot and less than the pivot
    while (ar[left] < pivot) left++; 
    while (ar[right] > pivot) right--;

    // swaps first element greater than the pivot, with first element less than the pivot
    if (left < right) {
      swap(&ar[left], &ar[right]);
      left++; right--;
    }

    if (right <= left) {
      break;
    }
  }

  // Once the left has the all the small elements and right has all the big elements, swap the pivot with the right pointer
  swap(&ar[0], &ar[right]);
  // return the new index of the pivot
  return right;
}

// get median function
int getMedian(int* ar) {
  int a = ar[0];
  int b = ar[1];
  int c = ar[2];

  if (a > b) { 
    if (b > c) 
        return b; 
    else if (a > c) 
        return c; 
    else
        return a; 
  } else { 
    // Decided a is not greater than b. 
    if (a > c) 
        return a; 
    else if (b > c) 
        return c; 
    else
        return b; 
  } 
}


void quick_sort(int* ar, int n) {
  // validate params, array less than equal to 1 is already sorted or invalid so just return
  if (ar == NULL || n <= 1) {
    return;
  }

  // store 3 random numbers 
  int randomAr[3]; 

  // pick a random number between 0 - n 
  for (int i = 0; i < 3; i++) {
    randomAr[i] = rand() % n;
  }
  
  // get median of those random 3 numbers
  int median = getMedian(randomAr);

  // recursive step: 
  int pivotIndex = rearrange(ar, n, median);
  // if error in rearrange, stop
  if (pivotIndex == -1) {
    return;
  }

  quick_sort(ar + pivotIndex + 1, n - pivotIndex - 1); // sort the right half wrt pivot
  quick_sort(ar, pivotIndex); // sort left half wrt pivot
}


// Merge subroutine:
// assumption [0 - (mid-1)] is sorted
// assumption [mid - (n-1)] is sorted 
// merge both
void merge(int* ar, int n, int mid) {
  // validate parameters, merge of n = 1 is just the array
  if (ar == NULL || n <= 1 || mid <= 0 || n < mid) {
    return; 
  }

  // create 2 subarrays to store [0 - (mid -1)]: size mid & [mid - (n-1)]: (n) - mid
  int leftSize = mid; 
  int leftHalf[leftSize]; 
  int rightSize = n - mid;
  int rightHalf[rightSize];

  // copy data to subarray
  for (int i = 0; i < leftSize; i++) {
    leftHalf[i] = ar[i];
  }

  for (int i = 0; i < rightSize; i++) {
    rightHalf[i] = ar[i + mid];
  }

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
}

void merge_sort(int* ar, int n) {
  // validate params 
  if (ar == NULL || n <= 1) {
    return;
  }
  
  // BASE CASE:
  // arrays less than zero are invalid 
  // arrays of 0 or 1 ore already sorted 
  
  // RECURSIVE STEP: 
  int mid = n / 2; 
  merge_sort(ar + mid, n - mid); // right half of the array
  merge_sort(ar, mid); // left half of the array
  merge(ar, n, mid);
}
