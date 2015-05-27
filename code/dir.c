#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc,char **argv){
	DIR *dir;
	struct dirent *entry;

	if((dir=opendir(argv[1]))==NULL)
		return 1;
	else
		while(entry=readdir(dir))
			if(strcmp(entry->d_name,".")&&strcmp(entry->d_name,".."))
				printf("%s\n",entry->d_name);
	return 0;
}
