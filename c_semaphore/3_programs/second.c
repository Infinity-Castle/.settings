#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEMKEY 0x1234

int main() {
    int semid;
    struct sembuf sop;

    // Get the semaphore ID
    semid = semget(SEMKEY, 1, 0);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Wait for semaphore to be available
    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_flg = 0;
    if (semop(semid, &sop, 1) == -1) {
        perror("semop");
        exit(1);
    }

    printf("P operation performed on the semaphore\n");

    // Release the semaphore
    sop.sem_op = 1;
    if (semop(semid, &sop, 1) == -1) {
        perror("semop");
        exit(1);
    }

    return 0;
}