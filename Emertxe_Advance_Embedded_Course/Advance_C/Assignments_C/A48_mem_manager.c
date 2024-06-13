//########################################################################################//

/*
Name:         GulamMustafa Ibrahim Kazi.
Date:         07/01/2024
Description:  C program to provide a menu to manipulate or display the value of variable of type t.

Sample execution: ~./mem_manager
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4

 */

//########################################################################################//

#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Declaration of variables.
    int choice, option, index;
    int pos[5];

    // Delaration & initialization of flags with value '0'.
    int c_flag = 0, sh_flag = 0, i_flag = 0, f_flag = 0, d_flag = 0;

    void *ptr;  // Declaration of generic pointer.
    ptr = malloc ( 8 * sizeof(char));  // Allocate 8 bytes of dynamic memory.

    // Desplay the menu until user select option with exit(1).
    while (1)
    {
	printf("\nMenu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n\nChoice ---> ");	

	scanf("%d",&choice);	// Read choic from user.
	switch(choice)
	{
	    case 1:		// To Add Element :
		{
		    printf("Enter the type you have to insert:\n1.int\n2.char\n3.short\n4.float\n5.double\n");
		    printf("\nchoice ---> ");
		    scanf("%d",&option);   // Read choice from user.

		    switch (option)
		    {
			case 1:
			    if ( i_flag == 0 && f_flag == 0 && d_flag == 0)
			    {
				i_flag++;
				printf("Enter the integer : ");	
				scanf("%d",((int*)ptr) + 1);		// Read int from user and store in second set of 4 bytes.
				printf("%d",*(((int*)ptr) + 1) );	
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 2:
			    if( c_flag < 2 && d_flag == 0	)
			    {
				printf("Enter the character : ");
				scanf(" %c",((char*)ptr) + c_flag); // Read char from user and store in set of first 2 bytes.
				printf("%c\n",*(((char*)ptr)+ c_flag) );
				c_flag++;
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 3:
			    if ( sh_flag == 0 && d_flag == 0 )
			    {
				sh_flag++;
				printf("Enter the integer (short) : ");
				scanf("%hd",((short*)ptr) + 1);		// Read short from user and store in second set of 2 bytes. 
				printf("%hd",*(((short*)ptr) + 1) );
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 4:
			    if ( i_flag == 0 && f_flag == 0 && d_flag == 0)
			    {
				f_flag++;
				printf("Enter the float value : ");
				scanf("%f",((float*)ptr) + 1);	// Read float from user and store in second set of 4 bytes.
				printf("%f",*(((float*)ptr) + 1) );
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 5:
			    if ( c_flag == 0 && i_flag == 0 && sh_flag == 0 && f_flag == 0 && d_flag == 0)
			    {
				d_flag++;
				printf("Enter the double value : ");
				scanf("%lf",((double*)ptr) );		// Read double from user and store in 8 bytes memory.
				printf("%lf",*((double*)ptr) );
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			default :
			    printf("Invalid option");
		    }
		    break;			
		}
	    case 2:	// Desplay Menu to Remove Element :
		{
		    index = 0;	
		    // Printing element with position in 8 bytes of memory allocated.

		    if ( c_flag > 0 )
		    {
			printf("[%d] -> %c\n",index, *((char*)ptr));    // 1st character. 
			pos[index++] = 1;

			if ( c_flag > 1 )
			{
			    printf("[%d] -> %c\n",index, *(((char*)ptr)+ 1) );    //2nd character.
			    pos[index++] = 1;
			}
		    }

		    if ( sh_flag == 1 )
		    {
			printf("[%d] -> %hd\n",index, *(((short*)ptr) + 1) );	// 1 short (At 3rd and 4th byte) Total 2 bytes for short.
			pos[index++] = 2;
		    }

		    if ( i_flag == 1 )
		    {
			printf("[%d] -> %d\n",index, *(((int*)ptr) + 1) );	// 1 int (At 5th to 8th byte) Total 4 bytes for int.
			pos[index++] = 3;
		    }

		    if ( f_flag == 1 )
		    {
			printf("[%d] -> %f\n",index, *(((float*)ptr) + 1) );	// 1 float (At 5th to 8th byte) Total 4 bytes for float.
			pos[index++] = 4;
		    }

		    if ( d_flag == 1 )
		    {
			printf("[%d] -> %lf\n",index, *((double*)ptr) );    // 1 double (Entire 8 bytes allocated).
			pos[index++] = 5;
		    }

		    // Read the index from user.
		    printf("Enter the index value to be deleted : ");
		    scanf("%d",&index);

		    switch ( pos[index] )
		    {
			case 1 :    // To Remove character.
			    if ( c_flag > 0 )	
			    {
				if (  index == 0 )
				{
				    *((char*)ptr) = *(((char*)ptr)+ 1);
				    c_flag--;
				}

				if ( index == 1 )
				{
				    c_flag--;
				}
				printf("Index %d is successfully deleted \n",index);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 2:    // To remove short.
			    if ( sh_flag == 1 )
			    {
				sh_flag--;
				printf("Index %d is successfully deleted \n",index);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 3:    // To remove int.
			    if ( i_flag == 1 )
			    {
				i_flag--;
				printf("Index %d is successfully deleted \n",index);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 4:	   // To remove float
			    if ( f_flag == 1 )
			    {
				f_flag--;
				printf("Index %d is successfully deleted \n",index);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 5:	   // To remove double.
			    if ( d_flag == 1 )
			    {
				d_flag--;
				printf("Index %d is successfully deleted \n",index);
			    }
			    else
				printf("Already deleted\n");
			    break;
			default :
			    printf("Invalid option");
		    }
		    break;
		}
	    case 3:	// To Desplay the Element :
		{
		    index = 0;
		    printf("\n");
		    if ( c_flag > 0 )
		    {
			printf("\n[%d] -> %c\t[char_type]\n",index++, *((char*)ptr));

			if ( c_flag > 1 )
			    printf("[%d] -> %c\t[char_type]\n",index++, *(((char*)ptr)+ 1) );	
		    }

		    if ( sh_flag == 1 )
			printf("[%d] -> %hd\t[short_type]\n",index++, *(((short*)ptr) + 1) );

		    if ( i_flag == 1 )
			printf("[%d] -> %d\t[int_type]\n",index++, *(((int*)ptr) + 1) );

		    if ( f_flag == 1 )
			printf("[%d] -> %f\t[float_type]\n",index++, *(((float*)ptr) + 1) );

		    if ( d_flag == 1 )
			printf("[%d] -> %lf\t[double_type]\n",index++, *((double*)ptr) );

		    if ( c_flag == 0 && i_flag == 0 && sh_flag == 0 && f_flag == 0 && d_flag == 0)
			printf("Nothing available all indexes are empty\n"); 
		    break;
		}
	    case 4 :	// To Exit from the Program :
		free(ptr);
		ptr = NULL;
		exit(1);
		break;
	    default :
		printf("Invalid option\n");
	}
    }
}
