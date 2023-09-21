////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
// Other Files:      division.c sendsig.c
// Semester:         CS 354 Fall 2022
//
// Author:           Wenpei Shao
// Email:            wshao33@wisc.edu
// CS Login:         wshao33
//
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>    
#include <sys/types.h>
int main(int argc, char *argv[]){
	
	if(argc != 3){
		printf("Usage: sendsig <signal type> <pid>\n");
		exit(0);
	}
	char *optstr = "u:i:";
        int opt;
	int pid = atoi (argv[2]);


	while((opt = getopt(argc,argv,optstr)) != -1){
                switch(opt){
                        case 'u':
			       	kill(pid,SIGUSR1);
                                break;
                        case 'i':
                              	kill(pid,SIGINT);
                                break;
                        default:
	   			printf("Usage: sendsig <signal type> <pid>\n");
			   	exit(0);  
                }
        }

}
