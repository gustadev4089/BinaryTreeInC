#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void){

    // Initialize root node
    Node *root;
    root = init_root(root);

    // Creating a list of short interger
    short list[] = {78,61,80,90,79,81,100,85,84,86,62,75,53,55,60,23,12,30,28,38,34,73};

    // Populating binarytree
    for(short c=0; c < (sizeof(list)/sizeof(short)); c++){
        root = insert_value(root, list[c]);
    }

    printf("Testing From Main\n");

    print_binarytree(root);
    printf("\n");

    return 0;
}