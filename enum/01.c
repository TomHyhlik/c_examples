#include <stdio.h>

#define NECUM 0x10

/* comment */
// banik pycoooooo

/* create boolean data type */
typedef enum {
    false, true
}bool;


int main(int argc, char const *argv[])
{
	printf("AppStart..............."\r\n);

	printf("value: %d\r\n", NECUM);

 	return 0;
}

switch(programStatus)
{
	case offline:
		printf("OFFLINE\n");
		break;
	case online:
		printf("ONLINE\n");
		programStatus_save(offline);
		break;
	default:
		printf("UNKNOWN, go offline...\n");
		programStatus = offline;
		programStatus_save(offline);
	}



