/*
==================================================================================================================================
Name: 11.c
Author: Anuja Jose
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

void main()
{
    int fd,fd1,fd2,fd3;
    int rval;
    char x[] = "current\n",x1[]="dup_fd\n",x2[] = "dup2_fd\n",x3[]="fcntl_fd";
    fd = open("file_a.txt",O_RDWR | O_CREAT | O_TRUNC,0644);

    fd1 = dup(fd);
    fd2 = dup2(fd,20);
    fd3 = fcntl(fd,F_DUPFD,20);
    printf("\nCurrent fd val = %d",fd);
    printf("\nDup: fd val = %d",fd1);
    printf("\nDup2: fd val = %d",fd2);
    printf("\nfcntl: fd val = %d",fd3);
    write(fd,x,8);
    write(fd1,x1,7);
    write(fd1,x2,8);
    write(fd1,x3,8);

    close(fd);
    close(fd1);
    close(fd3);
    close(fd2);

}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 

Current fd val = 3
Dup: fd val = 4
Dup2: fd val = 20
fcntl: fd val = 21

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cat file_a.txt 
current
dup_fd
dup2_fd
fcntl_fd
*/