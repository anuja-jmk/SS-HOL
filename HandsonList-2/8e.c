/*
==================================================================================================================================
Name: 8e.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.

e. SIGALRM (use setitimer system call)

Date: 30th Sep, 2025
==================================================================================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<stdlib.h>
#include<signal.h>

void sigalrm_handler(int signum)
{

    printf("CAUGHT SIGNAL from setitimer %d.(SIGALRM)\n",signum);
    exit(1);
 
}

void main()
{
    signal(SIGALRM,sigalrm_handler);

    struct itimerval timer;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    setitimer (ITIMER_REAL, &timer, 0);

    printf("Alarm for 2 seconds\n");
    while (1) {
        pause(); 
    }

    printf("Continuing after catching signal..");

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Alarm for 2 seconds
CAUGHT SIGNAL from setitimer 14.(SIGALRM)
*/