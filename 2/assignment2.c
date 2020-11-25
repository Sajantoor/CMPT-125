#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment2.h"

/* 
  ====================
  Question 1 Function
  ====================
*/

// O(n) run time solution
long foo(int n) {
  // n less than / equal to 2 is always n 
  if (n <= 2)
    return n;

  long ar[n]; // array to store previously computed values
  ar[0] = 0; // initialize all known elements n <= 2
  ar[1] = 1; 
  ar[2] = 2;

  for (int i = 3; i <= n; i++) { 
    // as each number > n must be computed for this problem, compute each number starting from n = 3
    // this allows to quickly compute larger numbers from the values computed previously
    // foo(n) = f(n-3) + f(n-2) - f(n-1) - 1
    ar[i] = ar[i - 3] + ar[i - 2] - ar[i - 1] - 1; 
  } 

  return ar[n];
}

/* 
  ====================
  Question 2 Functions
  ====================
*/

// returns index of item if found or -1 if not found
int linear_search_rec(person* A, int n, int id) {
  // if length (n) is reached return -1 
  // return the index if (A + length - 1)->id == id 
  // else recurse and search again with the last element removed (n - 1)
  if (n == -1) {
    return -1;
  } else if ((A + (n - 1))->id == id) {
    return n - 1;
  } else {
    return linear_search_rec(A, n - 1, id);
  }
}

// returns index of item if found or -1 if not found -> Sorted
int binary_search_rec(person* A, int n, int id)  {
  // fix seg fault 
  if (A == NULL) {
    return -1;
  }

  static int i = 0; // keeps track starting position
  int half = i + (n - i) / 2; // half of the array 

  if (i <= n) { // id is in the array
    if ((A + half)->id == id) { // is exactly half -> return half 
      return half;
    } else if ((A + half)->id < id) { // id is greater - > search n to n / 2 + 1 
      i = half + 1;
      return binary_search_rec(A, n, id);
    } else { // if ((A + half)->id > id) ->  id is less -> search 0 to n / 2 - 1
      i = 0;
      return binary_search_rec(A, half - 1, id);
    }
  }
  // id is not in the array
  return -1;
}

/* 
  ===================
  Question 3 Function 
  ===================
*/

void flood_fill(int N, int ar[N][N], point start) {
  const int color = 0; // color is always white (0) to 1;
  // recursive loop
   if (start.x < 0 || start.y < 0 || start.x >= N || start.y >= N || ar[start.x][start.y] != color) {
    return;
  } 

  // sets current to color 
  ar[start.x][start.y] = 1; 

  // Recursively fills in all 4 directions
  // Left
  start.x -= 1;
  flood_fill(N, ar, start);
  // Right
  start.x += 2;
  flood_fill(N, ar, start);
  
  // Down 
  start.x -= 1;
  start.y -= 1;
  flood_fill(N, ar, start);

  // Up
  start.y += 2;
  flood_fill(N, ar, start);
}

/* 
  ================================
  Question 4 Functions and Helpers
  ================================
*/

// returns the number of string len from digits
int getStringLen(int value) {
  int i = 0;

  while(value > 9) {
    i++; 
    value /= 10; 
  }

  return i + 1;
}

// Proccesses the full line of text and returns malloc string of the name
char* processText(char * string, int id, int nameLen) {
  // get # of chars to store the digit
  int idLen = getStringLen(id);
  int nameDigitLen = getStringLen(nameLen);
  // create new malloc string with name length
  char * nameString = malloc(sizeof(char) * (nameLen));
  // i starts before word, accounting for the space in line by the id and name digit and the 2 spaces 
  int i = idLen + nameDigitLen + 2;
  // j must be less than the name length
  for (int j = 0; j < nameLen; i++, j++) {
    nameString[j] = string[i];
  }
  
  // because I didn't memset because this is easier and faster
  nameString[nameLen] = '\0';
  return nameString;
}

// Finds a person from the database, returns person if found or NULL if not found. 
person* find_person(const char* file_name, int ID) {
  // Learned how to get file line by line from here https://www.youtube.com/watch?v=TKKQERrrt5o
  // open the file in reading mode
  FILE *file = fopen(file_name, "r");

  if (file != NULL) { // opened successfully
    char buffer[100];  // buffer for fget 100 characters
    unsigned int len = sizeof(buffer);
    // dynamically allocated string used to store whole line if doesn't fit in buffer array
    char * string = malloc(len);
    string[0] = '\0';
    
    int personID; // get person's id 
    int nameLen; // get person's name len

    while(fgets(buffer, sizeof(buffer), file) != NULL) {
      // Resize the string to fit the full line 
      // End of line is needed as the name is located on the same line and name is arbitrary length
      if (len - strlen(string) < sizeof(buffer)) {
        len *=2;
        if ((string = realloc(string, len)) == NULL) {
          printf("Could not reallocate memory for string.");
          free(string);
          fclose(file);
          return NULL;
        }
      }
      // append buffer to the end of line array
      strcat(string, buffer);

      // if end of line is reached => check if person exists in file
      if (string[strlen(string) - 1] == '\n') {
        sscanf(string, "%d %d", &personID, &nameLen); // read formatted string

        // person's ID in file matches ID -> return data on the person
        if (personID == ID) {
          person* personData = malloc(sizeof(person)); // must be on heap
          personData->id = personID;
          personData->name = processText(string, personID, nameLen);
          free(string); // free string as we no longer need it 
          return personData; 
        }

        memset(string, 0, len); // clear string for next use
        len = sizeof(buffer);  // reset len for next use
      }
    }

    fclose(file);
    return NULL;
  } else { // error opening file -> return null
    fclose(file);
    printf("Error opening file. \n");
    return NULL;
  }
}

int add_person(const char* file_name, person p) {
  // open file
  FILE *file = fopen(file_name, "a"); // file opened in appending mode, adding something to end of file
  if (file == NULL) { // error opening file
    fclose(file);
    return -1;
  }
  // look for person in file 
  person* personPointer = find_person(file_name, p.id);

  if (personPointer != NULL) { // person exists, this function returns null if it doesn't
    fclose(file);
    return 1;
  } else { // person does not exist, add person 
    int len = strlen(p.name);
    fprintf(file, "%d %d %s \n", p.id, len, p.name);
    fclose(file);
    return 0;
  }
}
