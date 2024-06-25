/*
* Name : GulamMustafa I. Kazi.
* Date : 20/04/2024
* Description : C program to understand usage of dup and dup2 system calls.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // Added for close() function

int main() 
{
    int option;
    printf("1. dup\n2. dup2\n");
    scanf("%d", &option);

    int fd = open("f1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666); // Changed O_WRONLY to write mode, added O_CREAT and O_TRUNC flags
    if (fd == -1) {
        perror("open");
        return -1;
    }
    int stdout_fp=dup(1);

    switch (option) { // Removed & from &option
        /case 1:
         /  
            close(1); // Closing stdout
         
            dup(fd); // Duplicating fd to stdout
            printf("This will be printed in f1.txt\n");
            close(fd); // Closing fd
            close(1);
            dup(stdout_fp);
            printf("This will be printed in stdout\n");
            break;
        case 2:
            close(1); // Closing stdout
            dup2(fd, 1); // Duplicating fd to stdout using dup2
            printf("This will be printed in f1.txt\n");
            dup2(stdout_fp,1);
            printf("This will be printed in stdout\n");
            break;
        default: // Added default case
            printf("Invalid option.\n");
            close(fd); // Closing fd
            return -1;
    }

    return 0;
}
 


