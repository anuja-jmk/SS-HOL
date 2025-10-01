/*
==================================================================================================================================
Name: 8f.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.

f. SIGVTALRM (use setitimer system call)

Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<stdlib.h>
#include<signal.h>

void sigvtalrm_handler(int signum)
{

    printf("CAUGHT SIGNAL from setitimer %d.(SIGVTALRM)\n",signum);

 
}

void main()
{
    signal(SIGVTALRM,sigvtalrm_handler);

    struct itimerval timer;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    setitimer (ITIMER_VIRTUAL, &timer, 0);

    printf("Alarm for 2 seconds\n");
    while (1) {
        for (volatile int i = 0; i < 10; i++);
    }

    printf("Continuing after catching signal..");

}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ cc 8f.c 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Alarm for 2 seconds
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALRM)
CAUGHT SIGNAL from setitimer 26.(SIGVTALR
*/