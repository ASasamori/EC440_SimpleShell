#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h> // Used for using the flags for redirection in/out?

#include "myshell_parser.h"

// Assigned global variables for the File Descriptors
#define READ_END 0
#define WRITE_END 1

char *prompt; // Global variable to help set the -n functionality and print myshell$

void execute(struct pipeline *pipeline)
{
    // fd standing for file descriptor, being array with len() of 2 for read/write.
    int fd[2];

    pid_t pid;
    int inputFd = 0;
    // int outputFd = 1; // Output File Descriptor, not sure why it is 1 though.
    // pipeline->commands is the next command in a pipeline. NULL if there is None.
    struct pipeline_command *command = pipeline->commands;

    // Provide looping to iterate over each command in pipeline
    while (command != NULL)
    {
        pipe(fd);

        if ((pid = fork()) == 0)
        {
            if (command->redirect_in_path != NULL)
            {
                inputFd = open(command->redirect_in_path, O_RDONLY);
                if (inputFd == -1)
                {
                    perror("my_shell");
                    exit(EXIT_FAILURE);
                }
                dup2(inputFd, STDIN_FILENO);
                close(inputFd);
            }
            if (command->redirect_out_path != NULL)
            {
                int outputFd = open(command->redirect_out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (outputFd == -1)
                {
                    perror("my_shell");
                    exit(1);
                }
                dup2(outputFd, STDOUT_FILENO);
                close(outputFd);
            }
            if (inputFd != 0)
            {
                dup2(inputFd, STDIN_FILENO);
                close(inputFd);
            }
            if (command->next != NULL)
            {
                dup2(fd[WRITE_END], STDOUT_FILENO);
                close(fd[WRITE_END]);
            }
            close(fd[READ_END]);
            close(fd[WRITE_END]); // Should catch the error in the redirection, now won't be displaying 2 error messages anymore

            if (execvp(command->command_args[0], command->command_args) < 0)
            {
                perror("my_shell");
                exit(1);
            }
        }
        else
        {
            if (pipeline->is_background)
            {
                printf("The pid of  %d is obviously running in the background because you appended an ampersand to the end.\n", pid);
            }
            else
            {
                // Want the parent to wait for its child to finish
                wait(NULL);
            }

            if (inputFd != 0)
            {
                close(inputFd);
            }
            close(fd[WRITE_END]);
            // Got rid of closing the inputFd, always just want to make sure can read the new input

            // Want the next child to read from the end
            inputFd = fd[READ_END];
            command = command->next;
        }
    }
}

int evaluate(char *line)
{
    struct pipeline *pipeline = pipeline_build(line);
    if (pipeline != NULL)
    {
        execute(pipeline);
        pipeline_free(pipeline);
        return 1; // Continue the shell loop
    }
    else
    {
        printf("Command not supported: \n");
        return 0; // Exit the shell loop
    }
}

void shellLoop()
{
    char line[MAX_LINE_LENGTH];
    int status = 1;

    do
    {
        printf("%s", prompt); // Had to look this up, don't really know how this will handle myshell -n but let's try
        fflush(stdout);
        if (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
        {
            // Remove newline character from end of line
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n')
            {
                line[len - 1] = '\0';
            }
            status = evaluate(line);
        }
        else
        {
            status = 0;
        }

    } while (status);
}

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
    {
        prompt = "";
    }
    else
    {
        prompt = "myshell$ ";
    }
    shellLoop();
    return EXIT_SUCCESS;
}