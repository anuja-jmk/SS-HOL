/*
==================================================================================================================================
Name: 32.c
Author: Anuja Jose
Description: Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main() {
    key_t sem_key = ftok("ticket_number.txt", 10);
    int sem_identifier = semget(sem_key, 1, 0666 | IPC_CREAT);
    semctl(sem_identifier, 0, IPC_RMID);
    printf("Semaphore deleted successfully\n");
    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Semaphore deleted successfully
*/