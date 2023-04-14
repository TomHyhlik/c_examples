#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

const char* fifo_file = "/tmp/myfifo";

int main() 
{
    // Create the FIFO file if it doesn't exist
    mkfifo(fifo_file, 0666);

    // Open the FIFO file for writing
    int fd = open(fifo_file, O_WRONLY);

    const char* msg = "Hello, Process B!";
    write(fd, msg, strlen(msg) + 1);

    // Close the FIFO file
    close(fd);

    return 0;
}