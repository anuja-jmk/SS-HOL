/*
==================================================================================================================================
Name: 29.c
Author: Anuja Jose
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    pid_t pid;  
    struct sched_param param;
    pid = getpid();
    int thr_policy;

    thr_policy = sched_getscheduler(pid);
    switch(thr_policy) {
        case SCHED_OTHER: 
        printf("Current policy: SCHED_OTHER\n"); 
        break;
        case SCHED_FIFO:  
        printf("Current policy: SCHED_FIFO\n"); 
        break;
        case SCHED_RR:    
        printf("Current policy: SCHED_RR\n"); 
        break;
        default:          
        printf("Current policy: Unknown\n");  
    }
    param.sched_priority = sched_get_priority_max(SCHED_RR);
    sched_setscheduler(pid, SCHED_RR, &param);
    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);   
    thr_policy = sched_getscheduler(pid);
    switch(thr_policy) {
       case SCHED_OTHER: 
        printf("Current policy: SCHED_OTHER\n"); 
        break;
        case SCHED_FIFO:  
        printf("Current policy: SCHED_FIFO\n"); 
        break;
        case SCHED_RR:    
        printf("Current policy: SCHED_RR\n"); 
        break;
        default:          
        printf("Current policy: Unknown\n");  
    }
    return 0;
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ sudo ./a.out 
Current policy: SCHED_OTHER
Scheduling policy changed to SCHED_RR with priority 99
Current policy: SCHED_RR
*/