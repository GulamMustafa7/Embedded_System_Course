//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         28/10/2023
Description:  C program to find the median of two unsorted arrays.

Sample input: Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5

Sample output: Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5 
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //To declare variables.
    int index, i, j;
    int M, N, temp1, temp2;
    float median, median1, median2;

    //To print the messege and take a user input for number of elements'M'.
    printf("Enter the 'n' value for Array A: ");
    scanf("%d",&M);

    //To print the messege and take a user input for number of elements'N'.
    printf("Enter the 'n' value for Array B: ");
    scanf("%d",&N);

    //Condition to insure only positive integers are taken.
    if (M > 0 && N > 0)
    {
	//To declare the Arreys.
	int arrA[M], arrB[N];

	//To store the elements in arrA one by one with user input.
	printf("Enter the elements one by one for Array A: ");
	for (index = 0; index < M; index++)
	{
	    scanf("%d", &arrA[index]);
	}

	//To store the elements in arrB one by one with user input.
	printf("Enter the elements one by one for Array B: ");
	for (index = 0; index < N; index++)
	{
	    scanf("%d", &arrB[index]);
	}

	//Sorting arrA in ascending order by Bubble Sorting Method.
	//Outer loop for number of iterations.
	for (i = 0; i < (M - 1); i++)
	{
	    //Inner loop for comparing each element with next element of Arrey.
	    for (j = 0; j < (M - i - 1); j++)
	    {
		//If first element is greater than next element, replace the elements with each other.
		if (arrA[j] > arrA[j+1])
		{
		    //To store element in temporary variable to further store in Arrey.
		    temp1 = arrA[j];
		    arrA[j] = arrA[j+1];
		    arrA[j+1] = temp1;
		}
	    }
	}

	//Sorting arrB in ascending order by Bubble Sorting Method.
	//Outer loop for number of iterations.
	for (i = 0; i < (N - 1); i++)
	{
	    //Inner loop for coparing each element with next element of Arrey.
	    for (j = 0; j < (N - i - 1); j++)
	    {
		//If first element is greater than next element, replace the elements with each other.
		if (arrB[j] > arrB[j+1])
		{
		    //To store element in temporary variable to further store in Arrey.
		    temp2 = arrB[j];
		    arrB[j] = arrB[j+1];
		    arrB[j+1] = temp2;
		}
	    }
	}

	//median1 of sorted arrA.
	//If number of elements are even the take average of two medians, else median is single element.
	if (M % 2 == 0)
	{
	    median1 = (float) (arrA[M/2] + arrA[M/2 - 1])/2;
	}
	else
	{
	    median1 = arrA[M/2];
	}
	printf("Median of array1 : %g\n", median1);

	//median2 of sorted arrB.
	//If number of elements are even the take average of two medians, else median is single element.
	if (N % 2 == 0)
	{
	    median2 = (float) (arrB[N/2] + arrB[N/2 - 1])/2;
	}
	else
	{
	    median2 = arrB[N/2];
	}
	printf("Median of array2 : %g\n", median2);

	//To calculate Median of both the Arreys.
	median = (float) (median1 + median2)/2;
	printf("Median of both arrays : %g\n", median);
    }
    else
    {
	printf("Invalide input");
    }

    return 0;
}

