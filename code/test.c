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

char **init_pp(void){
	int i;
	char **p1;
	p1=(char**)malloc(sizeof(char*));
	for(i=0;i<100;i++)
		p1[i]=(char *)malloc(sizeof(char));
	return p1;
	//p1->*p1+i->**p1
}

int free_pp(char **pps){
	int i=0;
	printf("free pps\n");
	free(pps);
	printf("free *pps\n");
	/*for(;i<100;i++)
		free((char*)pps[i]);*/
	printf("free ok\n");
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
	for(;i<3;i++)
		strcpy(*(p+i),test("fffg"));
	for(i=0;i<3;i++)
		printf("\t%s\n",*(p+i));

	free_pp(p);
	return 0;
}
