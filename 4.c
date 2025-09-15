/*
==================================================================================================================================
Name: 4.c
Author: Anuja Jose
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void main()
{
    int fd,wrte_ret;
    char strset[100],rstr[100];

    fd = open("test.txt",O_RDWR ,0644);
    printf("File opened in read-write mode, fd value: %d",fd);
    
    close(fd);

    fd = open("test.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    printf("\nOpening file with O_EXCL, fd value: %d\n", fd);
    close(fd);
    

}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
File opened in read-write mode, fd value: 3
Opening file with O_EXCL, fd value: -1
*/