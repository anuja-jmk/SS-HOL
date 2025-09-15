/*
==================================================================================================================================
Name: 22.c
Author: Anuja Jose
Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 30th Aug, 2025
==================================================================================================================================
*/




#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    
int fd;
fd = open("file_a.txt",O_WRONLY,0644);
pid_t c1;
if(fork())
{
    write(fd,"Parent process Writing\n",23);
    close(fd);
}
else
{
    write(fd,"Child process Writing\n",22);
    close(fd);
}
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cat file_a.txt 
Parent process Writing
Child process Writing
*/