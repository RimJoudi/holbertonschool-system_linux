#ifndef H_LS_
#define H_LS_

#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/types.h>

#include <errno.h>

#include <string.h>


#include <err.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <inttypes.h>




void hls(const char *dir, int op_a, int op_l, int op_1);
int main(int argc, const char *argv[]);
void op_longformat(struct dirent *read);





#endif