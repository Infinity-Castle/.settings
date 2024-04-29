#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

int main(int argc, char *argv[]) {
    FILE *file;
    char line[256];
    int line_count = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL && line_count < MAX_LINES) {
        printf("%s", line);
        line_count++;
    }

    fclose(file);
    return 0;
}