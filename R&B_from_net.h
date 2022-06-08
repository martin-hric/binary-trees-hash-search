#ifndef DSA_TESTS_RED_BLACK_TREE_H
#define DSA_TESTS_RED_BLACK_TREE_H

#endif

enum nodeColor {
    RED,
    BLACK
};

typedef struct rbNode {
    int data, color;
    struct rbNode *link[2];
}RBNODE;

RBNODE *createNode(int data);
RBNODE *insertion_rbtree(int data);
void free_rbtree(RBNODE *temp);
RBNODE *search_rb(int value);