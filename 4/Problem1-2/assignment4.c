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
int binary_tree_array(BTnode_t* root, int arr[], unsigned int i) {
  // base case
  if (root == NULL)
    return i;
  
  // left half add, to the array
  if (root->left != NULL)
    i = binary_tree_array(root->left, arr, i);
    
  // add root to the array 
  arr[i] = root->value;
  i++;

  // right half add to array
  if (root->right != NULL)
    i = binary_tree_array(root->right, arr, i);

  return i;
}

int get_median(BST_t* tree) {
  if (!tree) {
    return -1;
  }
  // median is middle number of in order traversal of binary tree
  // count nodes to create an array and know which index is the median
  int count = count_nodes(tree->root);
  // if it's just one element, it must be the root 
  if (count == 1) {
    return tree->root->value; 
  }
  // create array to store tree
  int* arr = malloc(sizeof(int) * count); 
  if (arr == NULL) {
    return -1; 
  }
  // find index median
  int index = count / 2.0;
  // convert binary tree to array
  binary_tree_array(tree->root, arr, 0);

  return arr[index];
}
