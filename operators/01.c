#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ByteArray.h"

int main(void)
{

	uint8_t array[3];

	for(int i = 0; i < sizeof(array); i++)
	{
		array[i] = (uint8_t)i;
	}

	pHex_nl(array, sizeof(array));

	arrayInvert(array, sizeof(array));

	pHex_nl(array, sizeof(array));


	return 0;
}