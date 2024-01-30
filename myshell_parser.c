#include "myshell_parser.h"
#include "stddef.h"

struct pipeline *pipeline_build(const char *command_line)
{
	// TODO: Implement this functio
	pid_t, cpid;
	int status = 0;
	cpid = fork();
	if (cpid < 0){
		perror("fork failed\n");
		exit(-1);
	}
	return NULL;
}

void pipeline_free(struct pipeline *pipeline)
{
	// TODO: Implement this function
}

//Created new pipeline command function to test functionality before
struct pipeline_command *command_build(const char *command_line)
{
  //Including a 'for' loop to look for the whitespaces and pipeline biulds
  return NULL;
}
