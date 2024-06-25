//########################################################################################//

/*
* Name:         GulamMustafa Ibrahim Kazi.
* Date:
* Description:
* Sample input:
* Sample output:
*/

//########################################################################################//


#include "main.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

typedef struct Job {
    pid_t pid;
    char command[MAX_INPUT_SIZE];
    struct Job *next;
} Job;

Job *jobs_list = NULL;

void add_job(pid_t pid, char *command) {
    Job *job = malloc(sizeof(Job));
    job->pid = pid;
    strcpy(job->command, command);
    job->next = jobs_list;
    jobs_list = job;
}

void remove_job(pid_t pid) {
    Job *current = jobs_list;
    Job *previous = NULL;
    while (current != NULL) {
        if (current->pid == pid) {
            if (previous == NULL) {
                jobs_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void list_jobs() {
    Job *current = jobs_list;
    while (current != NULL) {
        printf("[%d] %s\n", current->pid, current->command);
        current = current->next;
    }
}

char prompt[MAX_INPUT_SIZE] = "msh> ";
int last_exit_status = 0;

void scan_input(char *prompt, char *input_string) {
    printf("%s", prompt);
    __fpurge(stdin);
    if (fgets(input_string, MAX_INPUT_SIZE, stdin) == NULL) {
        printf("\n");
        exit(0);
    }
    input_string[strcspn(input_string, "\n")] = 0; // Remove newline character
}

char *get_command(char *input_string) {
    char *command = strtok(input_string, " ");
    return command;
}

void copy_change(char *prompt, char *input_string) {
    strncpy(prompt, input_string, MAX_INPUT_SIZE);
}

int check_command_type(char *command) {
    if (strcmp(command, "exit") == 0) return BUILTIN;
    if (strcmp(command, "cd") == 0) return BUILTIN;
    if (strcmp(command, "echo") == 0) return BUILTIN;
    if (strcmp(command, "pwd") == 0) return BUILTIN;
    if (strcmp(command, "jobs") == 0) return BUILTIN;
    if (strcmp(command, "fg") == 0) return BUILTIN;
    if (strcmp(command, "bg") == 0) return BUILTIN;
    return EXTERNAL;
}

void echo(char *input_string) {
    char *arg = strtok(NULL, " ");
    if (arg == NULL) {
        printf("\n");
    } else if (strcmp(arg, "$?") == 0) {
        printf("%d\n", last_exit_status);
    } else if (strcmp(arg, "$$") == 0) {
        printf("%d\n", getpid());
    } else if (strcmp(arg, "$SHELL") == 0) {
        printf("%s\n", __FILE__);
    } else {
        printf("%s\n", input_string + 5); // Skip the 'echo ' part
    }
}

void execute_internal_command(char *input_string) {
    char *command = get_command(input_string);
    if (strcmp(command, "exit") == 0) {
        exit(0);
    } else if (strcmp(command, "cd") == 0) {
        char *path = strtok(NULL, " ");
        if (path == NULL) {
            path = getenv("HOME");
        }
        if (chdir(path) != 0) {
            perror("msh");
        }
    } else if (strcmp(command, "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("msh");
        }
    } else if (strcmp(command, "jobs") == 0) {
        list_jobs();
    } else if (strcmp(command, "fg") == 0) {
        // Bring job to foreground
    } else if (strcmp(command, "bg") == 0) {
        // Move job to background
    } else if (strcmp(command, "echo") == 0) {
        echo(input_string);
    }
}

void signal_handler(int sig_num) {
    signal(SIGINT, signal_handler);
    printf("\nCaught signal %d, but ignoring it.\n", sig_num);
    printf("%s", prompt);
    fflush(stdout);
}

void extract_external_commands(char **external_commands) {
    // Placeholder: You can implement external command parsing here if needed.
}

void execute_external_command(char *input_string, int background) {
    char *args[MAX_ARGS];
    char *token = strtok(input_string, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("msh");
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        if (!background) {
            waitpid(pid, &last_exit_status, 0);
        } else {
            add_job(pid, input_string);
            printf("[%d] %s\n", pid, input_string);
        }
    } else {
        perror("msh");
    }
}

void handle_ps1(char *input_string) {
    if (strncmp(input_string, "PS1=", 4) == 0) {
        strcpy(prompt, input_string + 4);
    } else {
        execute_internal_command(input_string);
    }
}

int main() {
    char input_string[MAX_INPUT_SIZE];
    char *command;
    int command_type;

    signal(SIGINT, signal_handler); // Register signal handler for Ctrl+C

    while (1) {
        scan_input(prompt, input_string);
        command = get_command(input_string);

        if (command == NULL) {
            continue;
        }

        if (strncmp(command, "PS1=", 4) == 0) {
            handle_ps1(input_string);
            continue;
        }

        command_type = check_command_type(command);

        switch (command_type) {
            case BUILTIN:
                execute_internal_command(input_string);
                break;
            case EXTERNAL: {
                int background = 0;
                if (input_string[strlen(input_string) - 1] == '&') {
                    background = 1;
                    input_string[strlen(input_string) - 1] = '\0';
                }
                execute_external_command(input_string, background);
                break;
            }
            case NO_COMMAND:
                printf("Command not found.\n");
                break;
        }
    }

    return 0;
}

