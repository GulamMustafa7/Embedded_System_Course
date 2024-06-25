#include "main.h"

extern int  cmd_idx;

int execute_internal_command(char *input)
{
    //cd,pwd,fg,bg,jobs
    switch (cmd_idx)
    {
        //input: cd /home/user
        case 0://cd
            if(chdir(input+3) == -1)
                return errno;
            break;
        case 1: //pwd
            printf("%s\n",get_current_dir_name());
            break;
        case 3: //fg
            fg_bg(input);
            break;
        case 4: //bg
            fg_bg(input);
            break;
        case 5://jobs
            fg_bg(input);
            break;
    }
    return 0;

}

