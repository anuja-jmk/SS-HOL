/*
==================================================================================================================================
Name: 8b.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.

b. SIGINT

Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sigint_handler(int signum)
{
    printf("CAUGHT SIGNAL %d.(SIGINT)\n",signum);
    exit(1);
}

void main()
{
    signal(SIGINT,sigint_handler);
    printf("Press Ctrl+C to trigger SIGINT...\n");

    for(;;)
        ;
    printf("Continuing after catching signal..");

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Press Ctrl+C to trigger SIGINT...
^CCAUGHT SIGNAL 2.(SIGINT)
*/