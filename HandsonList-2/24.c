/*
==================================================================================================================================
Name: 24.c
Author: Anuja Jose
Description: Write a program to create a message queue and print the key and message queue id.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/msg.h>

void main()
{
    key_t k;
    int msgid;
    k = ftok("/tmp",100);
    msgid = msgget(k, 0666 | IPC_CREAT);
    printf("Key: %d\n", k);
    printf("Message Queue ID: %d\n", msgid);
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Key: 1678049281
Message Queue ID: 1
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/