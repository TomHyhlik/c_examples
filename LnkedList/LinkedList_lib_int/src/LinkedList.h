#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int data;
    struct node* next;
} node;
  

node* create(int data,node* next);
node* prepend(node* head,int data);
node* append(node* head, int data);
node* insert_after(node *head, int data, node* prev);
node* insert_before(node *head, int data, node* nxt);
void traverse(node* head);
node* remove_front(node* head);
node* remove_back(node* head);
node* remove_any(node* head,node* nd);
void display(node* n);
node* search(node* head,int data);
void dispose(node *head);
int count(node *head);

node* insertion_sort(node* head);
node* reverse(node* head);








