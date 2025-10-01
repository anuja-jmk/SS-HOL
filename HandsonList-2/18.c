/*
==================================================================================================================================
Name: 18.c
Author: Anuja Jose
Description: Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int fd1[2];
    pipe(fd);
    pipe(fd1);
pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(fd1[0]);
        close(fd1[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        dup2(fd1[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(fd1[0]);
        close(fd1[1]);
        execlp("grep", "grep", "^d", NULL);
    }

    pid_t pid3 = fork();
    if (pid3 == 0) {

        dup2(fd1[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(fd1[0]);
        close(fd1[1]);
        execlp("wc", "wc", NULL);
    }

    close(fd[0]);
    close(fd[1]);
    close(fd1[0]);
    close(fd1[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
      1       9      52
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/