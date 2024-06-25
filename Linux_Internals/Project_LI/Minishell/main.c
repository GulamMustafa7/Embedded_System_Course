/*
Name:Mustafa Shaikh
Date:02/05/2024
Description:Minishell
*/

#include "main.h"

int exit_status = 0;
extern int pid;

/* Function definition of signal handler */
void signal_handler(int signum)
{
    if (pid > 0)
    {
        if (signum == SIGINT)
        {
            kill(pid , SIGINT);
            pid = 0;
            exit_status = 128 + SIGINT;
        }
        else if (signum == SIGTSTP)
        {
            insertNode(getpid());
            kill(pid , SIGTSTP);
            pid = 0;
            exit_status = 128 + SIGTSTP;

        }
    }
    printf("\n");

}

int main()
{
    char input[50], prompt[50] = "minishell";
    int ret = 0;

    //SIGNINT,SIGTSTP
    struct sigaction act;
    act.sa_handler = signal_handler;
    sigaction(SIGINT,&act,NULL);
    sigaction(SIGTSTP,&act,NULL);
    act.sa_handler = SIG_DFL;
    act.sa_flags = SA_NOCLDWAIT;
    sigaction(SIGCHLD, &act, NULL);


    while(1)
    {
        printf(ANSI_COLOR_BLUE"[%s]$" ANSI_COLOR_RESET, prompt);
        fgets(input, 50, stdin);
        input[strlen(input)-1] = '\0';

        if (*input == '\0')
        {
             continue;
        }
        else if (!strcmp(input, "exit"))
        {
            exit(EXIT_SUCCESS);
        }
        else if (!strcmp(input, "echo $?"))
        {
            printf("%d\n", exit_status);
        }
        else if (!strcmp(input, "echo $$"))
        {
            printf("%d\n", getpid());
        }
        else if (!strcmp(input,"echo $SHELL"))
        {
            printf("%s\n",get_current_dir_name());
        }
        else if (strncmp("PS1=", input, 4) == 0)
        {
            strcpy(prompt,input+4);
        }
        else if ((ret = check_command_type(input)) == EXTERNAL_CMD)
        {
            exit_status = execute_external_command(input);
        }
        else if (ret == INTERNAL_CMD)
        {
            exit_status = execute_internal_command(input);

        }
        else
        {
            printf("Command not found\n");
        }
        memset(input, 0, 50);
    }
}
