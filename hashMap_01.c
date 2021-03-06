/*
 * code taken from:
 * http://www.kaushikbaruah.com/posts/data-structure-in-c-hashmap/
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    int val;
    struct node *next;
};

struct table{
    int size;
    struct node **list;
};

///////////////////////////////////////////////////////
struct table *createTable(int size)
{
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);

    for(int i = 0; i < size; i++) {
        t->list[i] = NULL;
    }

    return t;
}

///////////////////////////////////////////////////////
int hashCode(struct table *t,int key)
{
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}

///////////////////////////////////////////////////////
void insert(struct table *t,int key,int val)
{
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}

///////////////////////////////////////////////////////
int lookup(struct table *t,int key)
{
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}
<<<<<<< HEAD

///////////////////////////////////////////////////////
int main()
{
	printf("AppStart......................\n");

=======
int main(){
	printf("AppStart................................\n");
>>>>>>> master
    struct table *t = createTable(5);

    insert(t,2,3);
    insert(t,5,4);
<<<<<<< HEAD
    insert(t,7,8);

    printf("%d\n",lookup(t,5));

	printf("AppEnd......................\n");
=======
    printf("%d\n",lookup(t,5));

	printf("AppEnd..................................\n");

>>>>>>> master
    return 0;
}

///////////////////////////////////////////////////////