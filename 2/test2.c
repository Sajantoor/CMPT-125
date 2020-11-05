#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment2.h"

bool test_q1_1()  {
  if (foo(4) == 4)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

bool test_q1_2()  {
  if (foo(99) == -146)  {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}

bool test_q2_linear_1()  {
  person a[4];

  a[0].name = "John";
  a[0].id = 6;

  a[1].name = "Bob";
  a[1].id = 3;

  a[2].name = "Nick";
  a[2].id = 5;

  a[3].name = "Will";
  a[3].id = 1;


  if (linear_search_rec(a,4,3) == 1)  {
    printf("Q2-lin-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-lin-1 ERROR\n");
    return false;
  }
  return true;
}

bool test_q2_linear_2()  {
  person a[4];

  a[0].name = "John";
  a[0].id = 2;

  a[1].name = "Bob";
  a[1].id = 6;

  a[2].name = "Nick";
  a[2].id = 4;

  a[3].name = "Will";
  a[3].id = 1;

  if (linear_search_rec(a,4,20) == -1)  {
    printf("Q2-lin-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-lin-2 ERROR\n");
    return false;
  }
  return true;
}


bool test_q2_binary_1()  {
  person a[5];

  a[0].name = "Sam";
  a[0].id = 1;

  a[1].name = "John";
  a[1].id = 2;

  a[2].name = "Bob";
  a[2].id = 3;

  a[3].name = "Nick";
  a[3].id = 4;

  a[4].name = "Will";
  a[4].id = 5;


  if (binary_search_rec(a,5,3) == 2)  {
    printf("Q2-bin-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-bin-1 ERROR\n");
    return false;
  }
  return true;
}

bool test_q2_binary_2()  {
  person a[5];

  a[0].name = "Sam";
  a[0].id = 1;

  a[1].name = "John";
  a[1].id = 2;

  a[2].name = "Bob";
  a[2].id = 3;

  a[3].name = "Nick";
  a[3].id = 5;

  a[4].name = "Will";
  a[4].id = 6;


  if (binary_search_rec(a,5,4) == -1)  {
    printf("Q2-bin-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-bin-2 ERROR\n");
    return false;
  }
  return true;
}


bool test_q3()  {
  int a[6][6] =
  {
    {0,0,3,7,7,7},
    {8,0,4,7,0,0},
    {0,0,0,1,0,1},
    {0,2,0,1,0,0},
    {0,2,0,0,1,1},
    {0,0,0,2,2,2}
  };
  point start = {2, 2};

  flood_fill(6, a, start);

  int correct_ans[6][6] =
  {
    {1,1,3,7,7,7},
    {8,1,4,7,0,0},
    {1,1,1,1,0,1},
    {1,2,1,1,0,0},
    {1,2,1,1,1,1},
    {1,1,1,2,2,2}
  };

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      if (a[i][j] != correct_ans[i][j])
      {
        printf("Q3 ERROR in position (%d,%d)\n", i,j);
        return false;
      }

  printf("Q3 ok\n");
  return true;
}


void test_q4()  {
  person p1 = {"Jack", 1};
  person p2 = {"John", 2};

  int tmp;
  tmp = add_person("people.db", p1);
  if (tmp == 0)
    printf("Q4-1 ok\n");
  else
    printf("Q4-1 ERROR : tmp=%d, expected 0\n", tmp);

  tmp = add_person("people.db", p2);
  if (tmp == 0)
    printf("Q4-2 ok\n");
  else
    printf("Q4-2 ERROR : tmp=%d, expected 0\n", tmp);

  tmp = add_person("people.db", p2);
  if (tmp == 1)
    printf("Q4-3 ok\n");
  else
    printf("Q4-3 ERROR : tmp=%d, expected 1\n", tmp);

  person* p3 = find_person("people.db", 1);
  if (p3 && strcmp(p3->name, "Jack") == 0)
    printf("Q4-4 ok\n");
  else
    printf("Q4-4 ERROR, Jack with ID=1 not found\n");
  if (p3)
    free(p3);

  person* p4 = find_person("people.db", 4);
  if (p4 == NULL)
    printf("Q4-5 ok\n");
  else
    printf("Q4-5 ERROR, no person with ID=4 is expected\n");
  if (p4)
    free(p4);
}

int main()  {
  test_q1_1();
  test_q1_2();
  test_q2_linear_1();
  test_q2_linear_2();
  test_q2_binary_1();
  test_q2_binary_2();
  test_q3();
  test_q4();
  return 0;
}
