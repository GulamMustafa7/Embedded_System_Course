//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         14/12/2023
Description:  C program to count no. of characters, words and lines, entered through stdin.

Sample input: Hello world
              Dennis Ritchie
              Linux

Sample output:Character count : 33
              Line count : 3
              Word count : 5
 */

//########################################################################################//

#include<stdio.h>

int main()
{
    //Declare & initialize 'Flag' with '0' to track word boundaries.
    int flag = 0;

    char ch = 0; //Declare & initialize 'ch' variable to hold input characters.

    //Variables to count characers, words and lines.
    int ch_count = 0, w_count = 0, l_count = 0;

    //Loop to read characters until end-of-file (EOF) is encountered.
    while ((ch = getchar()) != EOF)
    {
	//Increament the count of characters.
	++ch_count;

	if ((ch == ' ') || (ch == '\t'))
	{
	    //Reset the flag when space or tab is encountered.
	    flag = 0;
	}
	else if (ch == '\n')
	{
	    //Increament the count of lines.
	    ++l_count;
	    
	    //Reset the flag on a newline.
	    flag = 0;
	}
	else if (flag == 0)
	{
	    //Increament the count of words when a new word begins.
	    ++w_count;

	    //Set the flag to indicate a word is in progress.
	    flag = 1;
    	}
    }

    printf("\n");
    printf("Character count : %d\n", ch_count);
    printf("Line count : %d\n", l_count);
    printf("Word count : %d\n", w_count);

    return 0;
}
