#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
////////////////////////////////////////////////////////////
typedef enum {
    false, true
}bool;

bool convert_ASCIIbyteHexString_to_byteArray(uint8_t* out, char* in);

void pHex_nl(uint8_t* str, int len);
////////////////////////////////////////////////////
/* prints array hex numbers with \n at the end
 */
void pHex_nl(uint8_t* str, int len)
{
	if(str == NULL){
		printf("Empty array passed to pHex function.\n");
		return;
	}
    for (int i = 0; i < len; ++i)
        printf("%.2X", str[i]);
    printf("\n");
}

////////////////////////////////////////////////////////////
/* according to the ASCII table
 */
bool convert_ASCIIbyteHexString_to_byteArray(uint8_t* out, char* in)
{
	int out_point = 0;
	int number;
	memset(out, 0, strlen(in)/2);

	/* for each character */
	for (int i = 0 ; i < strlen(in); i++)
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
			return false;
		}
		/* in case of an odd or even character */
		if(i%2 == 1){
			out[out_point] |= number;
			out_point++;
		} else {
			out[out_point] |= number << 4;
		}
	}	
	return true;
}

////////////////////////////////////////////////////////////
int main()
{
    printf("App started___________________\r\n");

    /* message in hex*/
    char in[] = "7B2272656C61793031223A302C2272656C61793032223A312C2272656C61793033223A302C2272656C61793034223A307D";
    // char in[] = "7B2272656C61793031223A";

    printf("%s\n", in);

    /* create space for the final message */
    uint8_t out[strlen(in)/2];

    if(convert_ASCIIbyteHexString_to_byteArray(out, in))
    {
    	pHex_nl(out, strlen(in)/2);
	}

return 0;
}
// End Of File