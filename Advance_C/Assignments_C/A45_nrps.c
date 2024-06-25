//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         04/01/2024
Description:  C program generate consecutive NRPS of length n using k distinct character.

Sample input: Enter the number characters C : 3
              Enter the Length of the string N : 6
              Enter 3 distinct characters : a b c

Sample output:Possible NRPS is abcbca
*/

//########################################################################################//

#include<stdio.h>

//Function prototype of nrps function.
void nrps(char [], int, int);

int main()
{
    //Declarion variables.
    int i, j, num, len;

    printf("Enter the number characters C: ");
    scanf("%d", &num); //Reading the number characters.

    //Declaration of string.
    char str[num];

    printf("Enter the Length of the string N: ");
    scanf("%d", &len); //Reading the length of the string.

    printf("Enter %d distinct characters: ", num);

    //Reading the distinct characters.
    for (i = 0; i < num; i++)
    {
    scanf("%s", &str[i]);
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (str[i] == str[j])
            {
                printf("Error : Enter distinct characters\n");
                return 0;
            }

        }
    }
    //Function call with passing str, num and len as arguments.
    nrps(str, num, len);

    return 0;
}

//Function definition to print possible NRPS.
void nrps(char *arr, int num, int len)
{
    //Local variable declaration.
    int i, count = 0;

    printf("Possible NRPS is ");
    for (i = 0; i < len; i++)
    {
        if (((i % num) == 0) && (i != 0))
            count++;

	//Logic to print all possible NRPS.
        printf("%c", *(arr + (count + i) % num));
    }
    printf("\n");
}
