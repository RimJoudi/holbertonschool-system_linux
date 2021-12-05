#include "hls.h"
#include <string.h>
/**
 * hls - ls recreated function
 * @dir: file stream
 * @op_a: hidden files option
 * @op_l: long format option
 * @op_1: one by line option
 * return: void
 */

void hls(const char *dir, int op_a, int op_l, int op_1)
{
	struct dirent *read;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		handle_error(dir);
	}
	while ((read = readdir(dh)) != NULL)
	{
		if (!op_a && read->d_name[0] == '.')
			continue;
		if (!op_l)
			printf("%s ", read->d_name);
		if (op_1)
			printf("\n");
		if (op_l)
		{
			op_longformat(read);
		}
	}
	if (!op_1 && !op_l)
		printf("\n");
}
