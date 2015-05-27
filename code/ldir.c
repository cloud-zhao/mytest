#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

static int ifdir(const char *path){
	struct stat st;
	stat(path,&st);
	if(S_ISDIR(st.st_mode))
		return 1;
	else if(S_ISREG(st.st_mode))
		return 0;
	else
		return -1;
}

static int ptype(char *path){
	char lp[1024];

	if(ifdir(path)==1){
		DIR *dir=NULL;
		struct dirent *entry;

		if((dir=opendir(path))==NULL)
			return 1;
		while(entry=readdir(dir))
			if(strcmp(entry->d_name,".")&&strcmp(entry->d_name,"..")){
				strcpy(lp,path);
					if(lp[strlen(lp)-1]=='/')
						lp[strlen(lp)-1]='\0';
				strcat(lp,"/");
				strcat(lp,entry->d_name);
				ptype(lp);
			}
	}else if(ifdir(path)==0){
		printf("%s\n",path);
	}
	return 0;
}

int main(int argc,char **argv){
	
	ptype(argv[1]);
	return 0;
}
