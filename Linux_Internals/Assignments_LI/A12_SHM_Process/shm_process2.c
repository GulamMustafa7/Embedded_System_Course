
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main()
{
	// Variable declaration
	int shmid, shmid1, len, i;
	char str[100];
	void *shm, *shm1;
	key_t key;

	// Key for the shared memory segment
	key = 'A';

	// Create a shared memory segment
	shmid = shmget(key, 100, IPC_CREAT | 0664);
	if(shmid < 0)
	{
		perror("shmget");
		exit(1);
	}

	// Attach the shared memory segment
	shm = shmat(shmid, NULL, 0);
	if(shm < 0)
	{
		perror("shmat");
		exit(1);
	}
	else
		printf("Received the string successfully:%s\n",(char*)shm);

	// Cast the shared memory pointer to char* before using it as a string
	char* shm_char = (char*)shm;

	// Reverse the string
	len = strlen(shm_char);
	for(i = 0; i < len/2; i++)
	{
		char temp = shm_char[i];
		shm_char[i] = shm_char[len - i - 1];
		shm_char[len - i - 1] = temp;
	}

	//printf("Reading reversed string from shared memory = %s\n", (char*)shm);

	key = 'B';

	// Create another shared memory segment
	shmid1 = shmget(key, 100, IPC_CREAT | 0666);
	if(shmid1 < 0)
	{
		perror("shmget");
		exit(1);
	}
	else
	{
		printf("Writing to shared memory..successfully\n");
		shm1 = shmat(shmid1, NULL, 0);

		// Copy the reversed string into a local variable
		strcpy(str, (char*)shm);

		// Write the reversed string into the second shared memory segment
		strcpy(shm1, str);
		shmdt(shm);
		shmdt(shm1);
	}
	return 0;
}
