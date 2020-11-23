#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "assignment4.h"

void create_my_tree(BTnode_t* n[11]) {
/**
// creates the following tree
//        6
//    /      \
//   1        8
//  / \     / \
// 0   3   7   10
//    / \      /
//   2   4    9
//        \ 
//         5
**/

  for (int i=0;i<11;i++)
    n[i] = create_node(i);

  set_left_child(n[6], n[1]);
  set_right_child(n[6], n[8]);
  
  set_left_child(n[1], n[0]);
  set_right_child(n[1], n[3]);
  
  set_left_child(n[3], n[2]);
  set_right_child(n[3], n[4]);
  
  set_left_child(n[8], n[7]);
  set_right_child(n[8], n[10]);
  
  set_right_child(n[4], n[5]);
  set_left_child(n[10], n[9]);
}

void test_q1() {
/***
// creates the following tree
//      +
//    /   \
//   *      +
//  / \    / \
// 3   -  5   /
//    / \    / \
//   9   7  8   -2
****/
  BTnode_t* root_plus = create_node(PLUS);
  BTnode_t* mult = create_node(MULT);
  BTnode_t* plus = create_node(PLUS);
  BTnode_t* minus = create_node(MINUS);
  BTnode_t* div = create_node(DIV);
  BTnode_t* neg_two = create_node(-2);
  BTnode_t* three = create_node(3);
  BTnode_t* five = create_node(5);
  BTnode_t* seven = create_node(7);
  BTnode_t* eight = create_node(8);
  BTnode_t* nine = create_node(9);

  set_left_child(root_plus, mult);
  set_right_child(root_plus, plus);
  
  set_left_child(mult, three);
  set_right_child(mult, minus);

  set_left_child(plus, five);
  set_right_child(plus, div);

  set_left_child(minus, nine);
  set_right_child(minus, seven);

  set_left_child(div, eight);
  set_right_child(div, neg_two);

  if (eval_arithmetic_expression(neg_two) == -2)    printf("Q1-1 ok\n");
  else    printf("Q1-1 ERROR\n");
    

  if (eval_arithmetic_expression(div) == -4)    printf("Q1-2 ok\n");
  else    printf("Q1-2 ERROR\n");
    
  if (eval_arithmetic_expression(plus) == 1)    printf("Q1-3 ok\n");
  else    printf("Q1-3 ERROR\n");
    
  if (eval_arithmetic_expression(mult) == 6)    printf("Q1-4 ok\n");
  else    printf("Q1-4 ERROR\n");
    
  if (eval_arithmetic_expression(root_plus) == 7)    printf("Q1-5 ok\n");
  else    printf("Q1-5 ERROR\n");
    
  return;
}

void test_q2() {
  BTnode_t* nodes[11];
  create_my_tree(nodes);

  BST_t* bstree = create_BST();
  
  bstree->root = nodes[0];
  if (get_max(bstree) == 0)    printf("Q2-1 ok\n");
  else    printf("Q2-1 ERROR\n");

  bstree->root = nodes[4];
  if (get_max(bstree) == 5)    printf("Q2-2 ok\n");
  else    printf("Q2-2 ERROR\n");

  bstree->root = nodes[7];
  if (get_max(bstree) == 7)    printf("Q2-3 ok\n");
  else    printf("Q2-3 ERROR\n");

  bstree->root = nodes[6];
  if (get_max(bstree) == 10)    printf("Q2-4 ok\n");
  else    printf("Q2-4 ERROR\n");

  bstree->root = nodes[10];
  if (get_max(bstree) == 10)    printf("Q2-5 ok\n");
  else    printf("Q2-5 ERROR\n");

  for (int i=0;i<11;i++)
    free(nodes[i]);
  free(bstree);

  return;
}


void test_q3() {
  BTnode_t* nodes[11];
  create_my_tree(nodes);

  BST_t* bstree = create_BST();
  
  bstree->root = nodes[0];
  if (get_median(bstree) == 0)    printf("Q3-1 ok\n");
  else    printf("Q3-1 ERROR\n");

  bstree->root = nodes[4];
  if (get_median(bstree) == 5)    printf("Q3-2 ok\n");
  else    printf("Q3-2 ERROR\n");

  bstree->root = nodes[7];
  if (get_median(bstree) == 7)    printf("Q3-3 ok\n");
  else    printf("Q3-3 ERROR\n");

  bstree->root = nodes[6];
  if (get_median(bstree) == 5)    printf("Q3-4 ok\n");
  else    printf("Q3-4 ERROR\n");

  bstree->root = nodes[10];
  if (get_median(bstree) == 10)    printf("Q3-5 ok\n");
  else    printf("Q3-5 ERROR\n");

  for (int i=0;i<11;i++)
    free(nodes[i]);
  free(bstree);

  return;
}


int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}