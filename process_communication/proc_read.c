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
    // Open the FIFO file for reading
    int fd = open(fifo_file, O_RDONLY);

    char buf[1024];
    int n = read(fd, buf, sizeof(buf));
    printf("Received message: %s\n", buf);

    // Close the FIFO file
    close(fd);

    return 0;
}