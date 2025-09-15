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
    int ticket = 0;

    fd = open("ticket_number.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    write(fd, &ticket, sizeof(ticket));
    printf("Ticket file initialized with ticket number = %d\n", ticket);
    close(fd);
    return 0;
}