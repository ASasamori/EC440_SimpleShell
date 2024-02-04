#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"

char *readline(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}
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

    pipeline_free(pipeline);
}

void execute(struct pipeline *pipeline)
{
    pid_t pid = fork();
}

// Just included print option to print but I don't know if this necessary so far
// printShell()
// {
// }

void shellLoop()
{
    char *line;
    char **args;
    int status = 1;

    do
    {
        printf("my_shell$ ");
        line = readline();
        evaluate(line);
        // print = print();

    } while (status);
}

int main(int argc, char **argv)
{
    shellLoop();
    return EXIT_SUCCESS;
}