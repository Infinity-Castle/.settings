#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    __pid_t pid=fork();

    if(pid<0){
        perror("error");
        return 1;
    } else if(pid==0){
        // child

        execl("/bin/google-chrome-stable","chrome",(char *)NULL);
        
    } else {
        // parent
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
    return 0;
}