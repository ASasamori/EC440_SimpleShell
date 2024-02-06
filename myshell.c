#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"
int evaluate(char *line)
{
    struct pipeline *pipeline = pipeline_build(line);
    if (pipeline != NULL)
    {
        execute(pipeline);
    }
    else
    {
        printf("Command not supported: \n");
    }
    pipeline_free(pipeline);
}

// Nested function only for usage of evaluate()
void execute(struct pipeline *pipeline)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process to execute
        if (execvp(pipeline->commands->command_args[0], pipeline->commands->command_args) == -1)
        {
            perror("my_shell");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        // Error forking
        perror("my_shell");
    }
    else
    {
        // Parent process
        wait(NULL);
    }
}

void shellLoop()
{
    char **args;
    int status = 1;

    do
    {
        printf("my_shell$ ");
        pipeline_build(args);
        status = evaluate(args);

        pipeline_free(args);
        free(args);

    } while (status);
}

int main(int argc, char **argv)
{
    shellLoop();
    return EXIT_SUCCESS;
}