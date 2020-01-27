/*  State machine
 *  Implementation with global function pointer.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

void (*statefunc)(); // state function pointer

/* states */
void state_00();
void state_01();
void state_02();

///////////////////////////////////////////////
void state_00() {
    printf("%s\n", __func__);
    statefunc = state_01;   // next state
}

void state_01() {
    printf("%s\n", __func__);
    statefunc = state_02;   // next state
}

void state_02() {
    printf("%s\n", __func__);
    statefunc = NULL;       
}

///////////////////////////////////////////////
int main() 
{
    statefunc = state_00;

    while(statefunc != NULL){
        (*statefunc)();
    }

    return 0;
}
///////////////////////////////////////////////