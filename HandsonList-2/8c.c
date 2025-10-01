/*
==================================================================================================================================
Name: 8c.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.

c. SIGFPE

Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sigfpe_handler(int signum)
{
    printf("CAUGHT SIGNAL %d.(SIGFPE)\n",signum);
    exit(1);
}

void main()
{
    signal(SIGFPE,sigfpe_handler);
    int h = 0;
    int x = 2/h;
    printf("Continuing after catching signal..");

}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
CAUGHT SIGNAL 8.(SIGFPE)
*/