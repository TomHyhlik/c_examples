#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define POS_1	10
#define POS_2	2

void reg_print(uint32_t reg)
{
	printf("Reg (DEC): %u\n", reg);
	printf("Reg (HEX): %.8X\n", reg);
}

int main(void)
{
	printf("AppStart.........................\n");


	uint32_t reg;

	reg = 0;


	printf("Set bit at position %d\n", POS_1);
	reg |= (1 << POS_1);
	reg_print(reg);


	printf("Set bit at position %d\n", POS_2);
	reg |= (1 << POS_2);
	reg_print(reg);



	printf("Reset bit at position %d\n", POS_1);
	reg &= ~(1 << POS_1);
	reg_print(reg);

	



	printf("AppEnd.........................\n");
	return 0;
}