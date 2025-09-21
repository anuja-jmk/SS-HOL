/*
==================================================================================================================================
Name: 15.c
Author: Anuja Jose
Description: Write a simple program to send some data from parent to the child process.
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main()
{
    int fd[2];
    
    char buf[14];
    char buf2[14];
    pipe(fd);
    if(!fork())
    {   

        close(fd[0]);
        write(fd[1],buf,sizeof(buf));
        printf("\nSending data to the pipe\n");
        printf("PID:%d, Parent id:%d",getpid(),getppid());

    }
    else
    {
        close(fd[1]);
        read(fd[0],buf2,sizeof(buf2));
        printf("\nReceived from pipe: %s",buf2);
        printf("PID:%d",getpid());

    }
}


/*
Output:

�anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ cc 15.c 
anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ ./a.out 


Sending data to the pipe
Received from pipe: PID:9146PID:9147, Parent id:9146
*/
