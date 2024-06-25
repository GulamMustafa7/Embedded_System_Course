//########################################################################################//

/*
 * Name:         GulamMustafa Ibrahim Kazi.
 * Date:         05/05/0/2024
 * Description:  C program to concatenate two strings.

 * Sample input:  Enter the string1 : hello

 Enter the string2 : world

 * Sample output: concatenate string is helloworld
 */

//########################################################################################//

#include <stdio.h>

int main()
{
	// Declaring charecter array to store strings.
	char str1[50] = {0};
    char str2[50] = {0};

	int length = 0, j;

	printf("Enter the string1:");
	scanf("%[^\n]", str1);    // Read string1 using selective scanf.

	getchar(); // To clear the input buffer.

	printf("Enter the string2:");
	scanf("%[^\n]", str2);    // Read string2


	// Store length of str1 in the length variable
	while (str1[length] != '\0')
	{
		++length;
	}

	// Concatenate str2 to str1
	for (j = 0; str2[j] != '\0'; ++j)
	{
		str1[length] = str2[j];
		++length;
	}

	// Terminating the str1 string
	str1[length] = '\0';

	printf("concatenate string is %s\n", str1);

	return 0;
}

