/*
==================================================================================================================================
Name: 3.c
Author: Anuja Jose
Description: Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
void main()
{   
    int fd;
    fd = creat("file_4.txt",0644);
    
    if(fd>0)
    printf("file created succssfully with fd value %d.\n",fd);
    else
    printf("File creation failed\n");

}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
file created succssfully with fd value 3.
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
File creation failed

*/