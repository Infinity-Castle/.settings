#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signalHandler(int sig) {
    if (sig == SIGUSR1) {
        printf("Received signal from other process!\n");
    }
}

int main(){
   __pid_t pid=getpid();

   if(signal(SIGUSR1,signalHandler)==SIG_ERR){
    perror("error occured");
    return 1;
   }    

   printf("Process 1 PID: %d\n", pid);
    printf("Send signal to this process from another terminal using: kill -SIGUSR1 %d\n", pid);

   while(1){
    sleep(1);
   }
}