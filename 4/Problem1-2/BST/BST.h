#ifndef BST_H
#define BST_H

#include "BTnode.h"


typedef struct BST {
  BTnode_t* root;
} BST_t;

BST_t* create_BST();

BTnode_t* find(BST_t* tree, int item);

void BST_insert(BST_t* tree, int item);

void BST_remove(BST_t* tree, int item);


#endif