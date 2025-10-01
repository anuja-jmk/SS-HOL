/*
==================================================================================================================================
Name: 29.c
Author: Anuja Jose
Description: Write a program to remove the message queue.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("/tmp", 100);
    msgid = msgget(key, 0666);
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue removed successfully.\n");
    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Message queue removed successfully.

 ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          anuja      666        0            0      
*/