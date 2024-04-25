#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void childSignalHandler(int sig){
    if(sig==SIGUSR1){
        printf("received signal from parent\n");
    }
}

void parentSignalHandler(int sig){
    if(sig==SIGUSR2){
        printf("received signal from child\n");
    }
}
int main(){
    __pid_t pid=fork();

    if(pid==-1){
        perror("error occured");
        exit(EXIT_FAILURE);
    } else if(pid==0){
        // child

        signal(SIGUSR1,childSignalHandler);

        printf("child process started\n");

        kill(getppid(),SIGUSR2);
    } else {
        signal(SIGUSR2,parentSignalHandler);

        // wait sys call waits for the parent process to be completed
        // where as pause waits until a signal is received from the parent proccess

        pause();
        kill(pid,SIGUSR1);
    }
}