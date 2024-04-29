#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[20];

    // Open a file
    fd = open("test.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Lock the file
    printf("Attempting to lock the file...\n");
    if (lockf(fd, F_RDLCK, 0) == -1) {
        perror("lockf");
        exit(EXIT_FAILURE);
    }
    printf("File locked successfully.\n");

    // Write to the file
    printf("Writing to the file...\n");
    if (write(fd, "Hello, lockf!", 13) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Unlock the file
    printf("Unlocking the file...\n");
    if (lockf(fd, F_UNLCK, 0) == -1) {
        perror("lockf");
        exit(EXIT_FAILURE);
    }
    printf("File unlocked.\n");

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}

