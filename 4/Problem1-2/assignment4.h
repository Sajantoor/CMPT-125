
#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H

#include <stdbool.h>

#include "BST/BST.h"

typedef enum {PLUS, MINUS, MULT, DIV} bin_op;

// evaluates an arithmetic expression in the given tree
// assumption: tree is not null and not empty
// assume all internal nodes are bin_ops, i.e. have values between 0 and 3
float eval_arithmetic_expression(BTnode_t* root);


// returns the maximal element in the tree
// assumprion: tree is not null and not empty
int get_max(BST_t* tree);

// returns the median element in the tree.
// if the sorted array ELTS[0...n-1] contained the elements of the tree
// the the output should be A[round_down(n/2)]
// For example, if the tree contains {1,3,6,8,100}, the output should be 6
// if the tree contains {1,2,3,7,8,100}, the output should be 7.
int get_median(BST_t* tree);

#endif
