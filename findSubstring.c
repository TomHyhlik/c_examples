// this example set relays variable according to the message format
#include <string.h>
#include <stdio.h>

int main()
{
	char message_ascii[] = "{\"relay01\":0,\"relay02\":1,\"relay03\":0,\"relay04\":0}";
   
	int relay01;
	int relay02;
	int relay03;
	int relay04;

	char *pMsg;

	pMsg = strstr (message_ascii,"relay01");
	relay01 = *(pMsg + 9) - '0';
	pMsg = strstr (message_ascii,"relay02");
	relay02 = *(pMsg + 9) - '0';
	pMsg = strstr (message_ascii,"relay03");
	relay03 = *(pMsg + 9) - '0';
	pMsg = strstr (message_ascii,"relay04");
	relay04 = *(pMsg + 9) - '0';

	printf("%d %d %d %d\n", relay01, relay02, relay03, relay04);

    return 0;
}
