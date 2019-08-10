#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu()
{

    unsigned char gen_number_kind,                                             // menu variables
    kind, kind_input_count = 0, number_input_count = 0, digits_input_count = 0;
    int gen_number_count, gen_number_digits;

//  asking for kind of generating number
	input_number_kind:
	printf("number kind: ");
	scanf("%c", &gen_number_kind);
    printf("\n");
	if (gen_number_kind != 'h' && gen_number_kind != 'H' && gen_number_kind != 'd' &&
     gen_number_kind != 'D' && gen_number_kind != 'b' && gen_number_kind != 'B')
	{
        kind_input_count++;
        if (kind_input_count > 4)
        {
            printf("Invalid input three times. Exiting...\n");
            return 0;
        }
        printf("Invalid input, try again...\n");
        goto input_number_kind;
    }


//  asking for count of generating numbers
    input_number_count:
    printf("number count:\t");
    scanf("%d", &gen_number_count);
    printf("\n");
    if (gen_number_count <= 0 || gen_number_count > 1000)
    {
        number_input_count++;
        if (number_input_count > 4)
        {
            printf("Invalid input three times. Exiting...\n");
            return 0;
        }
        printf("Invalid input, try again...\n");
        goto input_number_count;  
    }


//  asking for count of digits of generating numbers
    input_number_digits:
    printf("number digits:\t");
    scanf("%d", &gen_number_digits);
    printf("\n");
    if (gen_number_digits <= 0 || gen_number_digits > 1000)
    {
        digits_input_count++;
        if (digits_input_count > 4)
        {
            printf("Invalid input three times. Exiting...\n");
            return 0;
        }
        printf("Invalid input, try again...\n");
        goto input_number_digits;  
    }


    printf("_______________________________________________\n");

    gen(gen_number_kind, gen_number_count, gen_number_digits);


}   // void menu();