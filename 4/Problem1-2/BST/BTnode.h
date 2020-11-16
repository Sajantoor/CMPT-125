#ifndef BTNODE_H
#define BTNODE_H



struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;

};

typedef struct BTnode BTnode_t;

BTnode_t* create_node(int value);

void set_left_child(BTnode_t* parent, BTnode_t* left_child);

void set_right_child(BTnode_t* parent, BTnode_t* right_child);

void preOrder(BTnode_t* root);

void inOrder(BTnode_t* root);

void postOrder(BTnode_t* root);



#endif