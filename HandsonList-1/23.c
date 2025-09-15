/*
==================================================================================================================================
Name: 23.c
Author: Anuja Jose
Description: Write a program to create a Zombie state of the running program.
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
    printf("Child process : %d \n", getpid());
    exit(0);  
}
else {
    printf("Parent process :%d\n", getpid());
    printf("Parent going to sleep\n");
    sleep(60);
    printf("Parent awake.\n");
}

return 0;
}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 23.c 
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Parent process :37877
Parent going to sleep
Child process : 37878 
Parent awake.

anuja@anuja-Precision-5550:/proc/37878$ ps aux | grep Z
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
anuja      12000  0.0  0.0      0     0 ?        Z    10:02   0:00 [sd_espeak-ng-mb] <defunct>
anuja      37878  0.0  0.0      0     0 pts/0    Z+   16:18   0:00 [a.out] <defunct>
anuja      38120  0.0  0.0   6628  2220 pts/1    S+   16:19   0:00 grep --color=auto Z
*/

