#include <stdio.h>
#include <time.h>

int main()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    // time(&timer);
    timer = 1000001;
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    return 0;
}