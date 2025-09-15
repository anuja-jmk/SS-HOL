/*
==================================================================================================================================
Name: 6.c
Author: Anuja Jose
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 30th Aug, 2025
==================================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>

void main()
{   char str[30];
    int k;
    printf("Enter text:\n");
    k=read(0,str,sizeof(str));
    if(k>0)
        {
            printf("File read successful.\n");
            write(1,str,k);
        }
    else
    write(2,str,sizeof(str));
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Enter text:
Hello Good Mrng!
File read successfull.
Hello Good Mrng!

*/