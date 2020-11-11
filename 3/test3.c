#include <stdio.h>

#include "assignment3.h"
#include "stack.h"
#include "queue.h"

// provided test
bool test_q1_1()  {
  int a[] = {4,1,2,7,5,3,2};
  rearrange(a,7,0);
  bool okFlag = true;

  int correct_ans[] = {3,1,2,2,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

// biggest element is the pivot
bool test_q1_1_1()  {
  int a[] = {2, 3, 6, -1, 3, 2, 1};
  rearrange(a,7,2);
  bool okFlag = true;

  int correct_ans[] = {1, 3, 2, -1, 3, 2, 6};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1-1 ERROR\n");
    return false;
  }
}


// another test
bool test_q1_1_2()  {
  int a[] = {4,1,2,7,5,3,2};
  rearrange(a,7,0);
  bool okFlag = true;

  int correct_ans[] = {3,1,2,2,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-1-2 ERROR\n");
    return false;
  }
}

// pivot is smallest element
bool test_q1_1_3()  {
  int a[] = {9, 6, 4, 1, 2, 9, 0, 1};
  rearrange(a,7,6);
  bool okFlag = true;

  int correct_ans[] = {0, 6, 4, 1, 2, 9, 9, 1};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1-3 ok\n");
    return true;
  }
  else  {
    printf("Q1-1-3 ERROR\n");
    return false;
  }
}

// test with 2 elements and largest is the pivot
bool test_q1_1_4()  {
  int a[] = {2, 1};
  rearrange(a,2,0);
  bool okFlag = true;

  int correct_ans[] = {1, 2};
  for (int i=0;i<2;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1-4 ok\n");
    return true;
  }
  else  {
    printf("Q1-1-4 ERROR\n");
    return false;
  }
}


bool test_q1_2()  {
  int a[] = {4,1,2,7,5,3,2};
  quick_sort(a,7);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}

bool test_q1_2_1()  {
  int a[] = {-1,51,12,21,122,-21,2};
  quick_sort(a,7);
  bool okFlag = true;

  int correct_ans[] = {-21,-1,2,12,21,51,122};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-2-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2-2 ERROR\n");
    return false;
  }
}

bool test_q2_1()  {
  int a[] = {2,4,7,1,2,3,5};
  merge(a,7,3);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}

bool test_q2_2()  {
  int a[] = {4,1,2,7,5,3,2};
  merge_sort(a,7);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}

bool test_q3_1()  {
  stack3_t* s = stack_create();
  stack_push(s,1);
  stack_push(s,2);
  stack_push(s,2);
  stack_push(s,3);
  int len1 = stack_length(s);
  stack_pop(s);
  stack_push(s,4);
  stack_push(s,5);
  stack_pop(s);
  stack_push(s,0);
  int len2 = stack_length(s);

  if (len1 == 4 && len2 == 5)  {
    if (stack_pop(s) != 0) {
      printf("Not the same stack!!!!! \n");
    }
    printf("Q3-1 ok\n");
    return true;
  }
  else  {
    printf("Q3-1 ERROR\n");
    return false;
  }
}

bool test_q3_2()  {
  stack3_t* s1 = stack_create();
  stack_push(s1,1);
  stack_push(s1,2);
  stack_push(s1,2);
  stack_push(s1,3);
  stack_pop(s1);
  stack_push(s1,4);
  stack_push(s1,5);
  stack_pop(s1);
  stack_push(s1,0);

  stack3_t* s2 = stack_create();
  stack_push(s2,10);
  stack_push(s2,11);
  stack_push(s2,1);
  stack_pop(s2);
  stack_push(s2,12);

  if (stack_strictly_less(s1, s2))  {
    if (stack_pop(s2) != 12 || stack_pop(s1) != 0) {
      printf("Not the same stack!!!!! \n");
    }

    printf("Q3-2 ok\n");
    return true;
  }
  else  {
    printf("Q3-2 ERROR\n");
    return false;
  }
}

bool test_q4()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  int one = dequeue(q1);
  enqueue(q1,3);
  enqueue(q1,4);
  int two = dequeue(q1);
  bool not_empty = queue_is_empty(q1);
  dequeue(q1);
  dequeue(q1);
  bool is_empty = queue_is_empty(q1);


  if (one==1 && two==2 && not_empty==false && is_empty)  {
    printf("Q4 ok\n");
    return true;
  } else {
    printf("Q4 ERROR\n");
    return false;
  }
}

// tests length
bool test_q4_L_1()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);
  enqueue(q1,5);


  int length = queue_length(q1);

  if (length == 5)  {
    printf("Q4-L-1 ok\n");
    return true;
  } else {
    printf("Q4-L-1 ERROR\n");
    return false;
  }
}
// another length test
bool test_q4_L_2()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);
  dequeue(q1);

  int length = queue_length(q1);

  if (length == 3)  {
    printf("Q4-L-2 ok\n");
    return true;
  } else {
    printf("Q4-L-2 ERROR\n");
    return false;
  }
}

// another length test
bool test_q4_L_3()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);
  dequeue(q1);
  dequeue(q1);
  dequeue(q1);
  dequeue(q1);

  int length = queue_length(q1);

  if (length == 0)  {
    printf("Q4-L-3 ok\n");
    return true;
  } else {
    printf("Q4-L-3 ERROR\n");
    return false;
  }
}

// realloc test case 
bool test_q4_L_4()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);
  enqueue(q1,5);
  enqueue(q1,6);
  dequeue(q1);

  int length = queue_length(q1);
  bool val = queue_is_empty(q1);

  if (length == 5 && !val)  {
    printf("Q4-L-4 ok\n");
    return true;
  } else {
    printf("Q4-L-4 ERROR\n");
    return false;
  }
}

// looping array test case
bool test_q4_L_5()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  dequeue(q1);
  enqueue(q1,2);
  dequeue(q1);
  enqueue(q1,3);
  dequeue(q1);
  enqueue(q1,4);
  dequeue(q1);
  enqueue(q1,5);
  dequeue(q1);
  enqueue(q1,6);
  dequeue(q1);
  bool val = queue_is_empty(q1);

  int length = queue_length(q1);

  if (length == 0 && val)  {
    printf("Q4-L-5 ok\n");
    return true;
  } else {
    printf("Q4-L-5 ERROR\n");
    return false;
  }
}

// tests null segfault 
bool test_q4_2()  {
  queue_t* q2 = NULL;
  enqueue(q2,1);
  dequeue(q2);
  int length = queue_length(q2);
  bool isEmpty = queue_is_empty(q2);

  if (length == -1 && isEmpty)  {
    printf("Q4-2 ok\n");
    return true;
  } else {
    printf("Q4-2 ERROR\n");
    return false;
  }
}

bool test_q1_EDGE()  {
  int a[] = {2, 1};
  int one = rearrange(a,-1,0); 

  int b[] = {0, 1, 2, 3}; 
  int two = rearrange(b, 4, 5); 
  int three = rearrange(b, 4, -1);
  int four = rearrange(NULL, 5, 2); 
  
  if (one == -1 && two == - 1 && three == -1 && four == -1)  {
    printf("Q1-1_EDGE_1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1_EDGE_1 ERROR\n");
    return false;
  }
}

bool test_q1_2_EDGE_1()  {
  int a[] = {4,1,2,7,5,3,2};
  quick_sort(a,-1);

  bool okFlag;
  int correct_ans[] = {4,1,2,7,5,3,2};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-2_EDGE_1 ok\n");
    return true;
  }
  else  {
    printf("Q1-2_EDGE_1 ERROR\n");
    return false;
  }
}

bool test_q1_2_EDGE_2()  {
  quick_sort(NULL,-1);
  printf("Q1_2 EDGE_2: Didn't seg fault: pass \n");
  return true;
}

bool test_q2_1_EDGE() {
  merge(NULL, -1, 0);
  int a[] = {4,1,2,7,5,3,2};
  merge(a, 7, 5);
  merge(a, -5, 5);
  merge(a, 1, 5);
  printf("Q2_1_EDGE: didn't seg fault: pass \n");
  return true;
}

bool test_q2_2_EDGE() {
  merge_sort(NULL, -1);
  int a[] = {4,1,2,7,5,3,2};
  merge_sort(a, 1);
  merge_sort(a, -5);
  merge_sort(a, 0);
  printf("Q2_2_EDGE: didn't seg fault: pass \n");
  return true;
}


int main(void) {
  printf("Running supplied tests \n");
  test_q1_1();
  test_q1_2();
  test_q3_1();
  test_q3_2();
  test_q4();

  printf("\n\nRunning additional tests \n");
  test_q1_1_1();
  test_q1_1_2();
  test_q1_1_3();
  test_q1_1_4();
  test_q1_2_1();
  test_q2_1();
  test_q2_2();
  test_q4_L_1();
  test_q4_L_2();
  test_q4_L_3();
  test_q4_L_4();
  test_q4_L_5();
  test_q4_2();
  
  printf("\n\nRunning edge cases tests\n");
  test_q1_EDGE();
  test_q1_2_EDGE_1();
  test_q1_2_EDGE_2();
  test_q2_1_EDGE();
  test_q2_2_EDGE(); 

  return 0;
}