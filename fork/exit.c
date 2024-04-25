#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    __pid_t pid=fork();
    int status;
    if(pid==-1){
        // error
        perror("error occured");
        exit(EXIT_FAILURE);
    } else if(pid==0){
        printf("child performing heavy tasks\n");
        sleep(5);
    } else {
        __pid_t term_pid=wait(&status);

        if(term_pid==-1){
            perror("error occured");
            exit(EXIT_FAILURE);
        }
    }
    printf("wait success with status %d and pid %d\n",status,getpid());
}