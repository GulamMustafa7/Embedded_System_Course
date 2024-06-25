#include "main.h"

// Define the structure of a node
struct Node 
{
    int pid;
    char state[20]; // Added state member
    char process_name[100]; // Added process_name member
    char priority; // Added priority member
    int process_num; // Added process_num member
    struct Node* next;
};

struct Node* stopped_processes = NULL;

// Function to create a new node
struct Node* createNode(int pid) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->pid = pid;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d\n", current->pid);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}


// Function to insert a new node at the end of the linked list
void insertNode(int pid)
{
    struct Node* newNode = createNode(pid);
    if (stopped_processes == NULL)
    {
        stopped_processes = newNode;
        printf("Added process with PID %d\n", pid);
    }
    else
    {
        struct Node* current = stopped_processes;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        printf("Added process with PID %d\n", pid);
    }
}

// Function to print the list of stopped processes
void print_jobs() {
    struct Node* current = stopped_processes;
    int count = 1;

    printf("List of stopped processes:\n");
    while (current != NULL) {
        printf("[%d] PID: %d\n", count++, current->pid);
        current = current->next;
    }
}


int fg_bg(char* buff) {
    struct Node* ptr = stopped_processes;

    // Foreground process
    if (strcmp(buff, "fg") == 0) {
        if (ptr == NULL)
            printf("No process in foreground\n");

        while (ptr != NULL && ptr->priority != '+')
            ptr = ptr->next;

        if (ptr != NULL) {
            // Update the state
            strcpy(ptr->state, "Running");
            printf("%s\n", ptr->process_name);

            // Send continue signal
            kill(ptr->pid, SIGCONT);
        }
    }

    // Background process
    else if (strcmp(buff, "bg") == 0) {
        if (ptr == NULL)
            printf("No process in background\n");
        else {
            while (ptr != NULL && ptr->priority != '+')
                ptr = ptr->next;

            if (ptr != NULL) {
                // Update the state
                strcpy(ptr->state, "Running");

                printf("[%d]%c\t%s\n", ptr->process_num, ptr->priority, ptr->process_name);

                // Send continue signal
                kill(ptr->pid, SIGCONT);
            }
        }
    }

    // Jobs system call
    else if (strcmp(buff, "jobs") == 0) {
        // Print the list
        print_jobs();
    }

    else
        return 0;

    return 1;
}

