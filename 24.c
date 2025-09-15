/*
==================================================================================================================================
Name: 24.c
Author: Anuja Jose
Description: Write a program to create an orphan process.
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
pid_t pid;
pid = fork();  

if(pid == 0) {
    printf("Child process ID: %d \nParent Process ID: %d\n", getpid(),getppid());
    sleep(5);
    printf("Orphan process ID: %d \nOrphan Parent Process ID: %d\n", getpid(),getppid());
}
else {
    printf("Parent process ID:%d\n", getpid());
    exit(0);  

}

return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Parent process :38924
Child process ID: 38925 
Parent Process ID: 38924
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ Orphan process ID: 38925 
Orphan Parent Process ID: 2102

*/