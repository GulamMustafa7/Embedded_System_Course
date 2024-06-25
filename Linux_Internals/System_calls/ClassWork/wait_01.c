//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:
* Description:
* Sample input:
* Sample output:
*/

//########################################################################################//

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
	pid_t pid = fork();

	if (pid > 0)    // Parent
	{
		printf("This is parent process\n");

		int status;		// To collect the exit states of child.
		pid_t ret = wait(&status);  // wait() returns child pid.

		/* WIFEXITED(wstatus) -> returns  true  if  the  child  terminated  normally*/
		if (WIFEXITED(status))
			printf("child %d terminated normally with exit code %d\n", ret, WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally with exit code %d\n", ret, status);
	}
	else if (pid == 0)		// Child 
	{
		printf("This is child process with pid %d\n", getpid());

		sleep(10);

		printf("child is teminating\n");
	}
}

