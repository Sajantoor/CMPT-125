#include <stdio.h>
#include <stdlib.h>

#include "BTnode.h"

BTnode_t* create_node(int val) {
    BTnode_t* newNode = (BTnode_t*) malloc(sizeof(BTnode_t));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void set_left_child(BTnode_t* parent, BTnode_t* left_child) {
  parent->left = left_child;
  left_child->parent = parent;
}

void set_right_child(BTnode_t* parent, BTnode_t* right_child) {
  parent->right = right_child;
  right_child->parent = parent;
}

void preOrder(BTnode_t* root) {
  if (root == NULL)
    return;  

  printf("%d ", root->value);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(BTnode_t* root) {
  if (root == NULL)
    return;  

  inOrder(root->left);
  printf("%d ", root->value);
  inOrder(root->right);
}

void postOrder(BTnode_t* root) {
  if (root == NULL)
    return;  

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->value);
}


