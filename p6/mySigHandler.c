////////////////////////////////////////////////////////////////////////////////
// Main File:        mySigHandler.c
// This File:        mySigHandler.c
// Other Files:      division.c sendsig.c
// Semester:         CS 354 Fall 2022
//
// Author:           Wenpei Shao
// Email:            wshao33@wisc.edu
// CS Login:         wshao33
//
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int times = 4;
int count_c = 0;

void alarm_handler(int sig){
	pid_t pid = getpid();
	time_t now;
	if (time(&now) == -1) 
	{
		printf("ERROR\n");
		exit(0);
	}


	printf("PID: %d | Current time: %s", pid, ctime(&now));	

	struct sigaction act_alarm;
 
       	memset (&act_alarm, 0, sizeof(act_alarm));
	act_alarm.sa_handler = alarm_handler;
  
 
       	if (sigaction(SIGALRM, &act_alarm, NULL) < 0){	
                printf("Can't handle SIGALRM\n");
                exit(0); 
  }

	alarm(times);
}


void c_handler(int sig){
	printf("\nSIGINT handled.\n");
	printf("SIGUSR1 was handled %d times. Exiting now.\n",count_c);
	exit(0);
}

void usr1_handler(int sig){
	
	printf("SIGUSR1 handled and counted!\n");
	count_c++;
        struct sigaction act_usr1;
        memset(&act_usr1, 0, sizeof(act_usr1));
        act_usr1.sa_handler = usr1_handler;
        act_usr1.sa_flags = 0;
        if(sigaction(SIGUSR1, &act_usr1, NULL) < 0){
                printf ("Can't handle SIGUSR1");
                exit(0);
        }

}

int main(int argc, char *argv[]){

	printf("PID and time print every 4 seconds.\n");
	printf("Type Ctrl-C to end the program.\n");
	
	struct sigaction act_alarm;
	memset(&act_alarm, 0, sizeof(act_alarm));
	act_alarm.sa_handler = alarm_handler;
	act_alarm.sa_flags = 0;
	if(sigaction(SIGALRM, &act_alarm, NULL) < 0){
		printf ("Can't handle SIGALRM");
                exit(0);
	}
	alarm(times);
	
//	struct sigactoion act;
//	memset (&act, 0, sizeof(act));
	/*
	if(alarm(times)!=0){
		printf("Alarm error.\n");
		exit(0);
		
	}
	
	*/


        struct sigaction act_usr1;
        memset(&act_usr1, 0, sizeof(act_usr1));
        act_usr1.sa_handler = usr1_handler;
        act_usr1.sa_flags = 0;
        if(sigaction(SIGUSR1, &act_usr1, NULL) < 0){
                printf ("Can't handle SIGUSR1");
                exit(0);
        }

        struct sigaction act_c;
        memset(&act_c, 0, sizeof(act_c));
        act_c.sa_handler = c_handler;
        act_c.sa_flags = 0;
        if(sigaction(SIGINT, &act_c, NULL) < 0){
                printf ("Can't handle SIGINT");
                exit(0);
        }
	

	while(1);
}
