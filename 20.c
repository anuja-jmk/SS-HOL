/*
==================================================================================================================================
Name: 20.c
Author: Anuja Jose
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
    int new_pr;
    printf("Current Priority: %d\n",getpriority(PRIO_PROCESS,0));
    new_pr=nice(6);
    printf("Current Priority: %d\n",new_pr);
    printf("Current Priority: %d\n",getpriority(PRIO_PROCESS,0));

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Current Priority: 0
Current Priority: 6
Current Priority: 6

*/