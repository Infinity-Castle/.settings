#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

struct stat data;

int main(){
    char filename[100];

    printf("Enter file/directory name (including path): ");
    scanf("%s", filename);

    if(stat(filename,&data)<0){
        perror("error");
        exit(EXIT_FAILURE);
    }

    printf("File statistics for: %s\n", filename);
    printf("Inode number: %ld\n", data.st_ino); // Inode number
    printf("UID: %d\n", data.st_uid); // User ID of owner
    printf("GID: %d\n", data.st_gid); // Group ID of owner
    printf("File access permissions: %o\n", data.st_mode & 0777); // File access permissions

    // filetype
    if(S_ISREG(data.st_mode)){}
    if(S_ISDIR(data.st_mode)){}
    if(S_ISLNK(data.st_mode)){}
}