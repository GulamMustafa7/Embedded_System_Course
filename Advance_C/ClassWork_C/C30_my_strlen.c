//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:
* Description:
* Sample input:
* Sample output:
*/

//########################################################################################//

#include<stdio.h>

int main()
{
    char str[50] = {0};
    unsigned int length = 0;
    
    printf("Enter the string : ");
    scanf("%s", str);
    
    while (str[length] != '\0')
    {
        length++;
    }
    
    printf("String length is %d\n", length);
    
    return 0;
    
}
