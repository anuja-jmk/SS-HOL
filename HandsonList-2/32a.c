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
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};




void sem_lock(int semid) {
    struct  sembuf op = {0, -1, 0};
    if (semop(semid, &op, 1) == -1) {
        perror("semop lock");
        exit(0);
    }  

}

void sem_unlock(int semid) {
    struct  sembuf op = {0, 1, 0};
    if (semop(semid, &op, 1) == -1) {
        perror("semop unlock");
        exit(0);
    }  

}


int main() {

    int t_val;
    key_t tkt_key = ftok("ticket_number.txt",10);
    int sem_id = semget(tkt_key, 1, 0666 | IPC_CREAT | IPC_EXCL);
    if (sem_id == -1) {
    if (errno == EEXIST) {
        sem_id = semget(tkt_key, 1, 0);
        if (sem_id == -1) {
            perror("semget");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("semget");
        exit(EXIT_FAILURE);
    }
}
    union semun s;
    s.val = 1;
    semctl(sem_id, 0, SETVAL, s); 
    int fd = open("ticket_number.txt", O_RDWR);
    sem_lock(sem_id);
    read(fd, &t_val, sizeof(t_val));
    t_val++;
    printf("Reserved ticket no: %d\n", t_val);
    lseek(fd, 0, SEEK_SET);
    sleep(30);
    write( fd, &t_val, sizeof(t_val));
    sem_unlock(sem_id);
    close(fd);
    
    return 0;
}


/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Reserved ticket no: 3
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Reserved ticket no: 4
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ cc 32a.c 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Reserved ticket no: 5

*/