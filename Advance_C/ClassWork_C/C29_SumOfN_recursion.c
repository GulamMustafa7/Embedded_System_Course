//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:         05/05/2024
* Description:  Write a program to find the sum of sequence of N from starting from 1 using recursion.
* Sample input:  Enter the N value : 5
* Sample output: Sum is 15
*/

//########################################################################################//

#include<stdio.h>

int main()
{
	//Declare static variables to retain the values in recursion.
    static int flag, num;
    static int sum = 0;

    //Conditon with flag to read the input value only once at the start.
    if (flag == 0)
    {
	    printf("Enter the N value: ");
	    scanf("%d", &num);
	    flag = 1;
    }

    if (num >= 0)
    {
	    //Recursive condition calling main() function.
	    if (num >= 1)
	    {
	        sum = (sum + num);
			num--;
	        //Function call.
	        main();
	    }
	    //Base condition to end the recursion.
	    else
	    {
	        printf("Sum is %d\n", sum);
	        return 0;
	    }
    }
    else
    {
	    printf("Invalid Input\n");
    }

	return 0;
}

