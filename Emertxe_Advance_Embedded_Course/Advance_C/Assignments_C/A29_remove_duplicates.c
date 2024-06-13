//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         28/11/2023
Description:  C program to remove duplicate elements in a given array.

Sample input: Enter the size: 7
              Enter elements into the array: 4 5 5 4 1 7 7

Sample output:After removing duplicates: 4 5 1 7
*/

//########################################################################################//

#include<stdio.h>

//Function declaration.
void fun(int arr1[], int size, int arr2[], int *new_size);

int main()
{
    int size, new_size = 0, i;

    printf("Enter the size: ");
    scanf("%d", &size);

    int arr1[size];
    int arr2[size];

    //Collecting elements in arr1.
    printf("Enter elements into the array: ");
    for (i = 0; i < size; i++)
    {
	scanf("%d", &arr1[i]);
    }

    //Function call.
    fun(arr1, size, arr2, &new_size);

return 0;
}

//Function definition.
void fun(int arr1[], int size, int arr2[], int *new_size)
{
    int i, j;

    //Outer loop to check elements of arr1.
    for (i = 0; i < size; i++)
    {
	//Inner loop to check elements of arr2.
	for (j = 0; j < *new_size; j++)
	{
	    //If duplicate element found then break the 'j' loop.
	    if (arr1[i] == arr2[j])
		break;
	}

	//If index of arr2 match with count (*new_size) then only collect in arr2.
	if (j == *new_size)
	{
	    arr2[*new_size] = arr1[i];

	    //If unique element found at index = count then inceament the count.
	    (*new_size)++;
	}
    }

    //To print the arr2 without duplicates.
    printf("After removing duplicates: ");
    for (i = 0; i < *new_size; i++)
    {
    	printf("%d ", arr2[i]);
    }
    printf("\n");
}

