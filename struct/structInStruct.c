#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	uint8_t synchByte;
	uint8_t myAddr;
	uint8_t endAddr;
	uint8_t type;
	uint16_t dataLength;
} RS485_Rx_header_t;





typedef struct {
	RS485_Rx_header_t* header;
	uint8_t crc;
	// uint8_t* data;
} RS485_Rx_cmd_t;


int main(void)
{
    printf("AppStart....................\n");

	RS485_Rx_cmd_t* cmd = malloc(sizeof(RS485_Rx_cmd_t));
	cmd->header = malloc(sizeof(RS485_Rx_header_t));

	 cmd->header->type = 0x88;






    return 0;
}