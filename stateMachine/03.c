/*  State machine
 *  Implementation without global function pointer,
 *  state function returns pointer to the next state function.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef void *(*StateFunc)();


/* states */
void* state_00(char* data);
void* state_01(char* data);
void* state_02();
void* state_03(int val);


///////////////////////////////////////////////
void* state_00(char* data) {
    printf("%s, data: %s\n", __func__, data);
    return state_01("param_1");   // next state
}
void* state_01(char* data) {
    printf("%s, data: %s\n", __func__, data);
    if (strcmp(data, "finish") == 0){
        return state_03(256);
    } else {
        return state_02();
    }
}
void* state_02() {
    printf("%s, data: THIS FUNCTION HAS NO PARAMETERS"
        " AND I USE CAPSLOCK LIKE SPD FAN.\n", __func__);
    return state_01("finish");       
}
void* state_03(int val){
    printf("%s, data: (int) %d\n", __func__, val);
    return NULL;
}

///////////////////////////////////////////////
int main() 
{
    StateFunc statefunc;
    // or without typedef:
    // void* (*statefunc)();

    statefunc = state_00;

    while(statefunc != NULL) {
       statefunc = (StateFunc)(*statefunc)("param_0");
    }

    return 0;
}
///////////////////////////////////////////////
