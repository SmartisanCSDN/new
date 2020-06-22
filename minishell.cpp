#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/wait.h>

char command[1024];

int getcommand()
{
	memset(command, '\0', sizeof(command));

	if(fgets(command, sizeof(command) - 1, stdin) == NULL)
	{
		printf("fgets error\n");
		return -1;
	}
	return 0;
}

int execcommand(char* argv[])
{
	if(argv[0] == NULL)
	{
		//printf("execcommand pram error\n");
		return -1;
	}
	//extern char** environ;
	pid_t pid = fork();
	if(pid < 0)
	{
		printf("create subprocess failed\n");
		return -1;
	}
	else if(pid == 0)
	{
		execvp(argv[0], argv);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

int dealcommand(char* command)
{
	if(!command || *command == '\0')
	{
		printf("command error\n");
		return -1;
	}

	int argc = 0;
	char* argv[1024] = { 0 };

	while(*command)
	{
		if(!isspace(*command) && *command != '\0')
		{
			argv[argc] = command;
			++argc;
			while(!isspace(*command) && *command != '\0')
				++command;
			*command = '\0';
		}
		++command;
	}

	argv[argc] = NULL;

	execcommand(argv);


	return 0;

}

int main()
{
	while(1)
	{
		printf("[test@localhost minishell]$ ");
		fflush(stdout);

		if(getcommand() == -1)
			continue;

		if(command[0] == 'q')
			break;

		dealcommand(command);
	}
	return 0;
}
