//
// Created by Luis Pedro Morales on 15/4/21.
//

#include "socket_client.h"

void *read_stream(void *socket_ptr){
    int socket= *(int*)socket_ptr;
    for (;;){
        char buffer[MAX_BUFFER]; //buffer size as defined in constants.h
        int x; //last position of buffer
        if ((x=read(socket , buffer, MAX_BUFFER)) > 0){
            buffer[x]='\0'; // \0 indicates the end
            printf("%s\n", buffer + 2);
            if (strcmp(buffer + 2, "Over") == 0){
                printf("Closing socket ...");
                close(socket);
                break;
            }
            fflush(stdout); //clear the buffer
        }
    }
}

void *send_stream(void *socket_ptr){
    int socket = *(int*)socket_ptr;
    char message[40];
    //for(;;){
        printf("Write message to java server: ");
        scanf("%s", message);
        //char end[1] = ".";
        //strcat(message, end);
        send(socket, message, strlen(message), 0);
        printf("%s", message);
        if (strcmp(message, "Over") == 0){
            printf("Closing socket ...");
            close(socket);
            //break;
        }
        fflush(stdout); //clear the buffer
    //}
}

void create_socket(){
    pthread_t sender_thread, receiver_thread;
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid/not supported address.\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection failed \n");
        exit(EXIT_FAILURE);
    }

    pthread_create(&sender_thread, NULL, &send_stream, &sock);
    pthread_join(sender_thread, NULL);
}

void create_socket1(){
    int sockfd, new_socket, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if (bind(sockfd, (SA *) &servaddr, sizeof(servaddr)) != 0) {
        printf("Socket bind failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Successful socket bind..\n");

    // Now server is ready to listen and verification
    if (listen(sockfd, 5) != 0) {
        printf("Listen failed...\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    /*
    // Accept the data packet from client_ex and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }*/

    if ((new_socket = accept(sockfd, (struct sockaddr *)&servaddr,
                             (socklen_t*)&len))<0)
    {
        perror("Server failed accepting socket");
        exit(EXIT_FAILURE);
    }
    printf("server acccept the client_ex...\n");

    // Function for chatting between client_ex and server
    //read_stream(&new_socket);
    send_stream(&new_socket);

    // After chatting close_window the socket
    //close_window(sockfd);
}

