#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void alarmHandler(int signum){
    printf("\n5 seconds are over\n");
    exit(1);
}

int main(){
    char name[10];
    signal(SIGALRM,alarmHandler);
    printf("Enter your name:");
    alarm(5);

    fgets(name,10,stdin);

    alarm(0);
    printf("your name: %s",name);
    return 0;
}