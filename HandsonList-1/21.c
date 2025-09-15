/*
==================================================================================================================================
Name: 21.c
Author: Anuja Jose
Description: Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2025
==================================================================================================================================
*/



#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main()
{
    pid_t pid; 
    pid=fork();
    if(pid>0)
        printf("Parent Process_id:%d",getpid());
    else if(pid==0)
        printf("\nChild Process: ID: %d\n",getpid());
    else
        printf("An error occured! Please try later.\n");

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Parent Process_id:76483
Child Process: ID: 76484



*/