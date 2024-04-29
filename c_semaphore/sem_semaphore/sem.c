#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 0x1234

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

int main() {
    int semid;
    pid_t pid;
    union semun sem_val;

    // Create a new semaphore set
    semid = semget(SEMKEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore value
    sem_val.val = 1;
    if (semctl(semid, 0, SETVAL, sem_val) == -1) {
        perror("semctl");
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
        struct sembuf sop = {0, -1, 0};
        if (semop(semid, &sop, 1) == -1) {
            perror("semop");
            exit(1);
        }
        printf("Child process acquired semaphore\n");

        // Do some work
        printf("Child process is working...\n");
        sleep(2);

        printf("Child process releasing semaphore\n");
        sop.sem_op = 1;
        if (semop(semid, &sop, 1) == -1) {
            perror("semop");
            exit(1);
        }
        printf("Child process finished\n");
    } else {
        // Parent process
        printf("Parent process started\n");

        // Wait for semaphore to be available
        struct sembuf sop = {0, -1, 0};
        if (semop(semid, &sop, 1) == -1) {
            perror("semop");
            exit(1);
        }
        printf("Parent process acquired semaphore\n");

        // Do some work
        printf("Parent process is working...\n");
        sleep(2);

        printf("Parent process releasing semaphore\n");
        sop.sem_op = 1;
        if (semop(semid, &sop, 1) == -1) {
            perror("semop");
            exit(1);
        }
        printf("Parent process finished\n");

        // Wait for child process to finish
        waitpid(pid, NULL, 0);
    }

    // Remove the semaphore set
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}