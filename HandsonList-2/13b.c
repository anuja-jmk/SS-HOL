/*
==================================================================================================================================
Name: 13a.c
Author: Anuja Jose
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide pid as argument!");
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);
    printf("SIGSTOP sent.\n");

    return 0;
}

