#include "assignment4.h"

float eval_arithmetic_expression(BTnode_t* root) {
  return -1;
}

int get_max(BST_t* tree) {
  if (!tree) 
    return -1;
  
  // on binary tree max is always the right most child 
  BTnode_t* el = tree->root; 
  while (el && el->right) {
    el = el->right; 
  }

  return el->value;
}

int get_median(BST_t* tree) {
  return -1;
}
