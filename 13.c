/*
==================================================================================================================================
Name: 13.c
Author: Anuja Jose
Description: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(void)
{
    int             retval;
    fd_set          rfds;
    struct timeval  tv;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1)
        perror("select()");
    else if (retval)
               printf("Data is available now.\n");
       
           else
               printf("No data within ten seconds.\n");

           exit(EXIT_SUCCESS);
       }

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
hi
Data is available now.
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
No data within ten seconds.

*/