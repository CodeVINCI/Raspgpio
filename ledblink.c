#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *sd;
	int flag=0,count=0;

	dir = opendir("/sys/class/gpio");
	if(dir == NULL)
		{
			printf("Unable to open the directory\n");
		}
	while((sd=readdir(dir)) != NULL)
		{
			if(strcmp(sd->d_name,"gpio4")==0)
			{
				flag =1;
				break;
				closedir(dir);
			}
		}
	if(flag == 0)
		{
			system("echo 4 > /sys/class/gpio/export");
			printf("done exporting gpio4\n");
		}

	system("echo out > /sys/class/gpio/gpio4/direction");
	

	while(count < 10)
	{
	   system("echo 1 > /sys/class/gpio/gpio4/value");
	   sleep(1);
	   system("echo 0 > /sys/class/gpio/gpio4/value");
	   sleep(1);
	count++;
	}
	return 0;

}


