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



int main(int argc, char *argv[]) {

    if(argc!=2)
    {
        printf("Enter a record number as argument");
        exit(0);
    }        
    struct flock lock;
    const int recs = 3;
    int recno = atoi(argv[1]);
    int recval;
    
    int fd = open("record.dat", O_RDWR | O_CREAT, 0644);

    printf("Acquiring write lock on record..%d\n", recno);
        
    lock.l_type = F_WRLCK;      
    lock.l_whence = SEEK_SET;
    lock.l_start = (recno-1) * sizeof(int); 
    lock.l_len = sizeof(int);     
    lock.l_pid = getpid();
    fcntl(fd, F_SETLKW, &lock);
    printf("Acquired write lock on record %d\n", recno);
    lseek(fd, (recno-1 )* sizeof(int), SEEK_SET);
    read(fd, &recval, sizeof(int));
    printf("\nCurrent value at record%d = %d\n",recno,recval);
    recval +=1;
    lseek(fd, (recno-1)* sizeof(int), SEEK_SET);
    write(fd, &recval, sizeof(int));
    printf("\nUpdated value at record%d = %d\nPress enter to release..",recno,recval);


    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Released write lock on record %d\n", recno);

    close(fd);
    return 0;
}


/*
Output:

anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 18b.c -o write_lock
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./write_lock 2
Acquiring write lock on record..2
Acquired write lock on record 2

Current value at record2 = 20

Updated value at record2 = 21
Press enter to release..
Released write lock on record 2
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./write_lock 3
Acquiring write lock on record..3

*/