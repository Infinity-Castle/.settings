#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <target_file>\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0) {
        printf("Error renaming file %s to %s\n", argv[1], argv[2]);
        return 1;
    }

    return 0;
}