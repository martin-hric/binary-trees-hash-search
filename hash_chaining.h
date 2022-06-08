#ifndef ZADANIE2_MY_HASH_CHAINING_H
#define ZADANIE2_MY_HASH_CHAINING_H
#define size 20000003

#endif

struct node
{
    int data;
    struct node *next;
};
void init(int pocet);
void insert_hash_chain(struct node *table,int value);
struct node *search_hash_chain(int value);
void free_hash_chain(struct node *Node);