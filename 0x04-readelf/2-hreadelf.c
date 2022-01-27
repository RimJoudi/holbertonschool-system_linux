#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Program that displays the information contained in the ELF file
 * @argc: arg counter
 * @argv: arg vector
 * @env: enviroment variable
 * Return: success or failure
 */
int main(int argc, char **argv, char **env)
{
	char *com[] = {"/usr/bin/readelf", "-W", "-l", "", NULL};

	(void)argc;
	com[3] = argv[1];
	if (execve("/usr/bin/readelf", com, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
