//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         22/10/2023
Description:  C programm to find which day of the year.

Sample input/output : 
Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 2
The day is Tuesday

 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare the variables as integers.
    int nth, first, day;

    //To print the messeg & raed input for nth day.
    printf("Enter the value of 'n' :");
    scanf("%d",&nth);

    //Condition to check value is within limit 1 to 365.
    if (nth >= 1 && nth <= 365)
    {
	//To print the Menu.
	printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");

	//To print the messege & read value for option to set first day.
	printf("Enter the option to set the first day :");
	scanf("%d",&first);

	//Condition to check Start day value is within limit.
	if (first > 0 && first <= 7)
	{
	    //Mathematicam formula to get the day value.
	    day = (nth + first) % 7;

	    //Switch cases to choose the day and print.
	    switch (day)
	    {
		case 2:
		    printf("The day is Sunday\n");
		    break;
		case 3:
		    printf("The day is Monday\n");
		    break;
		case 4:
		    printf("The day is Tuesday\n");
		    break;
		case 5:
		    printf("The day is Wednesday\n");
		    break;
		case 6:
		    printf("The day is Thursday\n");
		    break;
		case 0:
		    printf("The day is Friday\n");
		    break;
		case 1:
		    printf("The day is Saturday\n");
		    break;
	    }
	}
	else
	{
	    printf("Error: Invalid input, first day should be > 0 and <= 7\n");
	}
    }
    else
    {
	printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
    }
    return 0;
}
