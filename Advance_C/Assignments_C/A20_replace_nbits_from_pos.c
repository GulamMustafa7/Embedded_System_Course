//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         10/11/2023
Description:  C code to put the (b-a+1) lsb’s of num into val[b:a].

Sample input: Enter num, a, b, and val:11 3 5 174

Sample output: Result = 158
*/

//########################################################################################//

#include<stdio.h>

//Function declaring.
int replace_nbits_from_pos(int, int, int, int);

int main()
{
    //Ceclare variables.
    int num, a, b, val, res = 0;

    //To print the message and read the input.
    printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);

    //Condition to check the inputs are within the range.
    if ((a <= b) && (b <= 31))
    {
	//Function calling.
    	res = replace_nbits_from_pos(num, a, b, val);

    	printf("Result = %d\n", res);
    }
    else
    {
	printf("Inavalid Input");
    }

return 0;
}

//Function definition to replace 'a'bits from the 'b'position of 'val'.
int replace_nbits_from_pos(int n, int a, int b, int v)
{
    //Expresion :
    //To get 'a'bits from LSB of 'num' : mask1 = (((1 << a) - 1) << (b - a + 1))
    //To clear 'a'bits from 'b'position of 'val' : mask2 = (((1 << a) - 1) << (b - a +1))
    //To replace : ((num & mask1) | (val & (~mask2)))
    return (((n & ((1<<a)-1)) << (b-a+1)) | (v & (~(((1<<a)-1) << (b-a+1)))));
}

