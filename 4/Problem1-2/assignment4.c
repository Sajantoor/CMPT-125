#include "assignment4.h"
#include <stdio.h> 

float eval_arithmetic_expression(BTnode_t* root) {
  // if null
  if (!root) 
    return 0;

  // recursively go through the left and right of the tree to bottom
  float leftSum = eval_arithmetic_expression(root->left);
  float rightSum = eval_arithmetic_expression(root->right);
  
  // must be a binary expression if it has 2 children -> not a leave
  if (root->left && root->right) {
    // evalute expressions 
    switch(root->value) {
      case (PLUS):
        return leftSum + rightSum;
      case (MINUS):
        return leftSum - rightSum;
      case(MULT) : 
        return leftSum * rightSum;
      case (DIV):
        return leftSum / rightSum;
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
