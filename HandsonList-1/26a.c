/*
==================================================================================================================================
Name: 26a.c
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
    char exec_file[] = "./filecreation"; 
    char *argv[] = {exec_file, NULL};      
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
Parent PID:= 49378
Exec Program:= ./filecreation
file created succssfully with fd value 3.
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$
*/