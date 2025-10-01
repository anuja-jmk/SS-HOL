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
#include <string.h>

int main() {
    char *fifo_path = "/tmp/myfifo";
    int fd;
    char buffer[] = "Writer writing this line to the fifo ..Hi how are you";
    mkfifo(fifo_path, 0666);
    fd = open(fifo_path, O_WRONLY);
    write(fd, buffer, strlen(buffer) + 1);
    close(fd);

    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ cc 20a.c 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ cc 20b.c 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Waiting for messages...
 Writer writing this line to the fifo ..Hi how are youanuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
*/