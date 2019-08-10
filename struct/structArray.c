#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	uint8_t devAddr[4];
	uint8_t NwSKey[16];
	uint8_t AppSkey[16];
} device;
////////////////////////////////////////////////////
void pHex(uint8_t* str, int len);

void pHex(uint8_t* str, int len)
{
    for (int i = 0; i < len; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}
////////////////////////////////////////////////////
int main ()
{
	printf("AppStart..................\n");
	device *d = malloc(sizeof(device)*10);
	memset(d, 0, sizeof(d));

	for(int i = 0 ; i < 10 ; i++){
		memset(d[i].devAddr, i, 4);
		memset(d[i].NwSKey, i*2, 16);
		memset(d[i].AppSkey, i*3, 16);
	}

	for(int i = 0 ; i < 10 ; i++){
		printf("------------------\n");
		pHex(d[i].devAddr, 4);
		pHex(d[i].NwSKey, 16);
		pHex(d[i].AppSkey, 16);
	}

	free(d);
	return 0;
}
