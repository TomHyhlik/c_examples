#include <stdio.h>
union intParts{
  int theInt;
    char bytes[sizeof(int)];
};
int main(void) {
    union intParts parts;
    for(int i = 0 ; i < 3 ; i++){
    parts.bytes[i] = i;    
    } 
    
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);
return 0;
}
