/*
==================================================================================================================================
Name: 10.c
Author: Anuja Jose
Description: Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("CAUGHT SIGNAL %d (SIGSEGV)\n", signum);
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_sigaction = sigsegv_handler;
   
    sigaction(SIGSEGV, &sa, NULL);

    int *ptr = NULL;
    *ptr = 42;

    return 0;
}




/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
CAUGHT SIGNAL 11 (SIGSEGV)
*/