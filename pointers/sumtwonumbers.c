#include <stdio.h>
int main()
{
   int fno, sno, *ptr, *qtr, sum;

   ptr = &fno;
   qtr = &sno;
   
   printf("\n\n Pointer : Add two numbers :\n"); 
   printf("--------------------------------\n");   
 
   printf(" Input the first number : ");
   scanf("%d", &fno);
   printf(" Input the second  number : ");
   scanf("%d", &sno);   
   
   sum = *ptr + *qtr;
 
   printf(" The sum of the entered numbers is : %d\n\n",sum);
 
   return 0;
}


