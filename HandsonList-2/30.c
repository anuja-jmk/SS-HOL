/*
==================================================================================================================================
Name: 30.c
Author: Anuja Jose
Description: Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main() {
    key_t key;
    int shmid;
    int size=60;
    char *data;
    key = ftok("shared_mmy", 65);
    shmid = shmget(key, size, 0744 | IPC_CREAT);
    data = shmat(shmid,(void *)0, 0);
    printf("Writing to shared memory...\n");
    printf ("Enter a String : ");
    scanf ("%[^\n]",data);
    printf("Data written: %s\n", data);
    shmdt(data);
    data = (char*) shmat(shmid, NULL, SHM_RDONLY);
    printf("Attempting to overwrite in read-only mode...\n");
    printf("Read-only data: %s\n", data);

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed.\n");

    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ ./a.out 
Writing to shared memory...
Enter a String : test phrases for shared memory
Data written: test phrases for shared memory
Attempting to overwrite in read-only mode...
Read-only data: test phrases for shared memory
Shared memory removed.
anuja@anuja-Precision-5550:~/Documents/SS/handsonl2$ 

*/