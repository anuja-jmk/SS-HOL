/*
==================================================================================================================================
Name: 8a.c
Author: Anuja Jose
Description: Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sigsev_handler(int signum)
{
    printf("CAUGHT SIGNAL %d.(Segmentation fault)\n",signum);
    exit(1);
}

void main()
{
    signal(SIGSEGV,sigsev_handler);

    int *ptr = NULL;
    *ptr = 42; 
    printf("Continuing after catching signal..");

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
CAUGHT SIGNAL 11.(Segmentation fault)
*/