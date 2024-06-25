//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         30/04/2024
 * Description:  C program Implement communication between two related processes using one pipe.
 *
 *	Sample execution:
 *	1. ./pipe (No arguments)
 *	Error: No arguments passed
 *	Usage: ./pipe <command 1> | <command 2>
 *	2. ./pipe ls 
 *	Error: Insufficient arguments passed
 *	Usage: ./pipe <command 1> | <command 2>
 *	3. ./pipe ls '|' wc
 *	5 5 25
 *	4. ./pipe ls ­l ­a '|' wc ­l ­w
 *	10 15
 */

//########################################################################################//

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("ERROR : No arguments passed\n");
		printf("USAGE : %s <cmd1> '|' <cmd2>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	int index, pid_1, pid_2, status, pipe_no = 0;
	
	//To check the index of pipe
	for(int i = 1 ; i < argc ; i++)
	{
		if (!strcmp("|",argv[i]))
		{
			pipe_no++;
			index = i;
			argv[i] = NULL;
			break;
		}
	}

	if (pipe_no != 1)
	{
		printf("ERROR : Insufficient arguments passed\n");
		printf("USAGE : %s <cmd1> '|' <cmd2>\n",argv[0]);
	}

	int fd[2];
	pipe(fd);
	pid_1 = fork();
	pid_2 = fork();

	if (pid_2 > 0)
	{
		//Wait for child to terminate
		wait(&status);
	}
	else if (pid_1 == 0)
	{
		//child 1
		dup(1);				//Stdout is duplicated
		close(fd[0]); 		//Read end of pipe is closed
		dup2(fd[1], 1); 	//write end of pipe is coppied to stdin
		execvp(argv[1], argv + 1);//Command is executed

	}
	else if (pid_2 == 0)
	{
		close(fd[1]);		//Write end is closed
		dup2(fd[0], 0); 	//read end of pipe is coppied to stdin
		dup2(5, 1);			// stdout is coppied to 1st index
		execvp(argv[index + 1], argv + index + 1); //command s executed
	}
	return 0;
}
