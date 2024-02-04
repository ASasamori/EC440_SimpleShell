#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myshell_parser.h"

void shellLoop()
{
}

// create a simple ls command working.
// one pipe two children to pipe with ls count working
// Even though can't fork one process and wait for it to complete
// Duping with the children.
// waiting for that to complete and read side of the pipe
// wc command in the sam example
// Close the write side of the pipe
// Run it in parallel, going to block and run it in the back
// While still child outstanding.
// Wait pid while child is waiting
// close the pipe so the parent is doing the pipe command
// Make sure to not blindly malloc a command to make sure it works
// Redirect need to use dupe

int main(int argc, char **argv)
{
    shellLoop();
    return EXIT_SUCCESS;
}