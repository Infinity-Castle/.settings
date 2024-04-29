#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define SEM_NAME "/my_semaphore"

int main() {
    sem_t *semaphore;
    pid_t pid;

    // Create a new semaphore
    semaphore = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process started\n");

        // Wait for semaphore to be available
        sem_wait(semaphore);
        printf("Child process acquired semaphore\n");

        // Simulate some work
        sleep(2);

        printf("Child process releasing semaphore\n");
        sem_post(semaphore);
        printf("Child process finished\n");
    } else {
        // Parent process
        printf("Parent process started\n");

        // Wait for semaphore to be available
        sem_wait(semaphore);
        printf("Parent process acquired semaphore\n");

        // Simulate some work
        sleep(2);

        printf("Parent process releasing semaphore\n");
        sem_post(semaphore);
        printf("Parent process finished\n");

        // Wait for child process to finish
        waitpid(pid, NULL, 0);
    }

    // Clean up the semaphore
    sem_close(semaphore);
    sem_unlink(SEM_NAME);

    return 0;
}


// Difference between sem.h and semaphore.h:

// sem.h is a header file provided by the POSIX.1 standard, which defines functions for creating and managing unnamed semaphores. Unnamed semaphores are identified by memory addresses and can only be shared between processes within the same program.
// semaphore.h is a header file introduced in the POSIX.1b standard, which defines functions for creating and managing named semaphores. Named semaphores are identified by a string name and can be shared between processes across different programs on the same system.