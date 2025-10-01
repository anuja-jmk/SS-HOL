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
#include <pthread.h>

#define PORT_NUM 23000
#define BUF_L 1024
#define BACKLOG 5

void* client_handler(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread %lu handling this client\n", (unsigned long)tid);
    int client_fd = *(int*)arg;
    free(arg);

    char buffer[BUF_L] = {0};
    read(client_fd, buffer, BUF_L);
    printf("Message from client: %s\n", buffer);

    const char *reply = "Hello from server (pthread)";
    send(client_fd, reply, strlen(reply), 0);

    close(client_fd);
    pthread_exit(NULL);
}

int setup_server_socket(int port, struct sockaddr_in *addr) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_port = htons(port);

    if (bind(sock_fd, (struct sockaddr*)addr, sizeof(*addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, BACKLOG) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);
    return sock_fd;
}

int main() {
    struct sockaddr_in server_addr;
    int server_fd = setup_server_socket(PORT_NUM, &server_addr);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int *client_fd = malloc(sizeof(int));
        if (!client_fd) { perror("malloc"); continue; }

        *client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (*client_fd < 0) {
            perror("Accept failed");
            free(client_fd);
            continue;
        }

        pthread_t tid;
        pthread_create(&tid, NULL, client_handler, client_fd);
        pthread_detach(tid);  // automatically reclaim thread resources
    }

    close(server_fd);
    return 0;
}



/*
Output:


*/