#include "main.h"
int pid;
//get command function
void get_command(char *input,char *cmd[])
{
    int i=0;
    char *token =strtok(input," ");
    while(token != NULL)
    {
        cmd[i]= malloc(sizeof(char)*strlen(token)+1);
        strcpy(cmd[i],token);
        token = strtok(NULL," ");
        i++;
    }
}
//function to execute external command
int execute_external_command(char *input)
{
     pid=fork();
    if(pid == 0)
    {
        char *cmd[10] ={NULL};
        get_command(input,cmd);
        execvp(cmd[0],cmd);
        perror("Command not found");
    }
    else
    {
        int status,exit_status=0;
        waitpid(pid,&status,WUNTRACED | WCONTINUED);
        if(WIFEXITED(status))
        {
            exit_status = WEXITSTATUS(status);
            printf("THe child %d terminated normally with %d\n",pid,exit_status);
            return exit_status;
        }
        else if(WIFSIGNALED(status))
        {
            exit_status=WTERMSIG(status);
            printf("The child %d terminated by the signal %d\n",pid,exit_status);
            return 128+exit_status;
        }
        else
        {
            printf("The child %d terminated abnormally\n",pid);
        }
    }
}
