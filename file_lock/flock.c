#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock fl;

    // Open a file
    fd = open("test.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Lock the file
    printf("Attempting to lock the file...\n");
    fl.l_type = F_WRLCK;   // Exclusive write lock
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;           // Lock entire file
    fl.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("File locked successfully.\n");

    // Write to the file
    printf("Writing to the file...\n");
    if (write(fd, "Hello, flock!", 13) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Unlock the file
    printf("Unlocking the file...\n");
    fl.l_type = F_UNLCK;   // Unlock
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
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



// can we lock specific part of the file as well? as we are providing start and end
// and
// what is fcntl?
// ChatGPT
// Yes, with fcntl you can lock specific parts of a file. The struct flock used with fcntl allows you to specify the range of bytes to lock within the file. By setting l_start and l_len fields appropriately, you can lock a specific part of the file.

// Regarding fcntl, it stands for "file control" and is a system call in Unix-like operating systems for performing various operations on open files. It provides a wide range of functionalities, including file locking (F_SETLK), file status flags (F_GETFL, F_SETFL), advisory record locking (F_SETLKW), and more. In the context of file locking, fcntl allows finer control over file locks compared to flock, enabling operations such as locking specific regions of a file, changing or retrieving file status flags, and blocking until a lock can be acquired.