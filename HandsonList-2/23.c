/*
==================================================================================================================================
Name: 23.c
Author: Anuja Jose
Description: Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<limits.h>

void main()
{
    struct rlimit r_lim;
    getrlimit(RLIMIT_NOFILE,&r_lim);
    printf("Max no. of files limit: soft limit: %lu, hard limit: %lu",r_lim.rlim_cur,r_lim.rlim_max);    
    printf("\nSize of pipe buffer: %d",PIPE_BUF);
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Max no. of files limit: soft limit: 1048576, hard limit: 1048576
Size of pipe buffer: 4096anuja@anuja-Precision-5550:~/
*/