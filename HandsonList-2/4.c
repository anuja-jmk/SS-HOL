/*
==================================================================================================================================
Name: 4.c
Author: Anuja Jose
Description: Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc()
{
	unsigned int lo,hi;
	__asm__ __volatile("rdtsc" : "=a"(lo),"=d"(hi));
			return((unsigned long long)hi << 32) | lo;
	
}

void main()
{
	unsigned long long int st,end;
	st = rdtsc();
	for(int i = 0; i < 100; i++)
		getppid();
	end = rdtsc();
	printf("Total time taken for 100 getppid calls = %llu",end-st);

}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Total time taken for 100 getppid calls = 127314

*/
