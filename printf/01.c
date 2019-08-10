#include <stdio.h>
#include <stdint.h>

int main(void)
{
	printf("AppStart...................\n");

	//////////////////////////////////////////
	printf("________char______\n");
	char a = 'a';
	printf("char: %c, has dec ASCII value: %d, "
			"and hex ASCII value: %.2X\n", a, a, a);

	//////////////////////////////////////////
	printf("_________float_&_double_____\n");
	double f = 12.3456789;
	printf("The whole float is: %f\n", f);
	printf("Here is with only 3 decimal places: %.3f\n", f);



	return 0;
}
