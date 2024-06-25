//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         14/01/2024
Description:  C programming to convert Little Endian data to Big Endian.

Sample input: Enter the size: 4
Enter any number in Hexadecimal: 12345678

Sample output:After conversion 78563412
 */

//########################################################################################//

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;     // Declare variable.

    // Reading input from user or no. of bytes.
    printf("Enter the size: ");
    scanf("%d", &size);

    if (size == 2)    // If selected 2 size(bytes).
    {
	short val, num = 0;    // short data type for size 2 byte.

	printf("Enter any number in Hexadecimal: ");
	scanf("%hX", &num);

	// Logic to convert 2 byte Hexadecial value in Big Endian format.
	val = ((num & 0x00FF) << 8) | ((num & 0xFF00) >> 8);
	printf("%hX", val);
    }
    else if (size == 4)    // If selected 4 size(bytes).
    {
	int val, num = 0;    // int data type for size 4 byte.

	printf("Enter any number in Hexadecimal: ");
	scanf("%X", &num);

	// Logic to convert 4 byte Hexadecial value in Big Endian format.
	val = ((num & 0x000000FF) << 24) | ((num & 0x0000FF00) << 8) | ((num & 0x00FF0000) >> 8) | ((num & 0xFF000000) >> 24);
	printf("%X", val);

    }
    else
    {
	printf("Invalide input\nPlease Enter 2 or 4\n");
    }

    return 0;
}

