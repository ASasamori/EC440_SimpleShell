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
}

void execute(struct pipeline *pipeline)
{
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
        read = readline();
        evaluate = evaluate();
        // print = print();

    } while (status);
}

int main(int argc, char **argv)
{
    shellLoop();
    return EXIT_SUCCESS;
}