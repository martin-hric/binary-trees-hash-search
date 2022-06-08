#ifndef ZADANIE2_MY_AVL_H
#define ZADANIE2_MY_AVL_H

#endif
#include<stdlib.h>
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N);
struct Node *insert(struct Node *node,int key);
struct Node *search(struct Node *node,int key);
void free_tree(struct Node *root);