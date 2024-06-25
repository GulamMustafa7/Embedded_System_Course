//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:         17/01/2024
* Description:  C program to define a macro swap (t, x, y) that swaps 2 arguments of type t.
* Sample input:
		1. Int
		2. char
		3. short
		4. float
		5. double
		6. string
		Enter you choice : 1

		Sample output:
		Enter the num1 : 10
		Enter the num2 : 20
		After Swapping :
		num1 : 20
		num2 : 10
 */

//########################################################################################//

#include<stdio.h>
#include <stdlib.h>

// Defining a SWAP macro :
#define SWAP(t, x, y)	\
{			            \
    t temp;		        \
    temp = x;		    \
    x = y;		        \
    y = temp;		    \
}			            \

int main()
{
    char ch;
    do
    {
	int choice;
	printf("1. int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your choice : "); 
	scanf("%d",&choice);	// Read the choice from user.

	switch (choice)
	{
	    case 1:
		{
		    int num1, num2;

		    // Read the integer input from user.
		    printf("Enter the num1 : ");
		    scanf("%d",&num1);
		    printf("Enter the num2 : ");
		    scanf("%d",&num2);

		    SWAP(int, num1, num2)	// Using MACRO with to swap the integers.

			printf("\nAfter swapping :\nnum1 : %d\nnum2 : %d\n",num1,num2);
		    break;
		}
	    case 2:
		{
		    char char1, char2;

		    printf("Enter the char1 : ");
		    scanf(" %c",&char1);
		    printf("Enter the char2 : ");
		    scanf(" %c",&char2);

		    SWAP(char, char1, char2)	// Using MACRO to swap the characters.

			printf("\nAfter swapping :\nchar1 : %c\nchar2 : %c\n",char1,char2);
		    break;
		}
	    case 3:
		{
		    short num1, num2;

		    printf("Enter the num1 : ");
		    scanf("%hd",&num1);
		    printf("Enter the num2 : ");
		    scanf("%hd",&num2);

		    SWAP(short, num1, num2)    // Using MACRO to swap the short integers.

			printf("\nAfter swapping :\nnum1 : %d\nnum2 : %d\n",num1,num2);
		    break;
		}
	    case 4:
		{
		    float num1, num2;

		    printf("Enter the num1 : ");
		    scanf("%f",&num1);
		    printf("Enter the num2 : ");
		    scanf("%f",&num2);

		    SWAP(float, num1, num2)    // Using MACRO to swap the float numbers.

			printf("\nAfter swapping :\nnum1 : %g\nnum2 : %g\n",num1,num2);
		    break;
		}
	    case 5:
		{
		    double num1, num2;

		    printf("Enter the num1 : ");
		    scanf("%lf",&num1);
		    printf("Enter the num2 : ");
		    scanf("%lf",&num2);

		    SWAP(double, num1, num2)    // Using MACRO to swap the double.

			printf("\nAfter swapping :\nnum1 : %g\nnum2 : %g\n",num1,num2);
		    break;
		}
	    case 6:
		{
		    char *str1, *str2;

		    str1 = malloc ( 50 * sizeof(char));    // Dynamic memmory allocation for string.
		    str2 = malloc ( 50 * sizeof(char));

		    printf("Enter string 1 : ");
		    scanf("%s",str1);
		    printf("Enter string 2 : ");
		    scanf("%s",str2);

		    SWAP(char *, str1, str2)    // Using MACRO to swap the strings.

			printf("\nAfter swapping :\nstring 1 : %s\nstring 2 : %s\n",str1,str2);
		    break;
		}
	    default :
		printf("Please enter correct choice\n");
	}
	printf("Do you want to continue(y/Y):");
	scanf(" %c",&ch);

    }while (ch == 'Y' || ch == 'y');    // Condition checking for repeated program.

    return 0;	
}

