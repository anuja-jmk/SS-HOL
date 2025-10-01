/*
==================================================================================================================================
Name: 8d.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.

d. SIGALRM (use alarm system call)

Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sigalrm_handler(int signum)
{
    printf("CAUGHT SIGNAL %d.(SIGALRM)\n",signum);
    exit(1);
 
}

void main()
{
    signal(SIGALRM,sigalrm_handler);
    printf("Alarm for 4 seconds\n");
    alarm(4);
    while (1) {
        pause(); 
    }

    printf("Continuing after catching signal..");

}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Alarm for 4 seconds
CAUGHT SIGNAL 14.(SIGALRM)

*/