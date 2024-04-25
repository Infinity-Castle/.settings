#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int maxlen=10;
    char name[maxlen];
    char pass[maxlen];

    __pid_t pid=vfork();

    if(pid<0){
        perror("error");
        return 1;
    } else if(pid==0){
        // child

        printf("Enter your name:");
        fgets(name,maxlen,stdin);
        exit(EXIT_SUCCESS);
    } else {
        // parent
        printf("Enter your pass:");
        fgets(pass,maxlen,stdin);
        exit(EXIT_SUCCESS);
    }
    return 0;
}