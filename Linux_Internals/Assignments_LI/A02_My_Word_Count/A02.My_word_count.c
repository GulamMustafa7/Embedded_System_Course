/*
* Name : GulamMusttafa I. Kazi.
* Date : 20/04/2024
* Description : Implement a wc(word count) command with -l -w -c options.
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>


void my_wc(int,int *,int *,int *);

int main(int argc, char *argv[])
{
	int l_flag = 0, w_flag = 0, c_flag = 0, fd,tw_cnt = 0, tl_cnt = 0, tc_cnt = 0;
	char ch;
        int w_c = 0, l_c = 0, c_c = 0;

	while ((ch = getopt(argc,argv,"lwc")) != -1)
	{
		switch(ch)
		{ 
			case 'l':
				l_flag = 1;
				break;
			case 'w':
				w_flag = 1;
				break;
			case 'c':
				c_flag = 1;
				break;
		}
	}	
	if (argv[optind] == NULL)               //User Not passing files
	{
		my_wc(0,&w_c, &l_c, &w_c);	
		printf("%d %d %d\n", w_c, l_c, c_c);
	}
	else                                //User passing files
	{
		for (int i = 1; argv[i] != NULL; i++)
		{
			//open files
			fd = open(argv[i], O_RDONLY);
			if (fd != -1)
			{
	        		w_c=0;
				l_c=0;
       			c_c=0;

				//call my_wc
				my_wc(fd,&w_c,&l_c,&c_c);

				//print line,word,char count
				tw_cnt = tw_cnt+w_c;
				tl_cnt = tl_cnt+l_c;
				tc_cnt = tc_cnt+c_c;
				
				if (l_flag && c_flag && w_flag)
				{
					printf("%d %d %d\t%s\n",w_c,l_c,c_c,argv[i]);
				}

			else if (l_flag && w_flag)
				printf("%d %d\t%s\n",l_c,w_c,argv[i]);

			else if (w_flag && c_flag)
				printf("%d %d\t%s\n",w_c,c_c,argv[i]);

			else if (l_flag && c_flag)	
				printf("%d %d\t%s\n",l_c,c_c,argv[i]);

			else if (l_flag)
				printf("%d\t%s\n",l_c,argv[i]);

			else if (w_flag)
				printf("%d\t%s\n",w_c,argv[i]);

			else if (c_flag)
				printf("%d\t%s\n",c_c,argv[i]);

			else
				printf("%d %d %d\t%s\n",w_c,l_c,c_c,argv[i]);
			}		
		}
		//print total count
			
		if (l_flag && c_flag && w_flag)
			printf("%d %d %d\ttotal\n",tw_cnt,tl_cnt,tc_cnt);
		
		else if (l_flag && w_flag)
			printf("%d %d\ttotal\n",tl_cnt,tw_cnt);

		else if (w_flag && c_flag)
			printf("%d %d\ttotal\n",tw_cnt,tc_cnt);

		else if (l_flag && c_flag)
			printf("%d %d\ttotal\n",tl_cnt,tc_cnt);

		else if (l_flag)
			printf("%d\ttotal\n",tl_cnt);

		else if (w_flag)
			printf("%d\ttotal\n",tw_cnt);

		else if (c_flag)
			printf("%d\ttotal\n",tc_cnt);

		else
			printf("%d %d %d\ttotal\n",tw_cnt,tl_cnt,tc_cnt);

	}
}
void my_wc(int fd,int *w_c,int *l_c,int *c_c) 
{
	char ch,p;
	while(read(fd,&ch,1)>0)
	{
		(*c_c)++;
        if(ch==' '||ch=='\t'||ch=='\n')
        {
            if(p!=' '&&p!='\t') 
            {
                (*w_c)++;
            }
        }
        if(ch=='\n')
        {
            (*l_c)++;
        }
        p=ch;
	}
}
