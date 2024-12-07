#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

Node* init_root(Node *root){
    root = NULL;
    return root;
}

Node* insert_value(Node *root, short value){
    if(root == NULL){
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;

    }else{
        if(value > root->value){
            root->right = insert_value(root->right, value);

        }else if(value < root->value){
            root->left = insert_value(root->left, value);

        }else{
            // Error Message, because is the same value
            printf("Cannot to be inserted, repeated value \n");
        }

        return root;
    }
}

void print_binarytree(Node *root){
    if(root != NULL){
        print_binarytree(root->left);
        if(root->left != NULL && root->right != NULL){
            // Node Two child
            printf("\033[31m%i\033[39m - ", root->value);
        }else if(root->left == NULL && root->right == NULL){
            // Node Leaf
            printf("\033[34m%i\033[39m - ", root->value);
        }else{
            // Node One child
            printf("\033[33m%i\033[39m - ", root->value);
        }
        print_binarytree(root->right);
    }
}

short search_value(Node *root, short value){
    Node *aux = (Node*) malloc(sizeof(Node));
    aux = root;

    while(aux != NULL){
        if(aux->value == value){
            return value;
        }else{
            if(value < aux->value){
                aux = aux->left;
            }else{
                aux = aux->right;
            }
        }
    }

    return 0;
}

Node* remove_value(Node *root, short value){
    
    while(root != NULL){
        if(root->value == value){
            // Node leaf
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;

            // Node Two child
            }else if(root->left != NULL && root->right != NULL){
                Node *aux = (Node*)malloc(sizeof(Node));
                aux = root;

                aux = aux->left;
                while(aux->right != NULL){
                    aux = aux->right;
                }

                root->value = aux->value;
                aux->value = value;

                root->left = remove_value(root->left, value);

                return root;

            // Node One child
            }else{
                Node *aux = (Node*)malloc(sizeof(Node));
                
                if(root->left != NULL){
                    aux = root->left;
                }else{
                    aux = root->right;
                }

                free(root);
                return aux;
            }

        }else{
            if(value < root->value){
                root->left = remove_value(root->left,value);
            }else{
                root->right = remove_value(root->right, value);
            }
        }

        return root;
    }
}
