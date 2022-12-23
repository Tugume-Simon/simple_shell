#include "shell.h"

/**
 * main - simple shell programm
 *
 * Return: Always 0.
 */
int main(void)
{
	ssize_t res;
	size_t n;
	pid_t child;
	int status;
	char *argv[] = {NULL, NULL, NULL, NULL};

	child = fork();
	if (child == -1)
	{
		perror("Error");
		return (1);
	}
	if (child != 0)
		wait(&status);
	while (res != EOF)
	{
		printf("#cisfun$ ");
		res = _getline(&argv[0], &n, stdin);
		if (res == -1)
			break;
		if (res == 0)
			continue;
		if (*argv[0] != '\n')
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error");
			}
		}
	}
	/*free(lpr);*/

	return (0);
}
