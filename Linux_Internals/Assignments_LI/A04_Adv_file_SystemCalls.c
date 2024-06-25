//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         15/05/2024
 * Description:  C program to understand advanced file control system calls.
 *
 * Sample Execution:
 * 1.When no arguments are passed
 *./a.out
 * Insufficient arguments
 * Usage:- ./a.out filename
 *
 * 2. ./a.out f1.txt
 * PARENT PROCESS: locked file
 * PARENT PROCESS: writing to file f1.txt
 * PARENT PROCESS: unlocked file
 * CHILD PROCESS: locked file
 * CHILD PROCESS: writing to file f1.txt
 * CHILD PROCESS: unlocked file
 */

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/types.h>     
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// Check the sufficient aguments passed or note.
	if (argc < 2)
	{
		printf("please pass the valid cla aruguments\n");
		printf("insufficient arguments\n");
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1],O_WRONLY|O_CREAT, 0666);

	if (fd == -1)
	{            
		perror("open");            
		exit(EXIT_FAILURE);        
	}

	// Varible declartion
	pid_t pid;
	struct flock file;

	// Clear the memory
	memset(&file, 0, sizeof(file));

	// Create a new process
	pid = fork();

	// Parent process
	if (pid > 0)
	{
		sleep(2);
		printf("PARENT PROCESS: locked the file\n");

		// lock the file for writing            
		file.l_type = F_WRLCK;
		fcntl(fd, F_SETLKW, &file);
		printf("PARENT PROCESS: writing to file %s\n",argv[1]);                    
		printf("PARENT PROCESS: unlocked the file\n");

		// dup2 condition
		int std_cpy;       
		dup2(std_cpy,1);         
		close(1);                  
		int new_fd = dup2(fd,1); 

		// varible declartion        
		int num = 15, i ,fact ,j;
		printf("\n");

		// prime number condition
		printf("Prime Numbers are: \n");
		for(i = 1; i <= num; i++)
		{
			fact = 0; 
			for(j = 1; j <= num; j++)
			{
				if (i % j == 0)
				{
					fact++;
				}
			}
			if (fact == 2)
			{
				printf("%d ",i);
			}

		}
		printf("\n"); 
		close(fd);

		//UNLOCK THE FILE 
		file.l_type = F_UNLCK;
		fcntl(fd, F_SETLKW, &file);
	}
	else if (pid == 0)
	{

		printf("CHILD PROCESS: locked the file\n");

		// lock the file for writing            
		file.l_type = F_WRLCK;
		fcntl(fd, F_SETLKW, &file);
		printf("CHILD PROCESS: writing to file %s\n",argv[1]);           
		printf("CHILD PROCESS: unlocked the file\n");

		// dup condition        
		int std_cpy;
		dup2(std_cpy,1);         
		close(1);
		int new_fd = dup2(fd,1); 

		// varible declaration       
		int num = 15, f1 = 0, f2 = 1,i ;

		// fibonacci series condition
		if (num >= 0)
		{
			printf("Fibonacci series are: \n");
			printf("%d %d",f1, f2);
			i = f1 + f2;
		}

		while (i <= num)
		{
			printf(" %d",i);
			f1 = f2;
			f2 = i;
			i = f1 + f2;
		}
		close(fd);

		// UNLOCK THE FILE 
		file.l_type = F_UNLCK;
		fcntl(fd, F_SETLKW, &file);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
