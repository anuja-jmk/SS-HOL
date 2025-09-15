/*
==================================================================================================================================
Name: 14.c
Author: Anuja Jose
Description: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char **argv)
{
      
    if(argc!=2)
        {printf("Provide a file name!\n");
            exit(0);}
    struct stat st;
    printf("File name: %s\n", argv[1]);
    lstat(argv[1], &st);
    if(S_ISREG(st.st_mode))
        printf("Type: Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Type: Directory\n");
    else if (S_ISCHR(st.st_mode))
        printf("Type: Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Type: Block device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("Type: FIFO/pipe\n");
    else if (S_ISLNK(st.st_mode))
        printf("Type: Symbolic link\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Type: Socket\n");
    else
        printf("Type: Unknown\n");

    return 0;
}

/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out file_a.txt 
File name: file_a.txt
Type: Regular file
*/

