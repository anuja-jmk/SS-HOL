/*
==================================================================================================================================
Name: 13a.c
Author: Anuja Jose
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int signum) {
    printf("SIGSTOP signal caught: %d\n", signum);
}

int main() {
  
    signal(SIGSTOP, sigstop_handler);
    printf("Waiting for SIGSTOP...pid: %d\n",getpid());

    while(1) {
        sleep(1);
    }

    return 0;
}




/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Waiting for SIGSTOP...pid: 58477

[1]+  Stopped                 ./a.out
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 


anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 58477
Sending SIGSTOP to process 58477
SIGSTOP sent.
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/