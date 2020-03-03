#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef void (* funcPtr)();
typedef funcPtr (* StateFunc)(int *, bool *);


StateFunc currentState;

//////////////////////////// DEFINED STATES
static funcPtr state_04(int *cmd, bool *ok) 
{
        printf("State \t%s\tcmd: %d\n", __func__,*cmd); 
        *ok = true;
        return (funcPtr)NULL; 
}

static funcPtr state_03(int *cmd, bool *ok) 
{
        printf("State \t%s\tcmd: %d\n", __func__,*cmd); 
        *ok = false;
        return (funcPtr)state_04; 
}

static funcPtr state_02(int *cmd, bool *ok) 
{
        printf("State \t%s\tcmd: %d\n", __func__,*cmd); 
        *ok = true;
        return (funcPtr)state_03; 
}

static funcPtr state_01(int *cmd, bool *ok) 
{
        printf("State \t%s\tcmd: %d\n", __func__,*cmd); 
        *ok = true;
        return (funcPtr)state_02; 
}

//////////////////////////////////////////////////////
void rxHandler(int *cmd) 
{
    if (currentState != NULL) {
        bool success = false;
        currentState = (StateFunc) currentState(cmd, &success);
        if (!success) {
            printf("Failed to handle command: %d\n", *cmd);
            currentState = NULL;
        } 
    } else {
        printf("Null state\n");
    }
}

//////////////////////////////////////////////////////
int main()
{
    printf("AppStart...............\n");

    currentState = (StateFunc) state_01;   // starting state

    /* simulate a few received commands */
    for (int i = 0; i < 8; i++) 
        rxHandler(&i);

    printf("AppEnd...............\n");
    return 0;
}
//////////////////////////////////////////////////////


