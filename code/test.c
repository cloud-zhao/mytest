#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

char* test(char *tt){
	return tt;
}

typedef char *AS[100];

typedef struct text
{
	char *a1[10];
}Text;

Text* init_text(void){
	Text *pt=(Text*)malloc(sizeof(Text));
	int i=0;
	for(;i<10;i++)
		pt->a1[i]=(char*)malloc(sizeof(char));
	return pt;
}

int free_text(Text *pt){
	int i=0;
	for(;i<10;i++)
		free(pt->a1[i]);
	free(pt);
	return 0;
}

char** init_pp(void){
	int i;
	char **p1;
	p1=(char **)malloc(sizeof(char*)*100);
	for(i=0;i<100;i++)
		(*(p1+i))=(char *)malloc(sizeof(char));
	return p1;
}

int init_pp2(char **p1){
	int i;
	for(i=0;i<100;i++)
		(*(p1+i))=(char *)malloc(sizeof(char));
	return 0;
}

int free_pp(char **pps){
	int j=0;
	for(j=0;j<100;j++)
		free((*(pps+j)));
	return 0;
}

int main(void){
	Text *ptt=NULL;
	ptt=init_text();
	strcpy(ptt->a1[0],test("aas"));

	printf("t1->a2[1]:%s\n",ptt->a1[0]);
	free_text(ptt);
	char **p=init_pp();
	int i=0;
	int jp=10;
	for(;i<jp;i++)
		strcpy(p[i],test("fffgaaaaaaaaaaaaa"));
	for(i=0;i<jp;i++)
		printf("\t%s\n",p[i]);

	free_pp(p);
	return 0;
}
