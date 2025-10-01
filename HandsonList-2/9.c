/*
==================================================================================================================================
Name: 9.c
Author: Anuja Jose
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>


void main()
{
  signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored for 10 seconds. Try pressing Ctrl+C...\n");
    sleep(10);


    signal(SIGINT, SIG_DFL);
    printf("SIGINT is now reset to default. Ctrl+C will terminate the program now.\n");

    while (1) {
        sleep(1);
    }

}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
SIGINT is now ignored for 10 seconds. Try pressing Ctrl+C...
^C^C^C^C^CSIGINT is now reset to default. Ctrl+C will terminate the program now.
^C

*/