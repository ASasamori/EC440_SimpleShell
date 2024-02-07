#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"
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
        }
        status = evaluate(line);

    } while (status);
}

int main(int argc, char **argv)
{
    shellLoop();
    return EXIT_SUCCESS;
}