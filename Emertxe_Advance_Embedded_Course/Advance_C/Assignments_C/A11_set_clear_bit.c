//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         23/10/2023
Description:  C programm to check N th bit is set or not, If yes, clear the M th bit.

Sample input: Enter the number: 19
              Enter 'N': 1
              Enter 'M': 4

Sample output: Updated value of num is 3 
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare all the variables as integer.
    int num, M, N;

    //To print the messege when program starts.
    printf("Enter the number: ");

    //To read integer input from user.
    scanf("%d", &num);

    //Condition to check number is positive integer.
    if (num >= 0)
    {
	//To print the messege & read Nth value from user.
	printf("Enter 'N': ");
	scanf("%d", &N);

	//To print the messege & read Mth value from user.
	printf("Enter 'M': ");
	scanf("%d", &M);

	//Condition to check Nth bit is set bit or not.
	if (num & (1 << N))
	{
	    //To clear Mth bit of the number.
	    num = num & (~(1 << M));
	}
        //To print the updated value.	
       	printf("Updated value of num is %d\n", num);

	/*
        -Another way of solving this problem is using Ternary Operators.
	-Explaination: In this code the statment used left side of '?' operator is a condition to check set bit.(In this case Mth bit is clear & value of num is change).
	-If condition is true the expression between '?' and ':' is evaluated.
	-If condition is false then expression right side of ':' operator is evaluated.(In this case value of num will not change)

	if (num & (1 << N) ? num = num & (~(1 << M)) : num)
	{
	//To print the updated value of num.
	    printf("Updated value of num is %d\n", num);
	}*/
    }
return 0;
}
