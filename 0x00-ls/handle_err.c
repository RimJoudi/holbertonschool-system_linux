#include "hls.h"
/*
 * handle_error - to handle error message fn
 * @filename: name of the file/dir
 * return: void
 */
void handle_error(const char *filename)
{
    if (errno == ENOENT)
    {
        fprintf(stderr, "hls: cannot access '%s': Permission denied", filename);
       
       // perror("directory doesn't exist");

    }
		
	else if (errno == EACCES)
	{
        fprintf(stderr, "hls: cannot open directory '%s': No such file or directory", filename);
            //perror("enable to read directory");
	}
	//perror("");
    //exit(EXIT_FAILURE);
}
