#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    __pid_t pid=fork();
    int status;

    if(pid<0){
        perror("error");
        return 1;
    } else if(pid==0){
        // child
        printf("Child process with pid %d and parent %d\n",getpid(),getppid());
        sleep(5); //simulate the work
        exit(EXIT_SUCCESS);
    } else {
        // parent
        printf("parent with pid %d\n",getpid());
        
        __pid_t term_pid=wait(&status);

        if(term_pid<0){
            perror("error while waiting");
            exit(EXIT_FAILURE);
        }
    }
    printf("wait finish with status %d\n",status);
}