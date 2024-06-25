//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:         01/05/2024
* Description:  Program to create child process to execute command passed through command line.
* Sample execution: -
* 	1. No args passed (Print usage info)
* 	./exe_child Usage: ./exe_child args...
* 	2. Valid arg. passed
* 	./exe_child date
* 	This is the CHILD process, with id 11612
* 	Wed Apr  4 13:27:19 IST 2012
* 	Child exited with status 0
*/

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
	if (argc < 2) 
	{
		printf("Please pass command in argument\n");
		printf("Usage: %s command\n", argv[0]);
		return 1;
	}

	// Fork a child process
	pid_t pid = fork();

	if (pid == 0) 
	{  // Child process
		printf("This is the CHILD process, with id %d\n", getpid());

		// Execute the command passed as argument
		execvp(argv[1], &argv[1]);

		// If execvp returns, it means an error occurred
		perror("execvp");
		exit(1);
	}
	else if (pid < 0) 
	{ // Fork failed
		perror("fork");
		return 1;
	} 
	else 
	{ // Parent process
		int status;

		// Wait for child to terminate
		 waitpid(pid, &status, 0);
		printf("Child exited with status %d\n", WEXITSTATUS(status));

	}

	return 0;
}
