//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         01/05/2024
 * Description:  Program to Implement communication between three processes using PIPE, FIFO and SHM.

 * Process1 : 
 * 1.Prompt the user to enter a string 
 * 2.Write the string in pipe 
 * 3.Read the string from pipe into child process
 * 4.Convert the string into Upper case
 * 5.Write the Upper case string  in shared memory
 */

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd[2], status,j=0;
	char str[100];
	char rd[100];
	char rec[100];
	int shmid = shmget(0xA, 100, IPC_CREAT | 0666);

	if (shmid == -1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	char *ptr = shmat(shmid, NULL, 0);
	if (ptr == (void *) -1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	pipe(fd);
	int pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			close(fd[1]);
			read(fd[0], rd, sizeof(str));
			while(j <= sizeof(str))
			{
				rd[j] = (toupper(rd[j]));
				j++;
			}
			strcpy(ptr, rd);
			printf("data written to SHM -> %s\n",ptr);
			break;
		default:
			close(fd[0]);
			printf("Enter the string : ");
			scanf("%s",str);
			write(fd[1], str, sizeof(str));
			wait(&status);
			mkfifo("myfifo", 0666);
			int fd_fifo = open("myfifo", O_RDONLY);
			if(fd_fifo == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			read(fd_fifo, rec, sizeof(str));
			printf("data from FIFO -> %s\n",rec);
			shmctl(shmid, IPC_RMID, NULL);
			shmdt(ptr);
	}
	return 0;
}
