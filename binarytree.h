#ifndef _BINARYTREE_H
#define _BINARYTREE_H

// Node Struct, content value and Pointers Left Right
typedef struct node{
    short value; 
    struct node *left, *right;
 
}Node;


Node* init_root(Node *root);
Node* insert_value(Node *root, short value);
void print_binarytree(Node *root);
short search_value(Node *root, short value);
Node* remove_value(Node *root, short value);

#endif