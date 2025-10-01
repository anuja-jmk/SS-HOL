/*
==================================================================================================================================
Name: 19.c
Author: Anuja Jose
Description: Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 30th Sep, 2025
==================================================================================================================================
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    mknod("myfifo", S_IFIFO | 0666, 0);
    mkfifo("myfifo3", 0666);
    return 0;
}



/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ls -l | grep pr
prw-rw-r-- 1 anuja anuja     0 Sep 29 22:55 myfifo
prw-rw-r-- 1 anuja anuja     0 Sep 29 22:24 myfifo1
prw-rw-r-- 1 anuja anuja     0 Sep 29 22:24 myfifo2
prw-rw-r-- 1 anuja anuja     0 Sep 29 22:55 myfifo3
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ 

mkfifo internally uses mknod itself
*/