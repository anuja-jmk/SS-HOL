/*
==================================================================================================================================
Name: 25.c
Author: Anuja Jose
Description: Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

void print_permissions(mode_t mode) {
    printf("Access Permissions: %o (octal)\n", mode & 0777);
}

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("/tmp", 100);
    msgid = msgget(key, 0666);

    msgctl(msgid, IPC_STAT, &buf);
    printf("Access permissions: %o\n", buf.msg_perm.mode);
    printf("User ID: %d\n", buf.msg_perm.uid);
    printf("Group ID: %d\n", buf.msg_perm.gid);
    printf("Last message sent time: %s", ctime(&(buf.msg_stime)));
    printf("Last message received time: %s", ctime(&(buf.msg_rtime)));
    printf("Last change time: %s", ctime(&(buf.msg_ctime)));
    printf("Current size of queue in bytes: %lu\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", buf.msg_qnum);
    printf("Maximum bytes allowed in queue: %lu\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Access permissions: 666
User ID: 1000
Group ID: 1000
Last message sent time: Tue Sep 30 19:32:04 2025
Last message received time: Tue Sep 30 19:33:03 2025
Last change time: Tue Sep 30 17:00:26 2025
Current size of queue in bytes: 0
Number of messages in queue: 0
Maximum bytes allowed in queue: 16384
PID of last msgsnd: 45542
PID of last msgrcv: 45864
anuja@anuja-Precision-5550:~

*/