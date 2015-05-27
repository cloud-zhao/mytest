#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char **argv){
	struct stat st;
	printf("%s",argv[1]);
	stat(argv[1],&st);
	if(S_ISDIR(st.st_mode))
		printf(" is a dir\n");
	else if(S_ISREG(st.st_mode))
		printf(" is a file\n");
	else
		printf(" is not a file or dir\n");
	return 0;
}
