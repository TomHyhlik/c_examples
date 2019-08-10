#include <stdio.h>
#include <stdint.h>


int main(void)
{
	printf("program to print int8_t hex value.\n");
	printf("-----------------\n");
	printf("| hex \t| dec \t|\n");
	printf("-----------------\n");

	int8_t val = 0;


	for (int i = 0; i < 256; i++, val++) 
	{
		printf("| %.2X \t| %d \t|\n", (uint8_t)val, val);

	}





	return 0;
}