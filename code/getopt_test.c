#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#define _GNU_SOURCE
#define COPYRIGHT "VVSSH Copyright (C) 2015, V.V wlsdhzy@163.com\n"

int help(void){
        printf("Options:\n\t");
        printf("-h,\t--hostname\t\t\tTarget host name.\n\t");
        printf("-i,\t--ipaddr\t\t\tTarget host ip.\n\t");
        printf("-u,\t--user\t\t\t\tTarget host user.\n\t");
        printf("-p,\t--password\t\t\tTarget host user.\n\t");
        printf("-r,\t--role=[description]\t\tTarget host description.\n\t");
        printf("-H,\t--help\t\t\t\tPrintf help info.\n");
        printf("\n\nUsage:\n\t");
        printf("First login: vvssh -h test1 -i 127.0.0.1 -u root -p root [--role=role]\n\t");
        printf("Later login: vvssh -h test1\n\t");
        printf("             vvssh -i ipaddr\n\n");
        printf("For more see source code.\n");
        printf(COPYRIGHT);
        return 0;
}

int main(int argc,char *argv[]){
	int opt;
	char *hostname=NULL;
	char *ipaddr=NULL;
	char *user=NULL;
	char *password=NULL;
	char *role=NULL;
	struct option longopts[]={
		{"hostname",1,NULL,'h'},
		{"ipaddr",1,NULL,'i'},
		{"user",1,NULL,'u'},
		{"password",1,NULL,'p'},
		{"role",1,NULL,'r'},
		{"help",0,NULL,'H'},
		{0,0,0,0}
	};

	if(argc<2){
		help();
		return 1;
	}
	while((opt=getopt_long(argc,argv,":h: :i: :u: :p: :r: H",longopts,NULL)) != -1){
		switch(opt){
		case 'h':
			hostname=optarg;
			printf("hostname:%s\n",hostname);
			break;
		case 'i':
			ipaddr=optarg;
			printf("ipaddr:%s\n",ipaddr);
			break;
		case 'u':
			user=optarg;
			printf("user:%s\n",user);
			break;
		case 'p':
			password=optarg;
			printf("password:%s\n",password);
			break;
		case 'r':
			role=optarg;
			printf("role:%s\n",role);
			break;
		case 'H':
			help();
			break;
		case ':':
			printf("option needs a value\n");
			break;
		case '?':
			printf("unknown option:%c\n",optopt);
			break;
		}
	}
	for(;optind<argc;optind++)
		printf("argument:%s\n",argv[optind]);
	exit(0);
}
