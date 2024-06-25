//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         01/05/2024
 * Description:  Program to implement 'n' pipes to execute 'n+1' commands.

 * Sample execution: 
 * 1../pipe (No arguments)
 *   Error: No arguments passed,Provide atleast one pipe  or more
 *   Usage: ./pipe <command1> '|' <command2>
 *   Usage: ./pipe <command1> '|' <command2> '|' <command3> etc
 * 2../pipe ls '|' wc
 *   5 25 4
 * 3. ./pipe ls -­l '|' grep “pattern” '|' wc -­l 
 *   5 5 25
 */

//########################################################################################//

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int pipe_no = 0, index = 0, pid, status, cpid, j = 1, k = 0;
	int arr[10];
	int fd[2];

	for (int i = 1 ; i < argc ; i++)
	{
		if (!strcmp("|", argv[i]))
		{
			pipe_no++;
			argv[i] = NULL;
			arr[index++] = i;
		}
	}
	if (!pipe_no)
	{
		printf("ERROR : Invalid Usage\n");
		printf("Usage : <cmd1> '|' <cmd2> '|' ... <cmdn>\n");
	}

	dup2(1, 5);
	for (int i = 0 ; i <= pipe_no ; i++)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			if (i == pipe_no)
			{
				dup2(5, 1);
			}
			else
			{
				dup2(fd[1], 1);
			}
			execvp(argv[j], argv + j);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], 0);
			j = 1 + arr[k++];
			cpid = wait(&status);
		}
	}
	return 0;
}
