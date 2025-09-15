/*
==================================================================================================================================
Name: 19.c
Author: Anuja Jose
Description: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include<unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    long long int start, end;
    start = rdtsc();
    pid_t pid;
    pid = getpid();

    end = rdtsc();

    printf("Process ID: %d\n", pid);
    printf("CPU cycles used by getpid(): %llu ", end - start);

    return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Process ID: 8721
CPU cycles used by getpid(): 20424 
*/