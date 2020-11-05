#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

int concat_ints(int n1, int n2) {
  // multiple n1 * 10 by the number of digits n2 is 
  // 1, 25 => 1 * 100 + 25 => 100 + 25 => 125 

  int power = 10; // used to multiple n1 by 10

  while (n2 >= power) { // power must be equal or smaller than n2 to get digits of n2
        power *= 10;
  }
  
  return (n1 * power) + n2;  
}

void upper2lowercase(char* c) {
  // char less or equal to 90 are uppercase
  // char greater or equal to 65 are letters
  if (c[0] >= 65 && c[0] <= 90) { // convert to lowercase => add 32 to string
    c[0] += 32;
  }
}

// shifts the array by one to the left 
void left_shift(char* str, int len) {
  char temp = str[0]; // temp so data is not overwritten

  // shift by one to the left
  for (int i = 0; i < len - 1; i++) {
    str[i] = str[i + 1];
  } 
  
  // add the temp to the left of the array
  str[len - 1] = temp;
}

void left_rotate(char* str, unsigned int n) {
  // if index is greater than the length of string or zero => do nothing
  // if index is within string get the n point and swap then do the rest 

  int stringLength = strlen(str);
  if (n > stringLength || n == 0) {
    return; 
  }

  // shifts left by 1 until n is reached => then it's left rotated 
  for (int i = 0; i < n; i++) {
      left_shift(str, stringLength); 
  }
}


bool contains_equal_columns(int height, int width, const int array[height][width]) {
  // loop through the arrays looking at the columns
  // code compares the 2D array columns by breaking it up into a 1D array and looking through that

  for (int i = 0; i < width; i++) {
    // this compares the columns of i to all other columns to the array
    for (int c = i + 1; c < width; c++) {
      // loops through height of all the arrays
      for (int j = 0; j < height; j++) {
        // if elements don't match, break out of this index and move on to the next
        if (array[j][i] != array[j][c]) {
          break;
        } else if (j == height - 1) { // reached end of 1D array, the two columns must be equal
          return true;
        }
      }
    }
 
  } 
  // implement me
  return false;
}

// string length function to get length of string
int str_len(const char* str) {
    int i = 0;
    // string ends with '\0' character
    while (str[i] != '\0') {
        i++;
    }

    return i;
}


char* str_compute_sum(const char* num1, const char* num2) {
  // num where digits start in the asci table 
  const int NUM_ASCII_TABLE = 48;
  int carry = 0; // the program must know when to carry when adding 
  int num1Len = str_len(num1) - 1;
  int num2Len = str_len(num2) - 1; 
  int stringLen = num1Len;

  // max string length used to create array and looping
  if (num2Len > stringLen) {
    stringLen = num2Len;
  }

  char *string = (char*)malloc(sizeof(char) * (stringLen + 2)); // create string on heap
  

  // loops through the string
  for (int i = 0; i < stringLen + 2; i++) {
    // creates sum by converting char to int using ASCII table and looks if the array has ended or not 
    int sum = 0;
    if (i > num1Len && i > num2Len) 
      sum = 0;
    else if (i > num1Len)
      sum = num2[num2Len - i] - NUM_ASCII_TABLE;
    else if (i > num2Len)
      sum = num1[num1Len - i] - NUM_ASCII_TABLE;
    else {
      sum = (num1[num1Len - i] - NUM_ASCII_TABLE) + (num2[num2Len - i] - NUM_ASCII_TABLE);
    }

    // add carry
    sum += carry; 
    carry = 0;

    // needs to carry
    if (sum > 9) {
      carry = 1;
      sum -= 10; 
    }

    // the stringlen should be shorter if the last character is 0
    if (i == (stringLen + 1) && sum == 0) {
      stringLen--;
    } else {
      // convert to char
      string[i] = sum + NUM_ASCII_TABLE;
    }
  }

   // flip the string to the correct way now
  int i, j; 
  for (i = 0, j = stringLen + 1; i < j; i++, j--) {
    char tmp = string[i];
    string[i] = string[j];
    string[j] = tmp; 
  }

  // hack to fix the '/n' at the end that might get overwritten somewhere, causing errors
  string[stringLen + 2] = 0;
  return string;
}
