/*
==================================================================================================================================
Name: 10.c
Author: Anuja Jose
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
    char buff[] = "Program10B";
    char buff1[] = "Second10BY";
    int fd,k,val;
    off_t lsk;
    fd = open("file1.txt",O_RDWR | O_CREAT,0644);

    
    val = write(fd,buff,10);
    if(val==10)
    {
        printf("Initial 10B Data written successfully.");
        lsk = lseek(fd,10,SEEK_CUR);
        printf("\nlseek value = %ld",lsk);
        val = write(fd,buff1,10);
        if(val==10)
            printf("\nSecond set of data written successfully.");

    }
    close(fd);


}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Initial 10B Data written successfully.
lseek value = 20
Second set of data written successfully.

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ od -c file1.txt 
0000000   P   r   o   g   r   a   m   1   0   B  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   S   e   c   o   n   d   1   0   B   Y
0000036
*/