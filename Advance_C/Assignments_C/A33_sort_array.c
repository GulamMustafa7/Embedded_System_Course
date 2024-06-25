//#########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         03/12/2023
Description:  C program to print the values in sorted order without modifying or copying array.

Sample input: Enter the size : 5
              Enter 5 elements 
              10 1 3  8 -1

Sample output:After sorting: -1 1 3 8 10
              Original array values 10 1 3 8 -1
 */

//########################################################################################//

#include<stdio.h>

//Function declaration.
void print_sort(int [], int);

int main()
{
    int size, iter;

    //Read input size.
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    //Declare array.
    int arr[size];

    //Read input values and collect array elements.
    printf("Enter the %d elements\n", size);
    for (iter = 0; iter < size; iter++)
    {
	scanf("%d", &arr[iter]);
    }

    //Function call.
    printf("After sorting: ");
    print_sort(arr, size);
    printf("\n");

    //Print original array.
    printf("Original array values ");
    for (iter = 0; iter < size; iter++)
    {
	printf("%d ", arr[iter]);
    }
    printf("\n");

    return 0;
}

//Function definition.
void print_sort(int arr[], int size)
{
    //Declare and initialize variables 'large' and 'small'.
    int large = arr[0], small = arr[0];

    //Find largest and smallest element of array.
    for (int i = 0; i < size; i++)
    {
	if (large < arr[i])
	{
	    large = arr[i];
	}

	if (small > arr[i])
	{
	    small = arr[i];
	}
    }
    //Print first smallest value of array.
    printf("%d ", small);

    //Declare and initialize 'second_small' with largest value of the array. 
    int second_small = large;

    //Run the iteration until last value of array is compared.
    while (small != large)
    {
	//Compare and print the elements of array in sorted order(second_small -to- large).
	for (int j = 0; j < size; j++)
	{
	    if (arr[j] > small && arr[j] < second_small)
	    {
		second_small = arr[j];
	    }
	}

	printf("%d ", second_small);
	small = second_small;
	second_small = large;
    }

}

