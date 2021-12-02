#include "hls.h"
/**
 * op_longformat - long format option fn
 * @read: struct dirent
 * return: void
 */


void op_longformat(struct dirent *read)
{
	struct stat fileStat;
	char time[24];
	struct group *grp;
	/*struct group *getgrgid(gid_t gid); */
	/*search the group database for an entry with a matching gid.*/
	struct passwd *usr;
	/*struct passwd *getpwuid(uid_t uid);*/
	/*The getpwuid() searchs for user db for an entry with a matching uid*/

		_strncpy(time, ctime(&fileStat.st_mtime), 24);
		lstat(read->d_name, &fileStat);

			printf((S_ISDIR(fileStat.st_mode))  ? "d" : "-");
			printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
			printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
			printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
			printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
			printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
			printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
			printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
			printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
			printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

			usr = getpwuid(fileStat.st_uid);
			grp = getgrgid(fileStat.st_gid);

		printf(" %lu %s %s %li %s %s\n", fileStat.st_nlink, usr->pw_name,
		grp->gr_name, (intmax_t)fileStat.st_size, time, read->d_name);

}

