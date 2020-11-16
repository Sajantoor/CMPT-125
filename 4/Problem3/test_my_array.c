#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_array.h"

my_array* create_my_ar_init(int len) {
  my_array* arr = create_my_array(len);
  for (int i=0; i<len; i++)
    my_ar_set_value(arr, i, i*i);
  return arr;
}

void test_q3_part1() {
  my_array* arr = create_my_ar_init(10);

  if (my_ar_get_length(arr) == 10)    printf("Q3-1-get_length ok\n");
  else    printf("Q3-1-get_length-1 ERROR\n");

  if (my_ar_get_value(arr,5) == 25)    printf("Q3-1-set/get_value ok\n");
  else    printf("Q3-1-set/get_value ERROR\n");

  my_ar_free(arr);
}

/********************************/
/******** testing part 2 ********/
/********************************/


void test_q3_resize() {
  my_array* arr = create_my_ar_init(10);

  my_ar_resize(arr, 20);

  if (my_ar_get_length(arr) == 20)   printf("Q3-2-resize-test1 ok\n");
  else    printf("Q3-2-resize-test1 ERROR\n");

  if (my_ar_get_value(arr,5) == 25)   printf("Q3-2-resize-test2 ok\n");
  else    printf("Q3-2-resize-test2 ERROR\n");

  my_ar_free(arr);
}


void test_q3_copy() {
  my_array* arr = create_my_ar_init(10);

  my_array* arr2 = my_ar_copy(arr);

  if (my_ar_get_length(arr2) == 10)    printf("Q3-2-copy-test1 ok\n");
  else    printf("Q3-2-copy-test1 ERROR\n");

  if (my_ar_get_value(arr2,5) == 25)    printf("Q3-2-copy-test2 ok\n");
  else    printf("Q3-2-copy-test2 ERROR\n");

  my_ar_set_value(arr2,5,7);
  if (my_ar_get_value(arr2,5) == 7 && my_ar_get_value(arr,5)== 25)
    printf("Q3-2-copy-test3 ok\n");
  else   
    printf("Q3-2-copy-test3 ERROR\n");

  my_ar_free(arr);
  my_ar_free(arr2);
}


void test_q3_append() {
  my_array* arr1 = create_my_array(5);
  for (int i=0; i<5; i++)
    my_ar_set_value(arr1, i, i*i);

  my_array* arr2 = create_my_array(5);
  for (int i=0; i<5; i++)
    my_ar_set_value(arr2, i, 2*i*i);

  my_ar_append(arr1,arr2);

//  printf("printing new arr1:\n");
//  for (int i=0; i<10; i++)
//    printf("arr1[%d] = %d\n", i, my_ar_get_value(arr1, i));

  if (my_ar_get_length(arr1) == 10)    printf("Q3-2-append-test1 ok\n");
  else    printf("Q3-2-append-test1 ERROR\n");

  if (my_ar_get_value(arr1,4) == 16)    printf("Q3-2-append-test2 ok\n");
  else    printf("Q3-2-append-test2 ERROR\n");

  if (my_ar_get_value(arr1,9) == 32)    printf("Q3-2-append-test3 ok\n");
  else    printf("Q3-2-append-test3 ERROR\n");

  // test no side effects
  if (my_ar_get_value(arr2,4) == 32)    printf("Q3-2-append-test4 ok\n");
  else    printf("Q3-2-append-test4 ERROR\n");


  my_ar_free(arr1);
  my_ar_free(arr2);

}

void test_q3_find() {
  my_array* arr = create_my_ar_init(10);
  if (my_ar_find(arr, 4) == 2)  printf("Q3-2-find-test1 ok\n");
  else    printf("Q3-2-find-test1 ERROR\n");

  my_ar_free(arr);
}
/********************************/
/******** testing part 3 ********/
/********************************/

/******** testing map  ********/

int mult3(int k) { return k*3;}

void test_q3_map() {
  my_array* arr = create_my_ar_init(10);

  my_ar_map(arr, mult3);
 
  int len = my_ar_get_length(arr);
  if (len == 10)    printf("Q3-3-map-test1 ok\n");
  else    printf("Q3-3-map-test1 ERROR\n");


  int flag = 0;
  for (int i=0; i<len; i++) {
    if (my_ar_get_value(arr, i) != i*i*3) {
      printf("Q3-3-map-test2 ERROR in index %d\n",i);
      flag = 1;
    }
  }
  if (!flag)      printf("Q3-3-map-test2 ok\n");

  my_ar_free(arr);
}

/******** testing reduce  ********/

int sum(int a,int b) { return a+b;}

void test_q3_reduce() {
  my_array* arr = create_my_ar_init(6);

  int res = my_ar_reduce(arr, sum);
  // expected 1+4+9+16+25=55
  if (res==55)    printf("Q3-3-reduce-test1 ok\n");
  else    printf("Q3-3-reduce-test1 ERROR\n");

  my_ar_free(arr);
}

/******** testing filter  ********/


bool is_odd(int a) { return a%2;}

void test_q3_filter() {
  my_array* arr = create_my_ar_init(6);

  my_array* odd_nums = my_ar_filter(arr, is_odd);

//  printf("printing odd_nums::: len = %d\n", my_ar_get_length(odd_nums));
//  for (int i=0; i<my_ar_get_length(odd_nums); i++)
//    printf("arr1[%d] = %d\n", i, my_ar_get_value(odd_nums, i));
//  printf("\n");

  if (odd_nums != NULL)
      printf("Q3-3-filter-test1 ok\n");
  else {
    printf("Q3-3-filter-test1 ERROR - retuned NULL\n");
    return;
  }

  
  if (my_ar_get_length(odd_nums) == 3)    printf("Q3-3-filter-test2 ok\n");
  else    printf("Q3-3-filter-test2 ERROR\n");

  if (my_ar_find(odd_nums, 4) == -1)  printf("Q3-3-filter-test3 ok\n");
  else    printf("Q3-3-find-test3 ERROR\n");


  if (my_ar_find(odd_nums, 9) > -1)  printf("Q3-3-filter-test4 ok\n");
  else    printf("Q3-3-find-test4 ERROR\n");


  my_ar_free(arr);
  my_ar_free(odd_nums);
}


int main() {
  test_q3_part1();
  test_q3_resize();
  test_q3_copy();
  test_q3_append();
  test_q3_find();
  test_q3_map();
  test_q3_reduce();
  test_q3_filter();
  return 0;
}