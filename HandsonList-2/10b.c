/*
==================================================================================================================================
Name: 10.c
Author: Anuja Jose
Description: Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("\nCAUGHT SIGNAL %d (SIGINT)", signum);
    exit(0);
}

int main() {
    struct sigaction sa;
    printf("Press Ctrl+C to interrupt");
    fflush(stdout);
    sa.sa_sigaction = sigsegv_handler;
   
    sigaction(SIGINT, &sa, NULL);
    while(1)
    {
        sleep(1);
    }

    return 0;
}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Press Ctrl+C to interrupt^C
CAUGHT SIGNAL 2 (SIGINT)

*/