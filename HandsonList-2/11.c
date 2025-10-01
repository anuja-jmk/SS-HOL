/*
==================================================================================================================================
Name: 11.c
Author: Anuja Jose
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



int main() {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sa, NULL);
    printf("Press Ctrl+C to interrupt. Ignoring interrupt for 5 seconds");
    fflush(stdout);
    sleep(5);
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
   
    printf("\n Resetting to default action on interrupt.Press Ctrl + C");
    fflush(stdout);

    while(1)
    {
        sleep(1);
    }

    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Press Ctrl+C to interrupt. Ignoring interrupt for 5 seconds^C^C^C^C^C
 Resetting to default action on interrupt.Press Ctrl + C^C
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/