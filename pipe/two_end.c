#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024
#define FIFO_NAME "/tmp/my_fifo"

int main() {
    char buffer[MAX_BUF];
    int fd;

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_NAME, 0666);

    // Process 1: Write to the named pipe
    printf("Process 1: Writing to the named pipe...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    strcpy(buffer, "Hello from Process 1!");
    write(fd, buffer, strlen(buffer) + 1);
    close(fd);

    // Process 2: Read from the named pipe
    printf("Process 2: Reading from the named pipe...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    memset(buffer, 0, MAX_BUF);
    read(fd, buffer, MAX_BUF);
    printf("Process 2: Received message: %s\n", buffer);
    close(fd);

    // Clean up the FIFO (named pipe)
    unlink(FIFO_NAME);

    return 0;
}