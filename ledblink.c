#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *sd;
	dir = opendir("/sys/class/gpio");
	if(dir == NULL)
		{
			printf("Unable to open the directory");
		}
	while((sd=readdir(dir)) != NULL)
		{
			printf(">> %s\n",sd->d_name);
		}
	closedir(dir);
	return 0;

}


