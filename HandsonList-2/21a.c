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
        printf("User1: ");
        fgets(buf, 100, stdin);
        fd1 = open(fifo1, O_WRONLY);
        write(fd1, buf, strlen(buf) + 1);
        close(fd1);

        fd2 = open(fifo2, O_RDONLY);
        read(fd2, buf, sizeof(buf));
        printf("User2: %s\n", buf);
        close(fd2);
    }

    return 0;
}




/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
User1: Hi how are you
User2: hi, I'm good, what bout u?

User1: same, bye
User2: bye

User1: 



anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
User1: Hi how are you

User2:hi, I'm good, what bout u?
User1: same, bye

User2:bye

*/