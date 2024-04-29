#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    char input[100];
    FILE *fp1, *fp2;

    // create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory to process's address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process (receiver)
        fp2 = fopen("output.txt", "w");
        if (fp2 == NULL) {
            perror("fopen");
            exit(1);
        }

        // Wait until parent writes something to shared memory
        while (*shmaddr == '\0') {
            sleep(1);
        }

        fprintf(fp2, "Received input: %s\n", shmaddr);
        fclose(fp2);
        exit(0);
    } else {
        // Parent process (sender)
        fp1 = fopen("input.txt", "r");
        if (fp1 == NULL) {
            perror("fopen");
            exit(1);
        }

        while (fgets(input, sizeof(input), fp1) != NULL) {
            sprintf(shmaddr, "%s", input);
            sleep(1); // wait for child to read
        }

        fclose(fp1);
        wait(NULL);

        // detach shared memory from parent process
        if (shmdt(shmaddr) < 0) {
            perror("shmdt");
            exit(1);
        }

        // remove the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) < 0) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}