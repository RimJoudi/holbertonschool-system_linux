#include "hls.h"
/**
 * main- main fn
 * @argc: arg count
 * @argv: arg vector
 * return: int
 */
int main(int argc, const char *argv[])
{
	int op_a = 0, op_l = 0, op_1 = 0;
	char *p = (char *) (argv[1] + 1);

	if (argc == 1)
		hls(".", 0, 0, 0);
	else if (argc == 2)
	{
		if (argv[1][0] == '-') /*checking if option is passed*/
		{

			while (*p)
			{
			   if (_strcmp(p, "a") == 0)
					op_a = 1;
				else if (_strcmp(p, "l") == 0)
					op_l = 1;
				else if (_strcmp(p, "1") == 0)
					op_1 = 1;
				else
				{
					perror("Unhandled operator");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			hls(".", op_a, op_l, op_1);
		}
			else
			{
				hls(argv[1], 0, 0, 0);
			}
	}
			else if (argc == 3)
			{
				if (argv[1][0] != '-')
				{
					perror("Incorrect usage");
					exit(EXIT_FAILURE);
				}
				

				while (*p)
				{
					if (_strcmp(p, "a") == 0)
						op_a = 1;
					else if (_strcmp(p, "l") == 0)
						op_l = 1;
					else if (_strcmp(p, "1") == 0)
						op_1 = 1;
					else
					{
						perror("Unhandled operator");
						exit(EXIT_FAILURE);
					}
					p++;
				}
				hls(argv[2], op_a, op_l, op_1);
			}
	return (0);
}
