#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 0x1234

union semun {
    int val;
    struct semid_ds *buf;
};

int main() {
    int semid;
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

    printf("Semaphore initialized with ID: %d\n", semid);

    return 0;
}