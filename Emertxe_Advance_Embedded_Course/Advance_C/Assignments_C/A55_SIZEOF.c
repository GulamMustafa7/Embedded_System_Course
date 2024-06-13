//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         17/01/2024
Description:  C program to define a macro SIZEOF(x), without using sizeof operator.
Sample input:
Sample output:
Size of int		: 4 bytes
Size of char		: 1 bytes
Size of float		: 4 bytes
Size of double		: 8 bytes
Size of unsigned int	: 4 bytes
Size of long int	: 8 bytes
Size of short int	: 2 bytes
Size of signed int 	: 4 bytes
Size of signed char	: 1 bytes
Size of unsigned char	: 1 bytes
Size of long double	: 16 bytes
Size of long long int	: 8 bytes
Size of unsigned short	: 2 bytes

*/

//########################################################################################//

#include <stdio.h>

// Calculating size of data type using pointer arithmatic between address.

#define SIZEOF(x)	(char *)(&x+1) - (char *)(&x)
	
int main()
{
	int i;
	char ch;
	float f;
	double dl;
	short int shint;
	unsigned int uint;
	long int lint;
	signed int sint;
	signed char schar;
	unsigned char uchar;
	long double ldl;
	long long int llint;
	unsigned short ushort;
	
	// To print the sizeof datatypes with the help of macro : 
	
	printf("Size of int		: %zu bytes\n", SIZEOF(i));  
	printf("Size of char		: %zu bytes\n", SIZEOF(ch));
    	printf("Size of float		: %zu bytes\n", SIZEOF(f));
    	printf("Size of double		: %zu bytes\n", SIZEOF(dl));
    	printf("Size of unsigned int	: %zu bytes\n", SIZEOF(uint));
    	printf("Size of long int	: %zu bytes\n", SIZEOF(lint));
    	printf("Size of short int	: %zu bytes\n", SIZEOF(shint));
    	printf("Size of signed int 	: %zu bytes\n", SIZEOF(sint));
    	printf("Size of signed char	: %zu bytes\n", SIZEOF(schar));
    	printf("Size of unsigned char	: %zu bytes\n", SIZEOF(uchar));
    	printf("Size of long double	: %zu bytes\n", SIZEOF(ldl));
    	printf("Size of long long int	: %zu bytes\n", SIZEOF(llint));
    	printf("Size of unsigned short	: %zu bytes\n", SIZEOF(ushort));
    
}	
