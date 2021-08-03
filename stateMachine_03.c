#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//////////////////////////////////////////////////////


typedef int (* ExecHandler)();



//////////////////////////////////////////////////////

int ExecHandler_0(void);
int ExecHandler_1(void);
int ExecHandler_2(void);

//////////////////////////////////////////////////////


ExecHandler testHandlers[] =
{
    ExecHandler_0,
    ExecHandler_1,
    ExecHandler_2,
};

//////////////////////////////////////////////////////

int ExecHandler_0(void)
{
    printf("State \t%s\n", __func__); 
    return 0;
}

int ExecHandler_1(void)
{
    printf("State \t%s\n", __func__); 
    return 0;
}

int ExecHandler_2(void)
{
    printf("State \t%s\n", __func__); 
    return 0;
}

//////////////////////////////////////////////////////
int main()
{
    printf("AppStart...............\n");

    /* simulate a few received commands */
    for (int i = 0; i < sizeof(testHandlers)/sizeof(ExecHandler); i++) 
    {
        int ret = testHandlers[i]();
        if (ret != 0) 
        {
            printf("SM exited with code: %d\n", ret);
            break;
        }
    }

    printf("AppEnd...............\n");
    return 0;
}
//////////////////////////////////////////////////////


