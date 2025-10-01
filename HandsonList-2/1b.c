/*
==================================================================================================================================
Name: 1.c
Author: Anuja Jose
Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 23th Sep, 2025
==================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void timer_handler(int sig) {
    printf("ITIMER_VIRTUAL expired... Signal = %d\n", sig);
}

int main() {
    signal(SIGVTALRM, timer_handler);
    struct itimerval timer;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    for (volatile int i = 0; ; i++);
    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
ITIMER_VIRTUAL expired... Signal = 26
ITIMER_VIRTUAL expired... Signal = 26
*/