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
//////////////////////////// 80 columns wide //////////////////////////////////
#include <stdlib.h> 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <time.h> 
#include <string.h> 
#include <sys/types.h> 
int count = 0;
void int_handler(int sig){
	printf("\nTotal number of operations completed successfully: %d\n",count);
	printf("The program will be terminated.\n");
	exit(0);
}
void fpe_handler(int sig){
	printf("Error: a division by 0 operation was attempted.\n");
	printf("Total number of operations completed successfully: %d\n",count);
	printf("The program will be terminated.\n");

	exit(0);
}
int main(){
	struct sigaction s_int;
	struct sigaction s_fpe;
	memset(&s_int,0,sizeof(s_int));
	memset(&s_fpe,0,sizeof(s_fpe));
	s_int.sa_handler = int_handler;
	s_fpe.sa_handler = fpe_handler;
	if (sigaction(SIGINT, &s_int, NULL) < 0){
		printf ("Can't handle SIGINT");
                exit(0);
	}
 	if (sigaction(SIGFPE, &s_fpe, NULL) < 0){
                printf ("Can't handle SIGFPE");
                exit(0);
        }

	while(1){
	int a,b;
	printf("Enter first integer: ");
	//scanf("%d",&a);
	char buffer [100];
	fgets(buffer, 100, stdin);
	a = atoi(buffer);
	printf("Enter second integer: ");
	//scanf("%d",&b);
	fgets(buffer, 100, stdin);
	b = atoi(buffer);
	int d = a/b;
	int r = a%b;
	printf("%d / %d is %d with a remainder of %d\n", a, b, d, r);
	count++;	

	
	}
}

