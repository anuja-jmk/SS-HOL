/*
==================================================================================================================================
Name: 9.c
Author: Anuja Jose
Description: Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 6th Sep, 2025
==================================================================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>   
#include <unistd.h>
#include <stdlib.h>
#include <time.h>       

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        printf("Missing filename argument!");
        exit(0);
    }
    stat(argv[1], &st);
    printf("Filename: %s\n", argv[1]);
    printf("a. Inode number: %ld\n", (long) st.st_ino);
    printf("b. Number of hard links: %ld\n", (long) st.st_nlink);
    printf("c. UID: %d\n", st.st_uid);
    printf("d. GID: %d\n", st.st_gid);
    printf("e. Size: %ld bytes\n", (long) st.st_size);
    printf("f. Block size: %ld bytes\n", (long) st.st_blksize);
    printf("g. Number of blocks: %ld\n", (long) st.st_blocks);
    printf("h. Time of last access: %s", ctime(&st.st_atime));
    printf("i. Time of last modification: %s", ctime(&st.st_mtime));
    printf("j. Time of last change: %s", ctime(&st.st_ctime));

    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./a.out destination.txt 
Filename: destination.txt
a. Inode number: 1352303
b. Number of hard links: 1
c. UID: 1000
d. GID: 1000
e. Size: 900 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Time of last access: Sat Sep  6 21:05:36 2025
i. Time of last modification: Sat Sep  6 21:05:36 2025
j. Time of last change: Sat Sep  6 21:05:36 2025

*/

