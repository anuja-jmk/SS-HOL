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
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void acquire_sem(int sid) {
    struct sembuf op = {0, -1, 0};
    printf("Process %d trying to acquire semaphore...\n", getpid());
    fflush(stdout);  

    if (semop(sid, &op, 1) == -1) {
        perror("semop acquire");
        exit(EXIT_FAILURE);
    }

    printf("Process %d acquired semaphore.\n", getpid());
    fflush(stdout); 
}

void release_sem(int sid) {
    struct sembuf op = {0, 1, 0};
    printf("Process %d releasing semaphore...\n", getpid());
    fflush(stdout); 
    if (semop(sid, &op, 1) == -1) {
        perror("semop release");
        exit(EXIT_FAILURE);
    }
    printf("Process %d released semaphore.\n", getpid());
    fflush(stdout); 
}

int init_semaphore(key_t token) {
    int semid = semget(token, 1, 0666 | IPC_CREAT | IPC_EXCL);
    if (semid >= 0) {
        union semun arg;
        arg.val = 1; 
        if (semctl(semid, 0, SETVAL, arg) == -1) {
            perror("semctl setval");
            exit(EXIT_FAILURE);
        }
        printf("Semaphore successfully created with ID %d\n", semid);
        fflush(stdout);  
        return semid;
    } else if (errno == EEXIST) {
        semid = semget(token, 1, 0); 
        if (semid == -1) {
            perror("semget");
            exit(EXIT_FAILURE);
        }
        printf("Semaphore already exists with ID %d\n", semid);
        fflush(stdout); 
        return semid;
    } else {
        perror("semget");
        exit(EXIT_FAILURE);
    }
}

int init_shared_memory(key_t token) {
    int id = shmget(token, 1024, 0666 | IPC_CREAT);
    if (id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return id;
}

int main() {
    key_t key = ftok(".", 123);
    printf("Generated key: %d\n", key);
    fflush(stdout); 
    int shm_id = init_shared_memory(key);  
    char *shared_ptr = (char*) shmat(shm_id, NULL, 0);  
    if (shared_ptr == (char*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory attached at %p\n", shared_ptr);
    fflush(stdout); 
    int sem_id = init_semaphore(key); 
    acquire_sem(sem_id); 
    printf("Process %d writing...\n", getpid());
    fflush(stdout);  
    snprintf(shared_ptr, 100, "Hello from process %d", getpid());  
    sleep(10); 
    printf("Process %d done writing.\n", getpid());
    fflush(stdout); 
    release_sem(sem_id); 
    shmdt(shared_ptr);
    shmctl(shm_id, IPC_RMID, NULL); 
    semctl(sem_id, 0, IPC_RMID);

    return 0;
}


/*
Output:

nuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Generated key: 2063945585
Shared memory attached at 0x7fb4887a9000
Semaphore already exists with ID 5
Process 73753 trying to acquire semaphore...
Process 73753 acquired semaphore.
Process 73753 writing...
Process 73753 done writing.
Process 73753 releasing semaphore...
Process 73753 released semaphore.
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Generated key: 2063945585
Shared memory attached at 0x7b11ab9a0000
Semaphore already exists with ID 5
Process 74013 trying to acquire semaphore...
*/