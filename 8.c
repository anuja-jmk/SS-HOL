/*
==================================================================================================================================
Name: 8.c
Author: Anuja Jose
Description: Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>     
#include <unistd.h>  


int main() {
    int fd,cnt;
    char line[512],buf[512];
    ssize_t n;
    cnt =0;

    fd = open("source.txt",O_RDONLY);

    while ((n = read(fd, buf, 512)) > 0) {
        for (int i = 0; i < n; i++) {
            line[cnt++] = buf[i];
            if (buf[i] == '\n') {   
                write(1, line, cnt);       
                cnt = 0;                 
            }
        }
    }
    if (cnt > 0) {
        write(1, line, cnt);
    }
    close(fd);
    return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
The first Linux Kernel, version 0.01, had just 10,239 lines of code (Source: Wikipedia)
Linux is not an OS, it is a kernel. Explore what Linux is if you are curious.
The Linux Kernel has crossed 1.2 million code commits (Source: GitHub)
The Linux Kernel today has well over 30 million lines of code as of 2022. (Source: Ubuntu)
The most popular programming language used for the Linux Kernel is C, with nearly 98% of code written in C. (Source: GitHub)
There are 272 active Linux distributions as per the information available in Distrowatch (there could be even more!)
Did you know that Android is built on top of the Linux Kernel? Even if it is heavily modified, Android functions because Linux exists.
Linux is everywhere, ranging from servers to routers. Whether it is a device for personal or enterprise usage, chances are it can run Linux or already runs on it.
*/