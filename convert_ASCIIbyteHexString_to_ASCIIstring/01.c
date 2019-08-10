
#include <string.h>
#include <stdio.h>

int hex_to_int(char c);
int hex_to_ascii(char c, char d);

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}

int main()
{

    printf("App started___________________\r\n");

    /* message in hex*/
    char st[] = "7B2272656C61793031223A302C2272656C61793032223A312C2272656C61793033223A302C2272656C61793034223A307D";


    /* create space for the final message */
    char message[100];
    memset(message, 0, sizeof(message));

    /* convert */
    int i;
    char buf = 0;
    for(i = 0; i < strlen(st); i++){
            if(i % 2 != 0){
                    sprintf(message,"%s%c", message, hex_to_ascii(buf, st[i]));
            }else{
                    buf = st[i];
            }
    }

    printf("\r\n|%s|\r\n", message);
 
 while(1);
 return 0;
}

// End Of File