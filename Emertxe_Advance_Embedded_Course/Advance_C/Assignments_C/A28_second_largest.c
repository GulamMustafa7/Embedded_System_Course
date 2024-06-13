//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         28/11/2023
Description:  C program to find 2nd largest element in an array.

Sample input: Enter the size of the Array : 5
              Enter the elements into the array: 5 1 4 2 8

Sample output:Second largest element of the array is 5
 */

//########################################################################################//

#include<stdio.h>

int sec_largest (int [], int);

int main()
{
    int size, ret, i;

    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);

    //Condition to check the size of array is at least 2.
    if (size > 1)
    {
	int arr[size];

	//Read elements into the array
	printf("Enter the elements into the array: ");
	for (i = 0; i < size; i++)
	{
	    scanf("%d", &arr[i]);
	}

	//funtion call
	ret = sec_largest(arr, size);

	printf("Second largest element of the array is %d\n", ret);

    }
    else
    {
	printf("Invalide input\n");
    }

    return 0;
}

//Function definition.
int sec_largest (int arr[], int size)
{
    //storing initial elements of array in variables.
    int first = arr[0];
    int second = arr[1];

    //Logic to find third largest element of array and store in variable 'second'.
    for (int i = 0; i < size; i++)
    {
	if (arr[i] > first)
	{
	    second = first;
	    first = arr[i];
	}
	else if ((arr[i] > second) && (arr[i] < first))
	{
	    second = arr[i];
	}
    }
    return second;
}
