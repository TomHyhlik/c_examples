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
void* state_00(int);
void* state_01(int);
void* state_02(int);


///////////////////////////////////////////////
void* state_00(int val) {
    printf("state: %s, ctr: %d\n", __func__, val);
    return state_01;   // next state
}

void* state_01(int val) {
    printf("state: %s, ctr: %d\n", __func__, val);
    return state_02;   // next state
}

void* state_02(int val) {
    printf("state: %s, ctr: %d\n", __func__, val);
    if (val > 10) {
        return NULL;   
    } else {
        return state_01;
    }    
}

///////////////////////////////////////////////
int main() 
{
    StateFunc statefunc;
    // or without typedef:
    // void* (*statefunc)();

    statefunc = state_00;

    int ctr = 0;

    while(statefunc != NULL) {
       statefunc = (StateFunc)(*statefunc)(ctr);
       ctr++;
    }

    return 0;
}
///////////////////////////////////////////////
