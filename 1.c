/*
==================================================================================================================================
Name: 1.c
Author: Anuja Jose
Description: Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)
Date: 30th Aug, 2025
==================================================================================================================================
*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    symlink("destination.txt", "dst_soft");
    printf("\nSoftlink generated for destination.txt");

    link("destination.txt", "dst_hard");
    printf("\nHardlink generated for destination.txt");

    mkfifo("my_fifo", 0666);
    printf("\nfifo file generated");

    return 0;
}

/*
Output:
i.

a)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ln -s daemon_script.sh dae_scr
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -l dae_scr 
lrwxrwxrwx 1 anuja anuja 16 Sep  7 15:08 dae_scr -> daemon_script.sh

b)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -li dsh daemon_script.sh 
1319385 -rwxrwxr-x 2 anuja anuja 66 Sep  7 11:48 daemon_script.sh
1319385 -rwxrwxr-x 2 anuja anuja 66 Sep  7 11:48 dsh

c)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ mkfifo fifo2
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -l fifo2 
prw-rw-r-- 1 anuja anuja 0 Sep  7 15:06 fifo2

ii.

Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out 

Softlink generated for destination.txt
Hardlink generated for destination.txt
fifo file generated
a)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -l dst_soft 
lrwxrwxrwx 1 anuja anuja 15 Sep  6 21:21 dst_soft -> destination.txt
b)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -li dst_hard destination.txt 
1352303 -rwxr--r-- 2 anuja anuja 900 Sep  6 21:05 destination.txt
1352303 -rwxr--r-- 2 anuja anuja 900 Sep  6 21:05 dst_hard
c)
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ls -l my_fifo
prw-rw-r-- 1 anuja anuja 0 Sep  6 21:15 my_fifo
*/