//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         28/12/2023
Description:  C program to implement atoi function.

Sample input: Enter a numeric string: -12345

Sample output:String to integer is -12345

*/

//########################################################################################//

#include<stdio.h>

//Function declaration.
int my_atoi(const char []);

int main()
{
    char str[20];

    printf("Enter a numeric string : ");
    scanf("%s", str);

    //Function call returns int value in printf.
    printf("String to integer is %d\n", my_atoi(str));

    return 0;
}

int my_atoi(const char *str1)
{
    int res = 0, value = 0;
    int	i = 0, sign = 1;

    //Check if there is a '-' sign in front of number,
    //then assign the '-ve' sign.
    if (str1[0] == '-')
    {
	sign = -1;
	i++; //Increament the index to next charactre of string.
    }
    //If there is '+' sign in front of number,
    //then its valid but in final result '+' will not come in front of number.
    else if (str1[0] == '+')
    {
	sign = 1;
	i++; //Increament the index to next character of string.
    }

    //Run the loop until NULL character of string.
    while (str1[i] != '\0')
    {
	//Convert character to integer by substracting ascii value of '0'.
	//So resultant value will be same interger.
	value = (int)(str1[i] - '0');

	//If any other character is encountered except (0 -9),
	//then loop will brake.
	if (value < 0 || value > 9)
	    break;

	//Store the value as per its position.
	res = res * 10 + value;
	i++;
    }

    return (sign * res);
}
