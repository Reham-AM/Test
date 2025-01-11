#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "initialize.h"
#include "execute.h"

#define MAX_LINE_LENGTH 512

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];

    initialize();

    if (argc == 1) {
        while (1) {
            printf("shell> ");
            if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
                printf("\nExiting shell.\n");
                break;
            }
            line[strcspn(line, "\n")] = 0;
            if (strcmp(line, "quit") == 0) {
                break;
            }
            if (strlen(line) >= MAX_LINE_LENGTH - 1) {
                fprintf(stderr, "Error: Command too long.\n");
                continue;
            }
            execute(line);
        }
    } else if (argc == 2) {
        FILE *batch_file = fopen(argv[1], "r");
        if (batch_file == NULL) {
            fprintf(stderr, "Error opening file '%s': %s\n", argv[1], strerror(errno));
            return EXIT_FAILURE;
        }

        while (fgets(line, MAX_LINE_LENGTH, batch_file) != NULL) {
            line[strcspn(line, "\n")] = 0;
            printf("%s\n", line);
            if (strcmp(line, "quit") == 0) {
                break;
            }
            execute(line);
        }
        fclose(batch_file);
    } else {
        fprintf(stderr, "Usage: %s [batchFile]\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
