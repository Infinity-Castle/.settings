#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    int i;
    pid_t pid;

    // Loop to create 5 child processes
    for (i = 0; i < 5; i++) {
        pid = fork(); // Create a child process
        if (pid < 0) { // Error occurred
            perror("fork");
            return 1;
        } else if (pid == 0) { // Child process
            switch (i) {
                case 0:
                    execl("/bin/echo", "echo", "I am printing my process ID.", NULL);
                    break;
                case 1:
                    execl("/bin/echo", "echo", "I am printing my parent process ID.", NULL);
                    break;
                case 2:
                    execl("/bin/echo", "echo", "I am printing my user ID.", NULL);
                    break;
                case 3:
                    execl("/bin/echo", "echo", "I am printing my group ID.", NULL);
                    break;
                case 4:
                    execl("/bin/date", "date", NULL);
                    break;
                default:
                    break;
            }
            return 0; // Child process should exit after execl
        }
    }

    // Wait for all child processes to terminate
    for (i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
