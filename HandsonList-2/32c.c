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
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void acquire_semaphore(int semid) {
    int val = semctl(semid, 0, GETVAL);
    if (val == 0) {
        printf("Process %d waiting for semaphore...\n", getpid());
        fflush(stdout);
    }
    struct sembuf op = {0, -1, 0};
    if (semop(semid, &op, 1) == -1) {
        perror("semop acquire");
        exit(EXIT_FAILURE);
    }
}

void release_semaphore(int semid) {
    struct sembuf op = {0, 1, 0};
    if (semop(semid, &op, 1) == -1) {
        perror("semop release");
        exit(EXIT_FAILURE);
    }
}

int create_or_get_semaphore(key_t key) {
    int semid = semget(key, 1, 0666 | IPC_CREAT | IPC_EXCL);
    if (semid != -1) {
        union semun arg;
        arg.val = 2;
        if (semctl(semid, 0, SETVAL, arg) == -1) {
            perror("semctl init");
            exit(EXIT_FAILURE);
        }
    } else {
        semid = semget(key, 1, 0666);
        if (semid == -1) {
            perror("semget existing");
            exit(EXIT_FAILURE);
        }
    }
    return semid;
}

int main() {
    key_t key = ftok(".", 100);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int semid = create_or_get_semaphore(key);

    printf("Process %d requesting resource\n", getpid());
    acquire_semaphore(semid);
    printf("Process %d using resource\n", getpid());
    sleep(10);
    printf("Process %d done with resource\n", getpid());
    release_semaphore(semid);

    return 0;
}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Process 68527 requesting resource
Process 68527 using resource
Process 68527 done with resource

*/