#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "execute.h"

#define MAX_COMMANDS 10

void execute(char *line) {
    char *commands[MAX_COMMANDS];
    int i = 0;

    char *token = strtok(line, ";");
    while (token != NULL && i < MAX_COMMANDS) {
        commands[i++] = token;
        token = strtok(NULL, ";");
    }
    commands[i] = NULL;

    for (int j = 0; j < i; j++) {
        pid_t pid = fork();
        if (pid == 0) {
            char *args[MAX_COMMANDS];
            char *arg = strtok(commands[j], " \t\n");
            int k = 0;
            while (arg != NULL && k < MAX_COMMANDS) {
                args[k++] = arg;
                arg = strtok(NULL, " \t\n");
            }
            args[k] = NULL;

            if (args[0] != NULL) {
                if (execvp(args[0], args) == -1) {
                    fprintf(stderr, "Error executing '%s': %s\n", args[0], strerror(errno));
                    exit(EXIT_FAILURE);
                }
            }
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            perror("Fork failed");
        }
    }
}
