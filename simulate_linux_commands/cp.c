#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *source, *target;
    char c;

    if (argc != 3) {
        printf("Usage: %s <source_file> <target_file>\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Error opening source file %s\n", argv[1]);
        return 1;
    }

    target = fopen(argv[2], "w");
    if (target == NULL) {
        printf("Error opening target file %s\n", argv[2]);
        fclose(source);
        return 1;
    }

    while ((c = fgetc(source)) != EOF) {
        fputc(c, target);
    }

    fclose(source);
    fclose(target);
    return 0;
}