/*
==================================================================================================================================
Name: 28.c
Author: Anuja Jose
Description: Write a program to change the existing message queue permission. (use msqid_ds structure)
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t k;
    int msgid;
    struct msqid_ds buf;

    k = ftok("/tmp", 100);
    msgid = msgget(k, 0666);
    msgctl(msgid, IPC_STAT, &buf);
    printf("Current permissions: %o\n", buf.msg_perm.mode & 0777);

    buf.msg_perm.mode = (buf.msg_perm.mode & ~0777) | 0644;
    msgctl(msgid, IPC_SET, &buf);
    printf("Permissions changed to: %o\n", buf.msg_perm.mode & 0777);

    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Current permissions: 666
Permissions changed to: 644
*/