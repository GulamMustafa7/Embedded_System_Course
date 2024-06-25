//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         01/05/2024
 * Description:  Program to avoid child becoming zombie without blocking parent.
 * Sample execution:
 *  ./nonblock_wait
 *  A child created with pid 1234
 *  parent is running
 *  parent is running
 *  parent is running . .
 *  ............................
 *  Child 1234 terminated normally with exit status 0 parent terminating
 */

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
	pid_t pid;

	pid = fork();

	if (pid < 0) 
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} 
	else if (pid == 0) 
	{ // Child process
		sleep(2); // Simulate some work
		exit(EXIT_SUCCESS);
	} 
	else 
	{ // Parent process
		printf("A child created with PID %d\n", pid);

		while (1) 
		{
			printf("Parent is running\n");
			sleep(1);

			// Check if the child has terminated
			int status;
			pid_t result = waitpid(pid, &status, WNOHANG);
			
			if (result == -1) 

			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			} 
			else if (result == 0) 
			{
				// Child is still running
				continue;
			} 
			else if (WIFEXITED(status)) 
			{
				printf(". . . . . . . . . . . . . . .\n");
				printf("Child %d terminated normally with exit status %d\n", pid, WEXITSTATUS(status));
				break; // Exit the loop
			}
		}
	}

	printf("Parent terminating\n");
	return 0;
}
