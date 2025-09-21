/*
==================================================================================================================================
Name: 16.c
Author: Anuja Jose
Description: Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main()
{
    int fd[2],fd1[2];
    
    char buf[20]="DATA FROM CHILD";
    char buf3[20]="DATA FROM PARENT";
    char buf1[20],buf2[20];
    pipe(fd);
    pipe(fd1);
    
    if(!fork())
    {   

        close(fd[0]);
        close(fd1[1]);
        write(fd[1],buf,sizeof(buf));
        printf("\nSending data to the pipe from child..\n");
        printf("PID:%d, Parent id:%d",getpid(),getppid());
        read(fd1[0],buf1,sizeof(buf1));
        printf("\nReceived data from parent: %s, Current PID: %d",buf1,getpid());
        

    }
    else
    {
        close(fd[1]);
        close(fd1[0]);
        read(fd[0],buf2,sizeof(buf2));
        printf("\nReceived from pipe: %s, Current PID:%d",buf2,getpid());
        write(fd1[1],buf3,sizeof(buf3));
        printf("\nSending data to the pipe from parent\n");
        printf("PID:%d\n",getpid());
        

    }
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ ./a.out 


Sending data to the pipe from child..
Received from pipe: DATA FROM CHILD, Current PID:7078
Sending data to the pipe from parent
PID:7078
PID:7079, Parent id:7078
Received data from parent: DATA FROM PARENT, Current PID: 7079

*/