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
    printf("Q1-1 ok\n\n");
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
bool test_q4_1()  {
  queue_t* q1 = queue_create();
  enqueue(q1,1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);

  int length = queue_length(q1);

  if (length == 4)  {
    printf("Q4-1 ok\n");
    return true;
  } else {
    printf("Q4-1 ERROR\n");
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

// tests free
bool test_q4_3()  {
  queue_t* q3 = queue_create();
  enqueue(q3,1);
  enqueue(q3,2);
  enqueue(q3,3);
  enqueue(q3,4);
  queue_free(q3);

  if (q3->head == NULL)  {
    printf("Q4-3 ok\n");
    return true;
  } else {
    printf("Q4-3 ERROR\n");
    return false;
  }
}


int main(void) {
  test_q1_1();
  test_q1_1_1();
  test_q1_1_2();
  test_q1_1_3();
  test_q1_1_4();
  test_q1_2();
  // test_q2_1();
  // test_q2_2();
  // test_q3_1();
  // test_q3_2();
  // test_q4();
  // test_q4_1();
  // test_q4_2();
  // test_q4_2();
  // test_q4_3();
  return 0;
}