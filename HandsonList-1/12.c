/*
==================================================================================================================================
Name: 12.c
Author: Anuja Jose
Description: Write a program to find out the opening mode of a file. Use fcntl.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
void main()
{
    int fd,mods,rwflgs;
    fd = open("file_a.txt", O_RDONLY | O_SYNC);
    printf("File access modes:\n");
    mods = fcntl(fd,F_GETFL);

    rwflgs = mods & O_ACCMODE;
    if (rwflgs == O_RDONLY)
        printf("O_RDONLY\n");
    else if (rwflgs == O_WRONLY)
        printf("O_WRONLY\n");
    else if (rwflgs == O_RDWR)
        printf("O_RDWR\n");
    if (mods & O_APPEND)
        printf("O_APPEND \n");
    if (mods & O_NONBLOCK)
        printf("O_NONBLOCK\n");
    if (mods & O_SYNC)
        printf("O_SYNC\n");
    if (mods & O_CREAT)
        printf("O_CREAT\n");

    close(fd);
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
File access modes:
O_RDONLY
O_SYNC
*/