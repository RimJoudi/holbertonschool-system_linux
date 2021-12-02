#include "hls.h"
/**
 * op_longformat - long format option fn
 * @read: struct dirent
 * return: void
 */


void op_longformat(struct dirent *read)
{
    //struct dirent *read;
   // DIR *dh = opendir(dir);
    struct stat fileStat;
   // char fullpath[256];
    char time[24];
    struct group *grp; //struct group *getgrgid(gid_t gid); // hall search the group database for an entry with a matching gid.
	struct passwd *usr; //struct passwd *getpwuid(uid_t uid);
                        //The getpwuid() function shall search the user database for an entry with a matching uid
/*
    if (argc != 2)
    {
        perror("Please supply a folder name\n");
        exit(-1);
    }
*/
   /*if ((dh=opendir(argv[1])) == NULL)
    {
        perror("Error in opendir");
        exit(-1);
    } */

    //while ((read = readdir(dh)) != NULL)
   // {
       // printf ("%s ", read->d_name);
        strncpy(time, ctime(&fileStat.st_mtime), 24);
       // strcpy (fullpath, argv[1]);
        //strcat (fullpath, "/");
       // strcat (fullpath, read->d_name);
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
      /*  } else
        {
            perror("Error in stat");
        }
        printf("\n");
    }
    closedir(dh);*/
    
}

