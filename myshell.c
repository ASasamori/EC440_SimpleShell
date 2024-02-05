#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"
evaluate(char *line)
{
    struct pipeline *pipeline = pipeline_build(line);

    if (pipeline != NULL && strcmp(pipeline->commands->command_args[0], "ls") == 0)
    {
        execute(pipeline);
    }
    else
    {
        printf("Command not supported: \n");
    }
    // err = execvp(command->command_args[0],command->command_args);
    // Supports all these commands
    pipeline_free(pipeline);
}

// Nested function only for usage of evaluate()
void execute(struct pipeline *pipeline)
{
    pid_t pid = fork();
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