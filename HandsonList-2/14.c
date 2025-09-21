/*
==================================================================================================================================
Name: 14.c
Author: Anuja Jose
Description: Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>

void main()
{
    int fd[2];

    char buf[14];
    pipe(fd);
    write(fd[1],"Hi World\n",9);
    read(fd[0],buf,sizeof(buf));
    printf("Data Received from pipe: %s",buf);

}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ ./a.out 
Data Received from pipe: Hi World
*/