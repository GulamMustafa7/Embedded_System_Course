//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         30/04/2024
 * Description:  Implement communication between three related processes using two pipe.
 * Sample execution:
 *  ./three_pipes (No arguments)
 *  Error: No arguments passed Usage: ./three_pipes  <command1 > '|'   <command2> '|'  <command3 >
 *  2. ./pipe ls ­l '|' grep 
 *  Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2> '|'  <command3 >
 *  3. ./pipe ls -­l '|' grep “pattern” '|' wc -­l
 *  5 5 25
 */

//########################################################################################//

#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) 
{
	int i, count = 0;
	char *commands[3];
	pid_t pid; 

	if (argc <= 1) //checking the arguments are passed or not
	{
		printf("Error: No arguments passed Usage: ./three_pipes  <command1 > '|'   <command2> '|'  <command3 >\n");
		return 1;
	}

	// Loop arguments to separate commands and store them
	for (i = 1; i < argc; i++) 
	{
		if (strcmp(argv[i], "|") == 0) 
		{
			break;
		}
		commands[count++] = argv[i];
	}

	// Check if sufficient commands are provided
	if (count == 0 || i == argc - 1) 
	{
		printf("Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2> '|'  <command3 >\n");
		return 1;
	}


	int pipes[2][2]; // Array to hold pipe file descriptors

	// Create pipes
	for (i = 0; i < 2; i++) 
	{
		if (pipe(pipes[i]) == -1) 
		{
			perror("Pipe creation failed");
			exit(1);
		}
	}

	// Execute commands in the pipeline
	for (i = 0; i <= 2; i++) 
	{
		pid = fork();

		if (pid == -1) 
		{
			perror("Fork");
			exit(1);
		} 
		else if (pid == 0) 
		{   // Child process
			// Redirect input if not the first command
			if (i != 0) 
			{
				dup2(pipes[i - 1][0], STDIN_FILENO);
				close(pipes[i - 1][0]);
			}

			// Redirect output if not the last command
			if (i != 2) 
			{
				dup2(pipes[i][1], STDOUT_FILENO);
				close(pipes[i][1]);
			}

			// Execute the command
			char *args[3];
			int j;
			for (j = 0; j < count; j++) 
			{
				args[j] = commands[j];
			}
			args[j] = NULL;
			execvp(args[0], args);
			perror("Execution failed");
			exit(1);
		}
	}

	// Close all pipe ends in the parent process
	for (i = 0; i < 2; i++) 
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}

	// Wait for all child processes to complete
	for (i = 0; i <= 2; i++) 
	{
		wait(NULL);
	}

	return 0;
}
