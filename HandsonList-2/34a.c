/*
==================================================================================================================================
Name: 34.c
Author: Anuja Jose
Description: Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 30th Sep, 2025
==================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT_NUM 23000
#define BUF_L 1024
#define MAX_CONN 5

int create_server_socket() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock_fd;
}

void bind_server_socket(int sock_fd, int port, struct sockaddr_in *addr) {
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_port = htons(port);
    if (bind(sock_fd, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
}

void listen_for_connections(int sock_fd) {
    if (listen(sock_fd, MAX_CONN) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT_NUM);
}

void handle_client(int fd) {
    char buf[BUF_L] = {0};
    read(fd, buf, BUF_L);
    printf("Message from client: %s\n", buf);
    char *reply = "Hello from server (fork)";
    send(fd, reply, strlen(reply), 0);
    close(fd);
    exit(0);
}

int main() {
    int server_fd = create_server_socket();
    struct sockaddr_in server_addr;
    bind_server_socket(server_fd, PORT_NUM, &server_addr);
    listen_for_connections(server_fd);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }
        pid_t pid = fork();
        if (pid == 0) { 
            printf("Child server: %d  ", getpid());
            close(server_fd);
            handle_client(client_fd);
        } else {
            close(client_fd);
        }
    }
    close(server_fd);
    return 0;
}



/*
Output:
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./a.out 
Server listening on port 23000...
Child server: 70001 Message from client: Hello from client!
Child server: 70032 Message from client: Hello from client!
Child server: 70163 Message from client: Hello from client!
Child server: 70273 Message from client: Hello from client!


anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./clie 
Message sent to server: Hello from client!
Response from server: Hello from server (fork)
anuja@anuja-Precision-5550:~/Documents/SS/SS-HOL/HandsonList-2$ ./clie 
Message sent to server: Hello from client!
Response from server: Hello from server (fork)
*/