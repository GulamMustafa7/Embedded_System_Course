#include "main.h"

int cmd_idx;

char *internal_cmd[] = {"cd","pwd","exit","fg","bg","jobs",NULL};
int check_command_type(char *input)
{
    int j;
    char cmd[strlen(input)+1];
    for(j=0;input[j]!=' ' && input[j] != '\0';j++)
    {
        cmd[j]=input[j];
    }
    cmd[j] = '\0';
    for(int i=0;internal_cmd[i] != NULL;i++)
    {
        if(strcmp(cmd,internal_cmd[i])==0)
        {
            cmd_idx=i;
            return INTERNAL_CMD;
        }
    }
    return EXTERNAL_CMD;
}
