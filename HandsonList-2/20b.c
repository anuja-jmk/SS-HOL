/*
==================================================================================================================================
Name: 20.c
Author: Anuja Jose
Description: Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo_path = "/tmp/myfifo";
    char buffer[100];
    mkfifo(fifo_path, 0666);

    int fd;
    printf("Waiting for messages...\n");
    fd = open(fifo_path, O_RDONLY);
    ssize_t bytes = read(fd, buffer, sizeof(buffer));
    if (bytes > 0) {
        printf(" %s", buffer);
        }
        close(fd);
    
    return 0;
}

