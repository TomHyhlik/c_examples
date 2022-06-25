
#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

const int years_cnt = 30;                   // number of years
const double year_on_year_inflation = 10;  // % 

////////////////////////////////////////////////////////////////////
int main (void)
{
    double result = 1;

    printf("____________________________________________\n");

    for (int i = 1; i <= years_cnt; i++)
    {
        result *= (1 - (year_on_year_inflation/100));

        printf("After %d years the value degrades to: %.2f \% %%\n", i, result*100);
    }
   
    return 0;
}

