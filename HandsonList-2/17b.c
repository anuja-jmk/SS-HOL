/*
==================================================================================================================================
Name: 17.c
Author: Anuja Jose
Description: Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);  
        dup2(fd[1],1);
        //close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    if (fork() == 0) {
        
        close(fd[1]);    
        dup2(fd[0],0);    
        //close(fd[0]);  
        execlp("wc", "wc", NULL);
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ cc 17b.c 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
     62     551    3037
anuja@anuja-Precision-5550:~/
*/