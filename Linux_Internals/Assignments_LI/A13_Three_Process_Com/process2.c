//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         01/05/2024
 * Description:  Program to implement communication between three processes using PIPE, FIFO and SHM.

 * Process2 :
 * 1.Read the data from the shared memory 
 * 2.Reverse input which is read from SHM
 * 3.Write the Reverse string  in FIFO
 */

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Function to reverse the string */
void strrev(char *str)
{
	char ch;
	int i = 0;
	int j = strlen(str) - 1;
	while(i < j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i++;
		j--;

	}
}

/* Main Function */
int main()
{
	int shmid = shmget(0xA, 100, 0);
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
	char rec[100];
	strcpy(rec, ptr);
	printf("data from SHM -> %s\n",rec);
	strrev(rec);

	printf("Data written to FIFO -> %s\n",rec);

	int fd = open("myfifo", O_WRONLY);

	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd,rec,sizeof(rec));

	return 0;
}
