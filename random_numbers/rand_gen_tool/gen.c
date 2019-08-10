#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///////////////////////////////////////////////////////////////////////
void gen(char kind, int count, int digits)
{
    switch (kind)
    {
    case 'h':   case 'H':
        gen_hex(count, digits);

        break;
    case 'd':   case 'D':
    	gen_dec(count, digits);

        break;
    case 'b':   case 'B':
    	gen_bin(count, digits);

        break;    
    default:
    printf("error in kind switch\n" );
    printf("the switch argument is:  '%c'\n", kind);
        break;        
    } 
}


///////////////////////////////////////////////////////////////////////
void gen_hex(int count, int digits)
{
    for ( int i = 0 ; i < count ; i++ )
    {
        for ( int j = 0 ; j < digits ; j++ )
        {
            printf("%01x", rand() % 16) ;
        }
        printf("\t");
    }
printf("\n");   
}

///////////////////////////////////////////////////////////////////////
void gen_bin(int count, int digits)
{
    for ( int i = 0 ; i < count ; i++ )
    {
        for ( int j = 0 ; j < digits ; j++ )
        {
            printf("%d", rand() % 2) ;
        }
        printf("\t");
    }
printf("\n");   
}

///////////////////////////////////////////////////////////////////////
void gen_dec(int count, int digits)
{
    for ( int i = 0 ; i < count ; i++ )
    {
        for ( int j = 0 ; j < digits ; j++ )
        {
            printf("%d", rand() % 10) ;
        }
        printf("\t");
    }
printf("\n");   
}