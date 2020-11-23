#include "assignment4.h"
#include <stdlib.h>

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

// --- Get Median -----  //
// Recursive function to get number of nodes in binary tree
int count_nodes(BTnode_t * root) {
  if (!root) {
    return 0; 
  }

  int count = 1;
  // count elements in left and right half of tree
  count += (count_nodes(root->right) + count_nodes(root->left));
  return count; 
}

// recursively function, creates an array with binary tree, in order traversal
int binary_tree_array(BTnode_t* root, int arr[], int i) {
     if (root == NULL)
          return i;

     if (root->left != NULL)
          i = binary_tree_array(root->left, arr, i);
    
    arr[i] = root->value;
    i++;

     if (root->right != NULL)
          i = binary_tree_array(root->right, arr, i);

     return i;
}

int get_median(BST_t* tree) {
  // median is middle number of in order traversal of binary tree
  // create array to store tree
  int count = count_nodes(tree->root);
  int* arr = malloc(sizeof(int) * count); 
  if (arr == NULL) {
    return -1; 
  }

  int index = count / 2.0;
  binary_tree_array(tree->root, arr, 0);


  return arr[index];
}
