/*
==================================================================================================================================
Name: 31.c
Author: Anuja Jose
Description: Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};


int create_sem(key_t token, int num_sems) {
    int id = semget(token, num_sems, 0666 | IPC_CREAT);
    return id;
}

void sem_init(int semid, int sem_num, int init_val) {
    union semun sem_union;
    sem_union.val = init_val;
    semctl(semid, sem_num, SETVAL, sem_union);
}

int main() {
    key_t key_bin = ftok("/tmp",45);
    int semid_bin = semget( key_bin, 1, 0666 | IPC_CREAT);
    sem_init(semid_bin, 0, 1);
    printf("Created binary semaphore with ID %d and initialized to 1\n", semid_bin);

    int resources = 5;
    key_t key_count = ftok("/tmp",47);
    int semid_count = semget( key_count, 1, 0666 | IPC_CREAT);
    sem_init(semid_count, 0, resources);
    printf("Created counting semaphore with ID %d and initialized to %d\n", semid_count, resources);

    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Created binary semaphore with ID 0 and initialized to 1
Created counting semaphore with ID 1 and initialized to 5
*/