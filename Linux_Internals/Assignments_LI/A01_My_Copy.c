/*
*Name : GulamMustafa I. Kazi
*Date : 18/04/2024
*Description : Implement a cp(copy) command with –p option
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 4096

/* Function to copy contents from source_fd to dest_fd */
int my_copy(int source_fd, int dest_fd) 
{
    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    struct stat permissions;

    // Copy contents from source to destination
    while ((bytes_read = read(source_fd, buffer, BUF_SIZE)) > 0) 
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) 
        {
            perror("Write error");
            return 1;
        }
    }

    // If read error
    if (bytes_read < 0) 
    {
        perror("Read error");
        return 1;
    }

    // If -p option is passed, copy permissions
    if (fstat(source_fd, &permissions) == 0) 
    {
        if (fchmod(dest_fd, permissions.st_mode) == -1) 
        {
            perror("Error copying permissions");
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        fprintf(stderr, "Insufficient arguments\nUsage:- %s [option] source_file dest_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source_file = NULL;
    char *dest_file = NULL;
    int option = 0;

    // Check if -p option is passed
    if (strcmp(argv[1], "-p") == 0) 
    {
        option = 1;
        source_file = argv[2];
        dest_file = argv[3];
    } 
    else 
    {
        source_file = argv[1];
        dest_file = argv[2];
    }

    // Open source file for reading
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) 
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing
    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (dest_fd == -1) 
    {
        if (errno == EEXIST) 
        {
            char response;
            printf("File \"%s\" already exists. Do you want to overwrite (Y/n): ", dest_file);
            scanf(" %c", &response);
            if (response != 'Y' && response != 'y') 
            {
                close(source_fd);
                exit(EXIT_SUCCESS);
            }
            dest_fd = open(dest_file, O_WRONLY | O_TRUNC);
            if (dest_fd == -1) 
            {
                perror("Error opening destination file");
                close(source_fd);
                exit(EXIT_FAILURE);
            }
        } 
        else 
        {
            perror("Error opening destination file");
            close(source_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Perform copy operation
    int copy_result = my_copy(source_fd, dest_fd);

    // Close file descriptors
    close(source_fd);
    close(dest_fd);

    if (copy_result == 0) 
    {
        printf("File copied successfully.\n");
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        exit(EXIT_FAILURE);
    }
}

