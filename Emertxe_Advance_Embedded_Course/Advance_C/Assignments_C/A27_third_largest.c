//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         27/11/2023
Description:  C program to find 3rd largest element in an array.

Sample input: Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8

Sample output:Third largest element of the array is 4
 */

//########################################################################################//

#include<stdio.h>

int third_largest (int [], int);

int main()
{
    int size, ret, i;

    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);

    //Condition to check the size of array is at least 3.
    if (size > 2)
    {
	int arr[size];

	//Read elements into the array
	printf("Enter the elements into the array: ");
	for (i = 0; i < size; i++)
	{
	    scanf("%d", &arr[i]);
	}

	//funtion call
	ret = third_largest(arr, size);

	printf("Third largest element of the array is %d\n", ret);

    }
    else
    {
	printf("Invalide input\n");
    }

    return 0;
}

//Function definition.
int third_largest (int arr[], int size)
{
    //storing initial elements of array in variables.
    int first = arr[0];
    int second = arr[1];
    int third = arr[2];

    //Logic to find third largest element of array and store in variable 'third'.
    for (int i = 0; i < size; i++)
    {
	if (arr[i] > first)
	{
	    third = second;
	    second = first;
	    first = arr[i];
	}
	else if ((arr[i] > second) && (arr[i] < first))
	{
	    third = second;
	    second = arr[i];
	}
	else if ((arr[i] > third) && (arr[i] < second) && (arr[i] < first))
	{
	    third = arr[i];
	}
    }
    printf("first = %d\n second = %d\n", first, second);
    return third;
}
