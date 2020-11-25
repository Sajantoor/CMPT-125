#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <stdio.h>
#include <stdbool.h>

// gets two numbers between 1 and 999
// returns the concatenation of the two strings
int concat_ints(int n1, int n2);


// get a pointer to char c
// if *c is an uppercase letter, changes it to the corresponding lowercase letter
// otherwise, does nothing
void upper2lowercase(char* c);


// rotates str to the left by n symbols
void left_rotate(char* str, unsigned int n);


// gets a 2-d array of numbers
// returns true if the matrix contains two equal columns
bool contains_equal_columns(int height, int width, const int array[height][width]);


// gets two strings that contain positive integers
// returns a string containing the sum of the two numbers
char* str_compute_sum(const char* num1, const char* num2);


#endif