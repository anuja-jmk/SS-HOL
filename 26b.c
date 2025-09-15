/*
==================================================================================================================================
Name: 26b.c
Author: Anuja Jose
Description: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char exec_file[] = "./filetype_detector"; 
    char *argv[] = {exec_file, "filecreation",NULL};      
    printf("Parent PID:= %d\n", getpid());
    printf("Exec Program:= %s\n", exec_file);

    if(execv(exec_file, argv) < 0) {
        perror("execv failed");
        return 1;
    }

       printf("Failed exec!\n");

    return 0;
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 
Parent PID:= 49630
Exec Program:= ./filetype_detector
File name: filecreation
Type: Regular file
*/