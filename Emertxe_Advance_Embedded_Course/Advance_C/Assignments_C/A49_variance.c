//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         08/01/2024
Description:  C program to Variance calculation with dynamic arrays.


Sample input: Enter the no.of elements : 10

Sample output: Enter the 10 elements:
[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31
Variance is 40.000000
 */

//########################################################################################//

#include<stdio.h>
#include<stdlib.h>   //Including standard library.

// Declaration of variance function.
float variance(int *ptr, int size);

int main()
{
    // Declaration of variables.
    int elements, i;
    char ch;

    // Read the input from user for number of elements.
    printf("Enter the number of elements : ");
    scanf("%d", &elements);

    int arr[elements];   //Declaration of array.

    //Function call.
    printf("Variance is %g\n", variance(arr, elements));

    return 0;
}

/*Definition of variance function :
 *Input : base address of array, size of array.
 *Output : return variance.
 */
float variance(int *ptr, int size)
{
    float sum = 0, mean = 0, sum_var = 0, dev, var;

    ptr = calloc (size, sizeof(size));    // dynamic array created

    if (ptr == NULL)
    {
	printf("Memory not allocated\n");
    }
    else
    {
	// To calculate mean of elements :
	for ( int i = 0; i < size; i++)
	{
	    printf("[%d] -> ",i);
	    scanf("%d",&ptr[i]);    // Reading array elements
	    sum = sum + ptr[i];     // Sum of elements
	}

	mean = sum / size;    // mean calculation
	//printf("\nx(input)\tD=x-Mean\tD^2\n");

	// To calculate deviation and variance :
	for (int i = 0; i < size; i++)
	{
	    dev = ptr[i] - mean;
	    var = dev * dev;
	    sum_var = sum_var + var;
	    //printf("%d\t\t%g\t\t%g\n",ptr[i], d, var );
	}
	//printf("Sum = %g\t\t\tSum = %g\n",sum,sum_var);

	free (ptr);	// frees the pointer
	ptr = NULL;	// pointer that hold the address is set to NULL
    }

    return sum_var/size;
}
