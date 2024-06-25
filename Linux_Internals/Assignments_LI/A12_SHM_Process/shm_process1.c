//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         01/05/2024
 * Description:  Implement communication between two different processes using SHM.
 * 
 * Sample output :
 *
 * Run the two process executable in two different tabs 
 * 1. ./Process1 
 *     Enter the string: Hello
 *     Writing to shared memory ......
 *     Reading from shared memory:  OLLEH
 *
 * 2. ./Process 2
 *     Reading from shared memory :olleh
 *     Writing to Shared memory ...
 */

//########################################################################################//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() 
{
	// Variable declaration
	int shmid, shmid1;
	char str[100];
	void *shm, *shm1;
	key_t key, key1;

	// Key for the shared memory segment
	key = 'A';

	// Create a shared memory segment
	shmid = shmget(key, 100, IPC_CREAT | 0664);
	if(shmid < 0) 
	{
		perror("shmget");
		exit(1);
	}
	else 
	{
		// Attach the shared memory segment
		shm = shmat(shmid, NULL, 0);

		// Read string from user
		printf("Enter the string : ");
		scanf("%s", str);

		// Convert string to uppercase
		for(int i = 0; str[i] != '\0'; i++) 
		{
			if(str[i] >= 'a' && str[i] <= 'z') 
			{
				str[i] = str[i] - 32;
			}
		}
		printf("Writing to shared memory = %s\n", str);

		// Write into shared memory
		strcpy(shm, str);
	}

	// Wait for 5 seconds
	sleep(8);

	// Key for the second shared memory segment
	key1 = 'B';

	// Create another shared memory segment
	shmid1 = shmget(key1, 100, IPC_CREAT | 0666);
	if(shmid1 < 0) 
	{
		perror("shmget");
		exit(1);
	}

	// Attach the second shared memory segment
	shm1 = shmat(shmid1, NULL, 0);
	if(shm1 < 0) 
	{
		perror("shmat");
		exit(1);
	}
	else 
	{
		// Print received string from shared memory
		printf("Reading from shared memory successfully\n");
		printf("%s\n", (char*)shm1);
		shmdt(shm);
		shmdt(shm1);
	}
	return 0;
}

