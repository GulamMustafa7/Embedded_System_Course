//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         19/01/2024
Description:  C program to Implement the student record using array of structures.

Sample execution:
Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1          Nandhu         99            91            95              A
Do you want to continue to display(Y/y) : n

 */

//########################################################################################//

#include<stdio.h>
#include <stdlib.h>

// Function prototypes :
int my_strcmp( char *str1, char *str2);
char grade(float avg);

struct student    // Defining Student Structure.
{
    int roll_no;
    char name[30];
    int *mark;

};

int main()
{
    char ch;
    do
    {
	// Declaration of variables.
	int total_stu, total_sub;
	int option,choice;
	float sum = 0, avg;
	int count = 0;

	printf("Enter no.of students : ");    // Read input from user for no. of Students.
	scanf("%d",&total_stu);

	printf("Enter no.of subjects : ");    // Read input from user for no. of Subjects.
	scanf("%d",&total_sub);

	char (*str)[20];
	str = malloc ( sizeof(*str) * total_sub);    // Dynamic memory allocation for all subjects.

	struct student  s[total_stu];    // Declaring array of structure.

	// Read the name of subjects.
	for (int i = 0; i < total_sub; i++)
	{
	    printf("Enter the name of the subject %d : ", i+1);
	    scanf("%s",str[i]);
	}

	// Read the student details one by one from user.
	for (int i = 0; i < total_stu; i++)
	{
	    printf(" --------------- Enter student details -------------\n");
	    printf("Enter the sutdent Roll no : ");
	    scanf("%d",&s[i].roll_no);

	    printf("Enter the student %d name : ", i+1);
	    scanf("%s",s[i].name);

	    s[i].mark = malloc ( sizeof(int) * total_sub);
	    for (int j=0; j < total_sub; j++)
	    { 
		printf("Enter the %s mark : ", str[j]);
		scanf("%d",&s[i].mark[j]);
	    }
	}

	do
	{
	    printf("----- Display menu -----\n1. All student details\n2. Particular student details\nEnter your choice : ");
	    scanf("%d", &option);
	    avg = 0;
	    count = 0;

	    switch (option)
	    {
		case 1:    // To display all student details.
		    {
			printf("Roll No\t\tName\t\t");
			for (int j = 0; j < total_sub; j++)
			    printf("%s\t\t", str[j]);

			printf("Average\t\tGrade\n");
			for (int i = 0; i < total_stu; i++)
			{
			    sum = 0;
			    for (int j = 0; j < total_sub; j++)
			    {
				sum = sum + s[i].mark[j];
			    }

			    printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
			    for (int j = 0; j < total_sub; j++)
			    {
				printf("%d\t\t",s[i].mark[j] );
			    }

			    avg = sum / total_sub;

			    printf("%g\t\t%c\n",avg,grade(avg));
			}
			break;
		    }
		case 2:    // To Display particular student details.
		    {
			printf("-----Menu for particular student-----\n1. Name\n2. Roll no\nEnter your choice: ");
			scanf("%d",&choice);

			if (choice == 1)    // If user wants to print details using name.
			{
			    char stu_name[40];
			    printf("Enter the name of the student : ");
			    scanf("%s",stu_name);
			    sum = 0;
			    for (int i = 0; i < total_stu; i++)
			    {
				if (my_strcmp ( s[i].name, stu_name) == 0)
				{
				    printf("Roll No\t\tName\t\t");
				    for (int j = 0; j < total_sub; j++)
				    { 
					printf("%s\t\t", str[j]);
					sum = sum + s[i].mark[j];
				    }

				    printf("Average\t\tGrade\n");
				    printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
				    for (int j = 0; j < total_sub; j++)
				    { 
					printf("%d\t\t",s[i].mark[j] );
				    }
				    avg = sum / total_sub;

				    printf("%g\t\t%c\n",avg,grade(avg));
				    count++;
				}
			    }
			    if (count == 0)    // If entered student name is not available it means its executes.
				printf("Please mention correct student name\n");		
			}
			else if (choice == 2)    // If user wants to print details using roll no.
			{
			    int number;
			    printf("Enter the number of the student : ");
			    scanf("%d", &number);
			    sum = 0;
			    for (int i = 0; i < total_stu; i++)
			    {
				if (number == s[i].roll_no)
				{
				    printf("Roll No\t\tName\t\t");
				    for (int j = 0; j < total_sub; j++)
				    { 
					printf("%s\t\t", str[j]);
					sum = sum + s[i].mark[j];
				    }

				    printf("Average\t\tGrade\n");
				    printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
				    for (int j = 0; j < total_sub; j++)
				    { 
					printf("%d\t\t",s[i].mark[j] );
				    }

				    avg = sum / total_sub;

				    printf("%g\t\t%c\n",avg,grade(avg));
				    count++;
				}
			    }
			    if (count == 0)    // If entered student roll no is not available it means its executes
				printf("Please mention correct student roll no\n");
			}
			else
			    printf("Enter valid option\n");
			break;
		    }
		default :
		    printf("Enter valid option\n");
	    }
	    printf("Do you want to continue to display(y/Y) : ");    // Ask user to continue the desplay menu.
	    scanf(" %c",&choose);	

	}while (choose == 'Y' || choose == 'y');    // Condition checking for repetetion.

	free(str);
	str = NULL;
	printf("Do you want to continue (y/Y) : "); // Ask user to continue or not for entire execution.
	scanf(" %c",&ch);


    }while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

    return 0;	

}

/* String compare function for finding student name  
   and entered name is matched or not irrespective of 
   lower or upper case. 
 */
int my_strcmp( char *str1, char *str2)
{
    // Compares strings character by character (treats uppercase and lower case as same).
    while ( ( *str1 && *str2 ) && ( *str1 == *str2 ) || ( *str1 - 32 == *str2) || (*str2 - 32 == *str1) ) 
    {
	str1++;
	str2++;	
    }
    return *str1 - *str2;
}

/* Function definition of grade function
 * Input : float average.
 * Output : returns grade for respective average.
 */
char grade(float avg)
{
    if ( avg >= 90 )
	return 'A';
    else if (avg >= 80 && avg < 90)
	return 'B';
    else if (avg >= 70 && avg < 80)
	return 'C';
    else if (avg >= 60 && avg < 70)
	return 'D';
    else if (avg >= 50 && avg < 60)
	return 'E';
    else
	return 'F';
}
