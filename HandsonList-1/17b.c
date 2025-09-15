/*
==================================================================================================================================
Name: 17.c
Author: Anuja Jose
Description: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 30th Aug, 2025
==================================================================================================================================
*/




#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    int ticket;
    struct flock tkt_lock;
    fd = open("ticket_number.txt", O_RDWR);
    tkt_lock.l_type = F_WRLCK;
    tkt_lock.l_whence = SEEK_SET;
    tkt_lock.l_start = 0;
    tkt_lock.l_len = 0; 
    fcntl(fd, F_SETLKW, &tkt_lock);
    printf("Preparing to reserve ticket...\n");
    lseek(fd, 0, SEEK_SET);
    read(fd, &ticket, sizeof(ticket));
    printf("Current ticket number: %d\n", ticket);
    ticket +=1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));
    printf("Ticket reservation successful.\nTicket number = %d\n", ticket);
    tkt_lock.l_type = F_UNLCK;
    sleep(2);
    fcntl(fd, F_SETLK, &tkt_lock);
    close(fd);
    return 0;
}

/*
Output:

cc 17a.c -o tkt_init
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 17b.c -o reserve_tkt
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./tkt_init 
Ticket file initialized with ticket number = 0
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ cc 17b.c -o reserve_tkt
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./reserve_tkt 
Preparing to reserve ticket...
Current ticket number: 0
Ticket reservation successful.
Ticket number = 1
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./reserve_tkt 
Preparing to reserve ticket...
Current ticket number: 1
Ticket reservation successful.
Ticket number = 2
anuja@anuja-Precision-5550:~/Documents/SS/handsonl1$ ./reserve_tkt 
Preparing to reserve ticket...
Current ticket number: 2
Ticket reservation successful.
Ticket number = 3

*/