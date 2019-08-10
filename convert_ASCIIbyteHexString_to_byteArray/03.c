#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

////////////////////////////////////////////////////////////
typedef enum {
    false, true
}bool;

uint8_t* convert_ASCIIbyteHexString_to_byteArray(uint8_t* in, uint8_t in_len);
void pHex(uint8_t* string, uint8_t string_len);
void pASCII(uint8_t* string, uint8_t string_len);


////////////////////////////////////////////////////////////
/* according to the ASCII table
 */
uint8_t* convert_ASCIIbyteHexString_to_byteArray(uint8_t* in, uint8_t in_len)
{
	int out_point = 0;
	int number;

    /* create space for the final message */
    uint8_t* out = calloc(in_len/2, sizeof(uint8_t));

	/* for each character */
	for (int i = 0 ; i < in_len ; i++)
	{
		/* 1...9 */
		if(in[i] >= 48 && in[i] <= 57){
			number = in[i] - 48;
		} 
		/* A...F */
		else if (in[i] >= 65 && in[i] <= 70){
			number = in[i] - 65 + 10;
		}
		/* a...f */
		else if (in[i] >= 97 && in[i] <= 102){
			number = in[i] - 97 + 10;
		} 
		else {
			printf("Invalid character: \"%d\", at possition: %d\n", in[i], i);
			return NULL;
		}
		/* in case of an odd or even character */
		if(i%2 == 1){
			out[out_point] |= number;
			out_point++;
		} else {
			out[out_point] |= number << 4;
		}
	}
	return out;
}
////////////////////////////////////////////////////////////
void pHex(uint8_t* string, uint8_t string_len)
{
	for (int i = 0; i < string_len ; i++){
		printf("%.2X ", string[i]);
	}
	printf("\n");
}
////////////////////////////////////////////////////////////
void pASCII(uint8_t* string, uint8_t string_len)
{
	for (int i = 0; i < string_len ; i++){
		printf("%c", string[i]);
	}
	printf("\n");
}


////////////////////////////////////////////////////////////
int main()
{
    printf("App started_______________________________\r\n");

    /* message in hex*/
    uint8_t *str[10];
    
    str[0] = "54686973";
	str[1] = "70726f6772616d6d696e67";
	str[2] = "6c616e6775616765";
	str[3] = "6973";
	str[4] = "6c696b65";
	str[5] = "444959";
    // printf("///////////////////////////////////////////////\n");
	for(int k = 0 ; k < 6 ; k++){
    uint8_t* data = convert_ASCIIbyteHexString_to_byteArray(str[k], strlen(str[k]));
    uint8_t data_len = strlen(str[k]) /2;

	    if(data != NULL){
	    	// pHex(data, data_len);
	    	pASCII(data, data_len);
	    }

		free(data);
	}
	return 0;
}
// End Of File