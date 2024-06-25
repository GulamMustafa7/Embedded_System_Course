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
#include <string.h>

// Function to concatenate two strings
void my_strcat(char *dest, const char *src)
{
    // Find the end of the destination string
    while (*dest != '\0')
	{
        dest++;
    }
    // Copy the source string to the end of the destination string
    while (*src != '\0')
	{
        *dest = *src;
        dest++;
        src++;
    }
    // Null-terminate the concatenated string
    *dest = '\0';
}

int main()
{
    char str1[50];
    char str2[50];

    // Read the first string from the user
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Read the second string from the user
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Concatenate str2 to str1
    my_strcat(str1, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", str1);

    return 0;
}
