/*
==================================================================================================================================
Name: 5.c
Author: Anuja Jose
Description: Write a program to print the system limitation of 
a. max length of the arguments to the exec family of functions.
b. max number of simultaneous process per user id.
c. number of clock ticks per second.
d. max number of open files.
e. size of a page.
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>


void main()
{
    long ex_args = sysconf(_SC_ARG_MAX);
    printf("a. max length of the arguments to the exec family of functions = %ld bytes \n",ex_args);
    struct rlimit rl;
    getrlimit(RLIMIT_NPROC, &rl);
    printf("b. max number of simultaneous process per user id: soft limit = %lu, hard limit = %lu\n",rl.rlim_cur,rl.rlim_max);
    printf("c. number of clock ticks per second = %ld\n",sysconf(_SC_CLK_TCK));
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("d. max number of open files: soft limit = %lu, hard limit = %lu\n",rl.rlim_cur,rl.rlim_max);
    printf("e. size of a page = %ld bytes\n",sysconf(_SC_PAGESIZE));
    printf("f. total number of pages in physical memory: %ld pages\n",sysconf(_SC_PHYS_PAGES));
    printf("g. number of currently available pages in the physical memory: %ld pages",sysconf(_SC_AVPHYS_PAGES));
    

}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
a. max length of the arguments to the exec family of functions = 2097152 bytes 
b. max number of simultaneous process per user id: soft limit = 126553, hard limit = 126553
c. number of clock ticks per second = 100
d. max number of open files: soft limit = 1048576, hard limit = 1048576
e. size of a page = 4096 bytes
f. total number of pages in physical memory: 8150602 pages
g. number of currently available pages in the physical memory: 5109248 pages
*/
