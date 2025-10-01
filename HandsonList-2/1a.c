/*
==================================================================================================================================
Name: 1.c
Author: Anuja Jose
Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
==================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("ITIMER_REAL expired.. Signal = %d\n", sig);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handler);
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    setitimer(ITIMER_REAL, &timer, NULL);
    while (1) {
        pause();
    }

    return 0;
}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
ITIMER_REAL expired.. Signal = 14
ITIMER_REAL expired.. Signal = 14


*/
