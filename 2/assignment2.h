#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

typedef struct  {
  int x;
  int y;
} point;

typedef struct  {
  char* name;
  int id;
} person;

// computes the foo function
long foo(int n);


// The function gets an (unsorted) array of length n
// with elements of type person, and an ID.
// The output of the function is the index of the item in the array
// that contains the person with the given ID.
// If A does not contain the item, the function returns -1
int linear_search_rec(person* A, int n, int id);


// The function gets a sorted array of length n
// with elements of type person, and an ID.
// The output of the function is the index of the item in the array
// that contains the person with the given ID.
// If A does not contain the item, the function returns -1
int binary_search_rec(person* A, int n, int id);


// implements the flood fill algorithm
void flood_fill(int N, int ar[N][N], point start);


// The function gets a name of a file and
// searches the file for a person with the given ID.
// It returns a pointer to the created struct person with the name and ID.
person* find_person(const char* file_name, int ID);


// The function gets a name of a file, and a person p.
// If the person is not in the file, the function adds p to the file.
int add_person(const char* file_name, person p);

#endif
