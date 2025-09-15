/*
==================================================================================================================================
Name: 7.c
Author: Anuja Jose
Description: Write a program to copy file1 into file2 ($cp file1 file2)
Date: 30th Aug, 2025
==================================================================================================================================
*/

#define SIZE 1024

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd1,fd2,i;
    char buff[SIZE];
    fd1=open(argv[1],O_RDONLY,0744);

    fd2 = open(argv[2],O_WRONLY | O_CREAT,0744) ;
     while ((i = read(fd1, buff, SIZE)) > 0) {
        if (write(fd2, buff, i) != i) {
            perror("write");
          
        }
    close(fd1);
    close(fd2);
    }

}


/*
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out source.txt copied.txt

*/