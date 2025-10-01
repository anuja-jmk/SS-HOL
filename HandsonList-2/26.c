/*
==================================================================================================================================
Name: 26.c
Author: Anuja Jose
Description: Write a program to send messages to the message queue. Check $ipcs -q
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("/tmp", 100);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;  
    printf("Enter message to send (max 99 chars): ");
    scanf("%[^\n]s",message.msg_text);
    msgsnd(msgid, &message, strlen(message.msg_text) + 1, 0);
    printf("Message sent successfully.\n");
    return 0;
}



/*
Output:
/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Enter message to send (max 99 chars): Inserting text for program no. 26...hi
Message sent successfully.

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          anuja      666        0            0           
0x64050001 1          anuja      666        39           1           


*/