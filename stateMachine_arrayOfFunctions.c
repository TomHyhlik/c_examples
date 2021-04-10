/*  State machine
 *  Implementation with global function pointer.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


/* Private functions ---------------------------------------------------------*/
int EntryState(int state);

int state_00_Entry();
int state_01_Entry();
int state_02_Entry();

int state_00_Do();
int state_01_Do();
int state_02_Do();


/* Private types -------------------------------------------------------------*/
typedef int (*fPtr) (void);

typedef struct 
{
    uint32_t currentStateId;
    uint32_t currentStateDoCtr;
} 
SM_Parameters;
   
/* Private constants ---------------------------------------------------------*/

#define NUMBEROFSTATES      3

#define PRINT_STATE_DO           printf("State DO: %s, ctr: %d\n", __func__, sm.currentStateDoCtr)
#define PRINT_STATE_ENTRY        printf("*** %s\n", __func__)

enum {
    STATE_00,
    STATE_01,
    STATE_02,
};

fPtr StateEntry[NUMBEROFSTATES] = 
{
    &state_00_Entry, 
    &state_01_Entry, 
    &state_02_Entry
};

fPtr StateDo[NUMBEROFSTATES] = 
{
    &state_00_Do, 
    &state_01_Do, 
    &state_02_Do
};

const int StateTransit_execCount[NUMBEROFSTATES] = 
{
    2,
    4,
    6
};

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
SM_Parameters sm;

///////////////////////////////////////////////
int EntryState(int state)
{
    int ret = 0;
    if (state < 0 || state >= NUMBEROFSTATES || StateEntry[state] == NULL)
    {
        printf("ERROR: %s() Invalid stgate ID: %d\n", __func__, state);
        return -1;
    }

    /* Init SM parameters */
    sm.currentStateDoCtr = 0;
    sm.currentStateId = state;
    /* Execute current state entry to initialize the system */
    ret |= StateEntry[state]();
    return ret;
}

///////////////////////////////////////////////
int DoState()
{
    int ret = 0;
    sm.currentStateDoCtr++;

    if (sm.currentStateId < 0 || 
        sm.currentStateId >= NUMBEROFSTATES || 
        StateDo[sm.currentStateId] == NULL)
    {
        printf("ERROR: Invalid state ID in func: %s\n", __func__);
        return -1;
    }

    ret |= StateDo[sm.currentStateId]();

    return ret;
}

///////////////////////////////////////////////
int state_00_Entry() 
{
    PRINT_STATE_ENTRY;
    return 0;
}

int state_01_Entry() 
{
    PRINT_STATE_ENTRY;
    return 0;
}

int state_02_Entry() 
{
    PRINT_STATE_ENTRY;
    return 0;       
}

///////////////////////////////////////////////
int state_00_Do() 
{
    PRINT_STATE_DO;

    if (sm.currentStateDoCtr >= StateTransit_execCount[sm.currentStateId])
    {
        return EntryState(STATE_01);
    }
    return 0;
}

int state_01_Do() 
{
    PRINT_STATE_DO;
    
    if (sm.currentStateDoCtr >= StateTransit_execCount[sm.currentStateId])
    {
        return EntryState(STATE_02);
    }
    return 0;
}

int state_02_Do() 
{
    PRINT_STATE_DO;

    if (sm.currentStateDoCtr >= StateTransit_execCount[sm.currentStateId])
    {
        printf("SM_STOP\n");
        // return EntryState(10); // generate error
        while(1);
    }
    return 0;
}

///////////////////////////////////////////////
int main() 
{
    printf("AppStart_______________________________\n");

    /* Init SM to some state */
    EntryState(STATE_00);

    /* Start SM */
    while (DoState() == 0);

    printf("AppEnd_________________________________\n");
    return 0;
}
///////////////////////////////////////////////