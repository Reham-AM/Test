#include <stdio.h>
#include <unistd.h>
#include "initialize.h"

#define clear() printf("\033[H\033[J")

void initialize() {
    clear();
    printf("\n\n\n\n******");
    printf("\n\n\tWELCOME TO THE SHELL PROJECT");
    printf("\n\n******");
    printf("\n\tDeveloped by: Group of Statistics & Computer Science Department");
    printf("\n\tUniversity of Khartoum, Faculty of Mathematical Sciences and Informatics");
    printf("\n\n******");
    printf("\n\n\tFeatures Implemented:");
    printf("\n\t- User Command Execution");
    printf("\n\t- Processes Management");
    printf("\n\t- Error Handling");
    printf("\n\t- User-Friendly Interface");
    printf("\n\n******");
    sleep(3);
    clear();
}
