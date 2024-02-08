#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"

// Assigned global variables for the File Descriptors
#define READ_END 0
#define WRITE_END 1

void execute(struct pipeline *pipeline)
{
    // fd standing for file descriptor, being array with len() of 2 for read/write.
    int fd[2];

    pid_t pid;
    int inputFd = 0;
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
            }
            if (command->redirect_out_path != NULL)
            {
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

            if (execvp(command->command_args[0], command->command_args) < 0)
            {
                perror("my_shell");
                exit(1);
            }
        }
        else
        {
            // Want the parent to wait for its child to finish
            wait(NULL);
            if (inputFd != 0)
            {
                close(inputFd);
            }

            close(fd[WRITE_END]);

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
        printf("my_shell$ ");
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
    shellLoop();
    return EXIT_SUCCESS;
}