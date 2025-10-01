/*
==================================================================================================================================
Name: 22.c
Author: Anuja Jose
Description: Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>
#include<fcntl.h>
#include <unistd.h>


int main(void)
{
    int             retval;
    fd_set          rfds;
    int fd;
    struct timeval  tv;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    char buf[100];

    char fifo[] = "/tmp/myfifo";
    fd = open(fifo, O_RDONLY | O_NONBLOCK);
    retval = select(1+fd, &rfds, NULL, NULL, &tv);

    if (retval)
     {   printf("Data is available now.\n");
        ssize_t n = read(fd, buf, sizeof(buf) - 1);
            if (n > 0) {
                buf[n] = '\0'; 
                printf("Data received: %s\n", buf);
       }
    }
    else
        printf("No data within ten seconds.\n");

    exit(EXIT_SUCCESS);
       }


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
hi how r u
Data is available now.
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ hi how r u
Command 'hi' not found, but can be installed with:
sudo snap install hi
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/