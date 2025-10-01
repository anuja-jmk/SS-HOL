/*
==================================================================================================================================
Name: 27.c
Author: Anuja Jose
Description: Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
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
    msgrcv(msgid, &message, sizeof(message.msg_text) + 1, message.msg_type, 0);
    printf("Message Received: %s\n",message.msg_text);
    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Message Received: Inserting text for program no. 26...hi
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 

*/