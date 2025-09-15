/*
==================================================================================================================================
Name: 18.c
Author: Anuja Jose
Description: Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three recsin a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2025
==================================================================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

# define SIZE 3

int main(int argc, char *argv[]) {

    if(argc!=2)
    {
        printf("Enter a record number as argument");
        exit(0);
    }    
        
    struct flock lock;
    int recno = atoi(argv[1]);
    int recval;
    int fd = open("record.dat", O_RDWR | O_CREAT, 0644);


    off_t size = lseek(fd, 0, SEEK_END);
    if (size < SIZE* sizeof(int)) {
        int vals[SIZE] = {10,20,30}; 
        write(fd, vals, sizeof(vals));
    }
    printf("Acquiring read lock on record..%d\n", recno);
        
    lock.l_type = F_RDLCK;      
    lock.l_whence = SEEK_SET;
    lock.l_start = (recno-1)* sizeof(int); 
    lock.l_len = sizeof(int);     
    lock.l_pid = getpid();
    fcntl(fd, F_SETLKW, &lock);
    printf("Acquired read lock on record %d\n", recno);
    lseek(fd, (recno-1)* sizeof(int), SEEK_SET);
    read(fd, &recval, sizeof(int));
    printf("Current value at record %d: %d\n Press enter to release..\n", recno, recval);
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Released read lock on record %d\n", recno);

    close(fd);
    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 18a.c -o read_lock
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./read_lock 3
Acquiring read lock on record..3
Acquired read lock on record 3
Current value at record 3: 30
 Press enter to release..
*/