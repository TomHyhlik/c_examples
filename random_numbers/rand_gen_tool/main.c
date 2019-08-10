/*
This program generates various types of random numbers 
It's possible to run the program and then input arguments or call the program with arguments for direct execution.

Tge calling must have following syntax:
 ./rand_gen_tool
 or
 ./rand_gen_tool  <type>  <numberCount>  <numberOfDigits>

FUTURE WORK:
>> make variables as global structures and optionally call them with pointers.
>> use bettter generating function. (The rand() generates still the same array)
>>	alert the code
>> make better makefile with more options
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include "main.h"


int main(int argc, char *argv[])
{
	if( argc == 4 )			// valid input, execute the operation
	{
		int count = strtoumax( argv[2], NULL, 10);
		int digits = strtoumax( argv[3], NULL, 10);	
//d		printf("inputs: %c %d %d \n", argv[1][0], count, digits);
		gen(argv[1][0], count, digits);
	}
	else if( argc == 1 )	// program turned on, go to menu
	{
		printf("\n What kind of number do you wantt?\n");
		printf(" H >> Hexadecimal\n");
		printf(" D >> Decimal\n");
		printf(" B >> binary\n");
		menu();       
	}
	else					//	invalid input, exit...
	{
		printf("Invalid input. Exiting...\n");
	} 
    return 0;
}
