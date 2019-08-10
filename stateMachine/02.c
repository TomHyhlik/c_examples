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
void* state_00();
void* state_01();
void* state_02();

///////////////////////////////////////////////
void* state_00() {
    printf("%s\n", __func__);
    return state_01;   // next state
}
void* state_01() {
    printf("%s\n", __func__);
    return state_02;   // next state
}
void* state_02() {
    printf("%s\n", __func__);
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
       statefunc = (StateFunc)(*statefunc)();
    }

    return 0;
}
///////////////////////////////////////////////
