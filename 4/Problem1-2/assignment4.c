#include "assignment4.h"
#include <stdio.h> 

float eval_arithmetic_expression(BTnode_t* root) {
  if (!root) 
    return 0;
  
  // root is the binary expression
  // {PLUS = 0, MINUS = 1, MULT = 2, DIV = 3}
  // solve using recursion from bottom to top, left side and right side
  // Recommended appraoch: Switch statements

  // recursively go through the left and right of the tree to bottom
  eval_arithmetic_expression(root->left);
  eval_arithmetic_expression(root->right);
  
  // must be a binary expression if it has 2 children
  if (root->left && root->right) {
    if (root->value == PLUS) {
      float value = root->left->value + root->right->value;
      root->value = value; 
      root->left = NULL;
      root->right = NULL; 
      return value;
    } else if (root->value ==  MINUS) {
      float value = root->left->value - root->right->value;
      root->value = value; 
      root->left = NULL;
      root->right = NULL; 
      return value;
    } else if (root->value == MULT) { 
      float value = root->left->value * root->right->value;
      root->value = value; 
      root->left = NULL;
      root->right = NULL; 
      return value;
    } else if (root->value == DIV) {
      float value = root->left->value / root->right->value;
      root->value = value; 
      root->left = NULL;
      root->right = NULL; 
      return value;
    }
  }  

  return root->value;
}

int get_max(BST_t* tree) {
  if (!tree) 
    return -1;
  
  // in binary tree, max is always the right most child 
  BTnode_t* el = tree->root; 
  while (el && el->right) {
    el = el->right; 
  }

  return el->value;
}

int get_median(BST_t* tree) {
  return -1;
}
