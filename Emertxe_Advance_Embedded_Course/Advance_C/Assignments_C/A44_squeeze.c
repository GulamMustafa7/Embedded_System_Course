//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         03/01/2024
Description:  C program to squeeze the character in s1 that matches any character in the string s2

Sample input: Enter s1 : Dennis Ritchie
              Enter s2 : Linux

Sample output: After squeeze s1 : Des Rtche
*/

//########################################################################################//

#include<stdio.h>
#include<string.h>

//Function prototype.
void squeeze(char [], char []);

int main()
{
    char str1[30], str2[30];

    // reading the input str1 using selective scanf.
    printf("Enter string1:");
    scanf("%[^\n]", str1);

    //Clear output buffer.
    getchar();

    // reading the input str2 using selective scanf.
    printf("Enter string2:");
    scanf("%[^\n]", str2);

    //Function call.
    squeeze(str1, str2);

    //Print updated str1.
    printf("After squeeze s1 : %s\n", str1);

    return 0;
}

//Function definition.
void squeeze(char str1[], char str2[])
{
    //Declare variables.
    int k, len1, len2;

    len1 = strlen(str1);
    len2 = strlen(str2);

    printf("%d\n", len1);
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
	    // comparing each elements of str1 with each elements of str2.
            if (str1[j] == str2[i])
            {
                for (k = j; k < len1; k++)
                {
		    // removing the match charcters(shifting to left).
                    str1[k] = str1[k + 1];
                }
                j--;
            }
        }
    }
}
