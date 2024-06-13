//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         16/01/2024
Description:  C program to read n & n person names of maxlen 20. Sort and print the names(1st Dynamic & 2nd Static).

Sample input:
Enter the size: 5
Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

Sample output:
The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata
 */

//########################################################################################//

#include<stdio.h>
#include<stdlib.h>

// Function prototypes :
void sort_array( char (*ptr)[20], int size);
int my_strcmp( char *str1, char *str2);
void my_swap(char *arr1, char *arr2, int len);

int main()
{
    // Declaration of variables.
    int i, j, num, len = 0, count = 0;

    char (*name)[20];    // 20 bytes of static memory allocation for each name.

    printf("Enter number of words : ");
    scanf("%d", &num);    // Read no.of.words from user 

    printf("Enter the %d names of length max 20 caharacters in each\n", num);

    name = malloc(num * sizeof(*name));    // Dynamic memory allocation for name.

    printf("%ld\n",sizeof(*name));
    for(i = 0; i < num; i++)
    {
	len = 0;    // Seting len to zero.
	printf("[%d] -> ",i);
	scanf("%s",name[i]);	// Read a name from user

	for (j = 0; *(*(name+i)+j) != '\0'; j++)
	{
	    len++;    // Count the length of string(name).
	}

	if (len >= 20)   // Checking length of string is within 20bytes or not.
	{
	    printf("Error : please enter name with only 20 characters including null character \n"); 
	    count = 1;
	    break;
	}
    }

    if (count != 1)
    {
	sort_array(name,num);	// Function call for sort array.

	printf("\nThe Sorted names are:\n");
	for (i = 0; i < num; i++)
	{
	    printf("[%d] -> ", i);
	    printf("%s \n", name[i]);	// Print the names in alphabetical order.
	}
    }

    free (name);    // Free the poiner.
    name = NULL;

    return 0;
}

/* Function definition of sort array function :
 * Input : pointer of array of 20bytes, number of names.
 * Output : Sort the names in alphabetical order.
 */
void sort_array(char (*ptr)[20], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
	for (j = 0; j < size - i - 1; j++)
	{
	    // Compare two strings(names) alphabeticaly
	    // If my_strcmp returns value greater than zero, then swap the names.
	    if ((my_strcmp(*(ptr + j), *(ptr + j + 1))) > 0)
	    {
		my_swap(*(ptr + j), *(ptr + j + 1), 20);    // Function call to swap the strings(names).
	    }
	}
    }
}

/* Function definition of my strcmp function :
 * Input : pointer of string1 & pointer of string2.
 * Output : returns greater than zero or less than zero if string1 is not match with string2
 returns zero if both strings are similar.
 */
int my_strcmp(char *str1, char *str2)	
{
    int i = 0;
    while (*str1)
    {
	// Compares the strings character by character (treats uppercase and lower case as same).
	if (*str1 != *str2)
	{
	    break;
	}
	str1++;
	str2++;
    }

    return str1[i] - str2[i];
}

/* Function definition of my swap function :
 * Input : base address of string1, base address of string2, max length.
 * Output : swap the strings(names).
 */
void my_swap(char *arr1, char *arr2, int len)
{
    char temp;
    for (int i = 0; i < len; i++)
    {
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
	arr1++;
	arr2++;
    }
}
