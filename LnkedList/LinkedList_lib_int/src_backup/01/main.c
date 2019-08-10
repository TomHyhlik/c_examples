#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

    ////////////////////////////////////////////////////////////////
int main()
{
    printf("AppStart...........................\n");

    node* head = NULL;
    // node* tmp = NULL;
 
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
    if(search(head, searchedNumber) != NULL){
        printf("Element %d found.\n", searchedNumber);
    } else {
        printf("Element %d not found.\n", searchedNumber);
    }


    // case 4:
    //     printf("Enter the element value where you want to insert after:");
    //     scanf("%d",&data);
    //     tmp = search(head,data);
    //     if(tmp != NULL)
    //     {
    //         printf("Enter the element value to insert after:");
    //         scanf("%d",&data);
    //         head = insert_after(head,data,tmp);
    //         if(head != NULL)
    //             traverse(head,disp);
    //     }
    //     else
    //     {
    //         printf("Element with value %d not found.",data);
    //     }




        // case 5:
        //     printf("Enter the element value where you want to insert before:");
        //     scanf("%d",&data);
        //     tmp = search(head,data);
        //     if(tmp != NULL)
        //     {
        //         printf("Enter the element value to insert before:");
        //         scanf("%d",&data);
        //         head = insert_before(head,data,tmp);
 
        //         if(head != NULL)
        //             traverse(head,disp);
        //     }
        //     else
        //     {
        //         printf("Element with value %d not found.",data);
        //     }
        //     break;
        // case 6:
        //     head = remove_front(head);
        //     if(head != NULL)
        //         traverse(head,disp);
        //     break;
        // case 7:
        //     head = remove_back(head);
        //     if(head != NULL)
        //         traverse(head,disp);
        //     break;
        // case 8:
        //     printf("Enter the element value to remove:");
        //     scanf("%d",&data);
        //     tmp = search(head,data);
        //     if(tmp != NULL)
        //     {
        //         remove_any(head,tmp);
        //         if(head != NULL)
        //             traverse(head,disp);
        //     }
        //     else
        //     {
        //         printf("Element with value %d not found.",data);
        //     }
        //     break;
        // case 9:
        //     head = insertion_sort(head);
        //     if(head != NULL)
        //         traverse(head,disp);
        //     break;
        // case 10:
        //     head = reverse(head);
        //     if(head != NULL)
        //         traverse(head,disp);
        //     break;
        
 

    dispose(head);
    return 0;
}