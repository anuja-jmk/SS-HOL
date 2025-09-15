/*
==================================================================================================================================
Name: 28.c
Author: Anuja Jose
Description: Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2025
==================================================================================================================================
*/



#include<sched.h>
#include<stdio.h>

int main()
{
    
    printf("Max Real Time Priority SCHED_FIFO:= %d\n",sched_get_priority_max(SCHED_FIFO));
    printf("Min Real Time Priority SCHED_FIFO:= %d\n",sched_get_priority_min(SCHED_FIFO));
    printf("Max Real Time Priority SCHED_RR:= %d\n",sched_get_priority_max(SCHED_RR));
    printf("Min Real Time Priority SCHED_RR:= %d\n",sched_get_priority_min(SCHED_RR));

  
    return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Max Real Time Priority SCHED_FIFO:= 99
Min Real Time Priority SCHED_FIFO:= 1
Max Real Time Priority SCHED_RR:= 99
Min Real Time Priority SCHED_RR:= 1
*/