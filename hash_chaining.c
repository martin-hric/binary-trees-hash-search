//zdroj: https://www.log2base2.com/algorithms/searching/open-hashing.html
#include "hash_chaining.h"
#include<stdlib.h>

struct node *chain[size];

void init(int pocet)
{
    for(int i = 0; i < pocet; i++)
        chain[i] = NULL;
}

void insert_hash_chain(struct node *table,int value)
{
    table = malloc(sizeof(struct node));
    table->data = value;
    table->next = NULL;

    int key = value % size;

    if(chain[key] == NULL)
        chain[key] = table;
    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = table;
    }
}

struct node *search_hash_chain(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    while(temp)
    {
        if(temp->data == value) return temp;
        temp = temp->next;
    }
    return NULL;
}

void free_hash_chain(struct node *Node){
    if(Node==NULL) return;
    free_hash_chain(Node->next);
    free(Node);
 }