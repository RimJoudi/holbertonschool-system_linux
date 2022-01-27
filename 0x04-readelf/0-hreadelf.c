#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - displays the information contained in the ELF sections' headers
 * @argc: arg counter
 * @argv: arg vector
 * @env: enviroment variable
 * Return: success or failure
 */
int main(int argc, char **argv, char **env)
{
	char *command[] = {"/usr/bin/readelf", "-W", "-h", "", NULL};

	(void)argc;
	command[3] = argv[1];
	if (execve("/usr/bin/readelf", command, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}