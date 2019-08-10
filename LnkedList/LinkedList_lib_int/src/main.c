#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

    ////////////////////////////////////////////////////////////////
int main()
{
    printf("AppStart...........................\n");

    node* head = NULL;
    node* tmp = NULL;
 
    /* fill the list using prepend */
    for(int i = 0 ; i < 5 ; i++){
        head = prepend(head, i);
    }

    /* fill the list using append */
    for(int i = 50 ; i < 55 ; i++){
        append(head, i);
    }

    traverse(head);

    /* search a number in the linked list */
    int searchedNumber = 51;
    tmp = search(head, searchedNumber);
    if(tmp != NULL){
        printf("Element %d found.\n", tmp->data);
    } else {
        printf("Element %d not found.\n", searchedNumber);
    }

    /* insert data after some value in the list */
    int dataToInsertAfter = 0;
    tmp = search(head, dataToInsertAfter);
    if(tmp != NULL){
        int dataToInsert = -1;
        head = insert_after(head,dataToInsert,tmp);
        if(head != NULL)
            traverse(head);
    } else {
        printf("Element with value %d not found.",dataToInsertAfter);
    }

    /* insert data before some value in the list */
    int dataToInsertBefore = 50;
    tmp = search(head, dataToInsertBefore);
    if(tmp != NULL){
        int dataToInsert = 49;
        head = insert_before(head,dataToInsert,tmp);
        if(head != NULL)
            traverse(head);
    } else {
        printf("Element with value %d not found.",dataToInsertBefore);
    }

    /* remove front and last */
    head = remove_front(head);
    head = remove_back(head);
    if(head != NULL)
        traverse(head);



    /* remove one velue in the linked list */
    int dataToRemove = 52;
    tmp = search(head,dataToRemove);
    if(tmp != NULL){
        remove_any(head,tmp);
    } else {
        printf("Element with value %d not found.", dataToRemove);
    }

    traverse(head);


    /* sort the list */
    head = insertion_sort(head);
    printf("Sorted: \n");
    traverse(head);


    /* reverse the list */
    head = reverse(head);
    printf("Reversed: \n");
    traverse(head);



    dispose(head);
    return 0;
}