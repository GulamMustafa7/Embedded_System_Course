#include<stdio.h>
#include<time.h>

int main()
{
    long int seconds;

    //seconds = time(NULL);
	time(&seconds);

    printf("%lu\n", seconds);
}

