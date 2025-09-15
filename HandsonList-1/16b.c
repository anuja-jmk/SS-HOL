/*
==================================================================================================================================
Name: 16.c
Author: Anuja Jose
Description: Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 30th Aug, 2025
==================================================================================================================================
*/




#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    struct flock file_lock;
    int fd;
    fd = open("dbfile.txt", O_RDWR );
    file_lock.l_start = 0;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_pid = getpid();
    file_lock.l_len = 0;
    file_lock.l_type = F_WRLCK;
    printf("Trying to write...\n");
    fcntl(fd, F_SETLKW, &file_lock);
    printf("Write lock acquired. Press enter to release\n");
    getchar();
    file_lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK,&file_lock);
    close(fd);
    return 0;

    
}

/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ gcc 16b.c -o writer 
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./writer 
Trying to write...
Write lock acquired. Press enter to release

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ gcc 16a.c -o reader
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./reader 
Trying to read...

*/