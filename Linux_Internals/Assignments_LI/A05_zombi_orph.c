/*
* Name : GulamMustafa I. Kazi.
* Date : 22/04/2024
* Description : C Program to make zombie process become orphan, print status of each state.
*/
#incl/ude <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>    // Include for open
#include <string.h>   // Include for sprintf

void print_process(pid_t pid)
{
    char str[100];
    char buffer;   // Buffer to read one character at a time
    int fd, bytes_read, lines_read;

    sprintf(str, "/proc/%d/status", pid);
    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    lines_read = 0;
    while ((bytes_read = read(fd, &buffer, 1)) > 0)
    {
        // Print the character
        write(STDOUT_FILENO, &buffer, 1);

        // Increment lines_read if the character is a newline
        if (buffer == '\n')
        {
            lines_read++;
            if (lines_read == 3)
            {
                break;  // Stop reading after three lines
            }
      
  	}
    }

    if (bytes_read == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(fd);  // Close the file descriptor
}

int main()
{
    pid_t pid1, pid2;
    pid1 = fork();
    
    if (pid1 < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid1 >  0)
    {
        printf("A child created with PID %d\n", pid1);
        sleep(1);
        print_process(pid1);
        sleep(10);
        printf("Child become Zombie:\n");
        print_process(pid1);
        pid2 = fork();
        
        if (pid2 == 0)
        {
            int ppid = getppid();
            sleep(2);
            
            if (getppid() != ppid) // Check if adopted by init
            {
                printf("Process %d cleared by init\n", getpid());
                exit(EXIT_SUCCESS);
            }
        }

    }
    else
    {
         sleep(5);    / Child process sleeps for some time
    }

    return 0;
}
