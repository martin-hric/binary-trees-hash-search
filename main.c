#include "my_avl.h"
#include "R&B_from_net.h"
#include "hash_chaining.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define POCET 10000000

void test_avl_l(int pocet){
    struct Node *root = NULL;
    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        root= insert(root,i);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search(root,i);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----AVL LINEAR TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nVyska stromu: %d", height(root->right));
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);
    free_tree(root);
}

void test_avl_r(int pocet,int *cisla){
    struct Node *root = NULL;
    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        root= insert(root,cisla[i]);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search(root,cisla[i]);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----AVL RANDOM TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nVyska stromu: %d", height(root->right));
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);
    free_tree(root);
}

void test_RB_l(int pocet){
    RBNODE *root = NULL;
    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        root= insertion_rbtree(i);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search_rb(i);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----R&B LINEAR TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);
    free_rbtree(root);
}

void test_RB_r(int pocet,int *cisla){
    RBNODE *root = NULL;

    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        root= insertion_rbtree(cisla[i]);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search_rb(cisla[i]);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----R&B RANDOM TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);
    free_rbtree(root);
}

void test_chain_l(int pocet){
    struct node *root=NULL;
    init(2000003);
    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        insert_hash_chain(root,i);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search_hash_chain(i);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----CHAIN LINEAR TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);
    free_hash_chain(root);
}

void test_chain_r(int pocet,int *cisla){
    struct node *root=NULL;
    init(2000003);
    float startInsert  = (float) clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        insert_hash_chain(root,cisla[i]);
    }
    float endInsert= (float)clock()/CLOCKS_PER_SEC;

    float startSearch=(float)clock()/CLOCKS_PER_SEC;
    for(int i=0;i<pocet;i++){
        search_hash_chain(cisla[i]);
    }
    float endSearch= (float)clock()/CLOCKS_PER_SEC;

    printf("\n-----CHAIN RANDOM TEST-----");
    printf("\nPocet prvkov: %d",POCET);
    printf("\nInsert time: %gs",endInsert - startInsert);
    printf("\nSearch time: %gs",endSearch - startSearch);

}

int main() {
    srand(time(NULL));
    int *random=(int*)malloc(POCET*sizeof(int));
    if(random==NULL) exit(-1);
    for(int i=0;i<POCET;i++){
        random[i]=((rand() * rand()) % 1000000000);
    }

    //test_avl_l(POCET);
    test_avl_r(POCET,random);
    //test_RB_l(POCET);
    test_RB_r(POCET,random);
    //test_chain_l(POCET);
    test_chain_r(POCET,random);

    free(random);
}