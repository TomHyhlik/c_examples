#include <stdio.h>
#include <time.h>
#include <stdint.h>

void msleep(uint64_t milliseconds);

//////////////////////////////////////////
int main()
{
    puts("AppStart_______________________");

    for(int i = 0 ; i <= 100 ; i++){
        printf("%d\n", i);
        msleep(100);
    }
    return(0);
}
//////////////////////////////////////////
void msleep(uint64_t milliseconds)
{
    uint64_t pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while ((now-then) < pause)
        now = clock();
}
//////////////////////////////////////////