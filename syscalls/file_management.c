#include<unistd.h>
#include<stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void main(int argc, char **args) {
	struct stat fileStat;
	
	if (argc < 2) {
		printf("Not File Provided\nExiting\n");
		_exit(-1);
	}
	
	char *filename = args[1];
	stat(filename, &fileStat);
	
	printf("Information for %s\n",filename);
	printf("----------------------------\n");
	printf("File Size        : %ld bytes\n", fileStat.st_size);
	printf("Number of Links  : %ld\n", fileStat.st_nlink);
	printf("File inode       : %ld\n", fileStat.st_ino);

	printf("File Permissions : ");
	printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf((fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n");

	printf("[ The file %s a symbolic link ]\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is NOT");
	printf("Last access time        : %s", ctime(&fileStat.st_atime)); 
	printf("Last modification time  : %s", ctime(&fileStat.st_mtime)); 
	printf("Last status change time : %s", ctime(&fileStat.st_ctime));
	
}
