/**********************vypracoval: Martin Hric ************************
 *               DSA: Vyhladavanie v dynamickych mnozinach
 */

#include "my_avl.h"
#include <stdlib.h>

/* funkcia , ktora mi vrati vysku nody */
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}
/* funkcia, na zistenie vyssieho cisla*/
int max(int a,  int b) {
    return (a > b) ? a : b;
}
/* vytvorenie nody*/
struct Node *create(int key) {
    struct Node *novaNode = (struct Node *)malloc(sizeof(struct Node));
    if(novaNode==NULL) exit(-1);
    novaNode->key = key;
    novaNode->left = NULL;
    novaNode->right = NULL;
    novaNode->height = 1;
    return (novaNode);
}
/* funkcie na vyvazovanie, su len 2 , kedze dalsie 2 druhy vyvazovania vytvorim kombinaciou ich 2*/
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
/* zistenie vysky laveho a praveho child*/
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL)           //ak este root nieje, tak vyuzijem funkciu create na vytvorenie
        return (create(key));

    if (key < node->key)                       //porovnam key a na zaklade toho zapisujem bud vlavo alebo vpravo
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;                  //ak je to rovnake tak neinstertujem

    node->height = 1 + max(height(node->left),height(node->right));       //vypocitam vysku

    int balance = getBalance(node);                       //pri kazdom volani insert rotujem strom
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {          //lavo-prave rotovanie
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {   //pravo-lave rotovanie
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *search(struct Node *node, int key) {

    if (node->key > key) {  //search je jednoduchy, len porovnavam nody a posuvam sa az kym ho najdem, ak ho nenajdem vraciam NULL
        search(node->left, key);
    } else if (node->key < key) {
        search(node->right, key);
    }else if (node->key == key) {
        return node;
    }

    return NULL;
}
/* funkcia na uvolnenie celeho stromu*/
void free_tree(struct Node *root){
    if(root == NULL){
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

