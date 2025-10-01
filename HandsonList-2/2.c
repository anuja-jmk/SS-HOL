/*
==================================================================================================================================
Name: 2.c
Author: Anuja Jose
Description: Write a program to print the system resource limits. Use getrlimit system call.
Date: 23th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

void print_lims(int res, char* name)
{

struct rlimit r_lim;
getrlimit(res,&r_lim);
printf("%s : Soft limit: %lu, Hard limit: %lu\n",name,r_lim.rlim_cur,r_lim.rlim_max);
}
void main()
{
 print_lims(RLIMIT_CPU,"CPU Time");
 print_lims(RLIMIT_FSIZE,"File Size");
 print_lims(RLIMIT_DATA,"Data Area");
 print_lims(RLIMIT_STACK,"Stack Size");
 print_lims(RLIMIT_CORE,"Core Dump Size");
 print_lims(RLIMIT_RSS,"Resident Set Size");
 print_lims(RLIMIT_NOFILE,"Max Open Files");
 print_lims(RLIMIT_AS,"Virtual Memory");


}


/*
Output:

nuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
CPU Time : Soft limit: 18446744073709551615, Hard limit: 18446744073709551615
File Size : Soft limit: 18446744073709551615, Hard limit: 18446744073709551615
Data Area : Soft limit: 18446744073709551615, Hard limit: 18446744073709551615
Stack Size : Soft limit: 8388608, Hard limit: 18446744073709551615
Core Dump Size : Soft limit: 0, Hard limit: 18446744073709551615
Resident Set Size : Soft limit: 18446744073709551615, Hard limit: 18446744073709551615
Max Open Files : Soft limit: 1048576, Hard limit: 1048576
Virtual Memory : Soft limit: 18446744073709551615, Hard limit: 18446744073709551615
*/
