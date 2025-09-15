/*
==================================================================================================================================
Name: 15.c
Author: Anuja Jose
Description: Write a program to display the environmental variable of the user (use environ).
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include<stdio.h>

extern char **environ;
void main()
{
    int i = 0;
    while(environ[i]) {
  printf("%s\n", environ[i++]); 
}
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
SHELL=/bin/bash
SESSION_MANAGER=local/anuja-Precision-5550:@/tmp/.ICE-unix/2370,unix/anuja-Precision-5550:/tmp/.ICE-unix/2370
QT_ACCESSIBILITY=1
*/