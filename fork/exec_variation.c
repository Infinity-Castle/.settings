#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    execl("/bin/ls","ls","-l",NULL);

    char *arr[]={"ls","-l",NULL};
    
    char *env[]={"PATH=/bin"};

    execv("/bin/ls",arr);

    execlp("ls",NULL);

    execvp("ls",arr);

    execve("/bin/ls",arr,env);
}