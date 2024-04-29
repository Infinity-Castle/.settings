#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main(){
    int shmid;
    char* shmaddr;
    char input[100];

    // create shared memory
    shmid=shmget(IPC_PRIVATE,SHM_SIZE,IPC_CREAT | 0666);

    // attach shared memory to process's address space
    shmaddr=shmat(shmid,NULL,0);

    pid_t pid=fork();

    if(pid<0){
        printf("Error");
    } else if(pid==0){
        printf("Child");

        // wait until parent writes something to it
        while(*shmaddr=='\0'){
            sleep(1);
        }

        printf("Received input: %s\n",shmaddr);

        exit(0);
    } else {
        printf("Parent process");
        fgets(input,sizeof(input),stdin);

        sprintf(shmaddr,"%s",input);

        wait(NULL);

        // detach shared memory from parent proccess
        shmdt(shmaddr);

        // remove the shared memory segement
        shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}