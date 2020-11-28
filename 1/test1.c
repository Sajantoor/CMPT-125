#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment1.h"

bool test_q1()  {
  int n1 = 1, n2=1;
  if (concat_ints(n1, n2)==11)  {
    printf("AC\n");
    return true;
  }
  else  {
    printf("WA\n");
    return false;
  }
}


int main()  {
  test_q1();
 
  return 0;
}
