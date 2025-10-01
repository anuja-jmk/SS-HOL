/*
==================================================================================================================================
Name: 12.c
Author: Anuja Jose
Description: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
pid_t pid;
pid = fork();  

if(pid == 0) {
    printf("Child process ID: %d \nParent Process ID: %d\n", getpid(),getppid());
    printf("\nKilling parent process");
    kill(getppid(), SIGKILL);
    sleep(5);
    printf("Orphan process ID: %d \nOrphan Parent Process ID: %d\n", getpid(),getppid());
}
else {
    printf("Parent process ID:%d\n", getpid());
     

}

return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Parent process ID:58322
Child process ID: 58323 
Parent Process ID: 58322

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ Killing parent processOrphan process ID: 58323 
Orphan Parent Process ID: 2193
*/