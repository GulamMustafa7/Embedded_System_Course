//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         01/01/2024
Description:  C program to implement itoa function.

Sample input: Enter the number : +1234

Sample output:Integer to string is 1234
*/

//########################################################################################//

#include<stdio.h>

//Function prototypes.
void itoa(int num, char str[]);
void reverse(char str[], int length);

int main()
{
    int num, ret;
    char str[10];

    printf("Enter the number:");
    ret = scanf("%d", &num);

    /*If Input is Non interger value,
     *then scan returns '0'.
     *This condicotion will be true when (ret = 0).
     *And condition will terminate returning result as '0'.
     */
    if (!ret)
    {
	printf("Integer to string is %d\n", ret);
	return 0;
    }

    //Funtion call to itoa function
    itoa(num, str);

    printf("Integer to string is %s\n", str);

return 0;
}

//Function definition to convert integer value to string.
void itoa(int num, char *str)
{
    //Declare & initialize local variables.
    int i = 0, flag = 0;
    int rem = 0;
    int rev = 0;

    //If given input is zero then dont need to reverse string function.
    if (num == 0)
    {
	str[i] = '0';
	i++;
	str[i] = '\0';
	return;
    }
    //If input is negative integer then convert it to positive
    //And set flag value to 1 for further use.
    else if (num < 0)
    {
	num = -num;
	flag = 1;
    }

    //Store only psitive 'num' value in 'rem'.
    rem = num;
    while (rem != 0)
    {
	//Logic to get each number and convert into ASCII.
	//And store in character array in reverse seguence.
        rev = rem % 10;
	str[i] = rev + '0';
	rem = rem / 10;
	i++;
    }

    //If input 'num' value was negative then put the '-' sign in front of string.
    if (flag)
    {
	str[i] = '-';
	i++;
    }

    //End string with NULL character '\0'
    str[i] = '\0';

    //Function call to reverse the string.
    reverse(str, i);
    return;

}

//Function definition to reverse the string by using iterative methode.
void reverse(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}
