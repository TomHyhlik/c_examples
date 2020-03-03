/*C program to guess a random number.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
 
int main(void)
{
    unsigned int randomNumber, count;

   printf("\n How many numbers u want?\n");
    scanf("%d", &count);
 
    for (int i = 0; i < count ;  i++)
    {
        randomNumber = rand()%1000;         //generate random number
       printf("%d \t", randomNumber);

    }
    printf("\n");   
    return 0;
}