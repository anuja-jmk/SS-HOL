/*
==================================================================================================================================
Name: 10.c
Author: Anuja Jose
Description: Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("\nCAUGHT SIGNAL %d (SIGFPE)", signum);
    exit(0);
}

int main() {
    struct sigaction sa;
    printf("Trying division by zero..");
    fflush(stdout);
    sa.sa_sigaction = sigsegv_handler;
   
    sigaction(SIGFPE, &sa, NULL);
    int x = 0;
    int h = 2/x;

    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Trying division by zero..
CAUGHT SIGNAL 8 (SIGFPE)a
*/