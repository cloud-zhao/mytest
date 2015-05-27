#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){

	char buf[1024];
	int count=readlink("/proc/self/exe",buf,sizeof(buf));
	if(count<0 || count>=1024)
		return 1;
	char *rb=strrchr(buf,'/');
	if(rb==NULL){
		printf("error\n");
		return 1;
	}
	buf[count-strlen(rb)+2]='\0';

	strcat(buf,"../data/file.txt");
	printf("%s\n",buf);

	char data[100]="abcdef";
	printf("%d\n",(int)strlen(data));
	data[strlen(data)-1]='\0';
	printf("%s\n",data);

	/*
	getcwd(buf,sizeof(buf));
	printf("Current working:%s\n",buf);

	char content[256];

	while(fgets(content,256,stdin)!=NULL){
		int len=strlen(content);
		if(content[len-1]=='\n')
			content[len-1]='\0';
			printf("%s\t",content);
	}
	*/

	return 0;
}

