/*
==================================================================================================================================
Name: 25.c
Author: Anuja Jose
Description: Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
pid_t c1,c2,c3;
c1 = fork();  
int state;
if(c1 == 0) 
{
    c2 = fork();
    if(c2==0)
    {
        c3 = fork();
        if(c3==0)
            {sleep(2);
            printf("Final child terminated");}
        else
        {   printf("\nChild2 %d waiting for c3: %d\n",getpid(),c3);
            waitpid(c3,&state,0);
            sleep(2);
        }
    }
    else

    {    printf("\nChild1 %d waiting for c2: %d\n",getpid(),c2);
        waitpid(c2,&state,0);
        sleep(2);
    }

}
else
{
    printf("\nParent %d waiting for c1: %d\n",getpid(),c1);
    waitpid(c1,&state,0);

}
}
    
/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 

Parent 40927 waiting for c1: 40928

Child1 40928 waiting for c2: 40929

Child2 40929 waiting for c3: 40930
Final child terminated
*/