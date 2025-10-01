/*
==================================================================================================================================
Name: 21.c
Author: Anuja Jose
Description: Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 30th Sep, 2025
==================================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo1 = "/tmp/fifo1";
    char *fifo2 = "/tmp/fifo2";
    char buf[100];
    int fd1, fd2;

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    while (1) {
        fd1 = open(fifo1, O_RDONLY);
        read(fd1, buf, sizeof(buf));
        printf("User1: %s\n",buf);
        close(fd1);
        printf("User2:");
        fgets(buf, 100, stdin);
        fd2 = open(fifo2, O_WRONLY);
        write(fd2, buf, strlen(buf) + 1);
        close(fd2);
    }

    return 0;
}

