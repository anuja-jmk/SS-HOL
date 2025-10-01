/*
==================================================================================================================================
Name: 3.c
Author: Anuja Jose
Description: Write a simple program to set (any one) system resource limit. Use setlimit system call.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

void main()
{
	struct rlimit rl;
	getrlimit(RLIMIT_NOFILE,&rl);
	printf("Current No. of Open Files limits: Soft limit:%lu, Hard limit: %lu\n",rl.rlim_cur,rl.rlim_max);
	rl.rlim_cur = 2000;
	setrlimit(RLIMIT_NOFILE,&rl);
	printf("New soft limit:%lu",rl.rlim_cur);
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Current No. of Open Files limits: Soft limit:1048576, Hard limit: 1048576
New soft limit:2000
*/
