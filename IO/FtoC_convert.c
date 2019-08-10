#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int fahr;

/* lower limit of table */
/* upper limit */
/* step size */
/* print Fahrenheit-Celsius table */
void main(void){
printf("C \t F\n");
for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	printf("%3d    %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}