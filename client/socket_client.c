//
// Created by Luis Pedro Morales on 15/4/21.
//

#include "socket_client.h"

void *read_stream(struct socket_info **socket_ptr){
    struct socket_info *sock = *socket_ptr;
    int socket= sock->socket_ptr;
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
            }else{
                struct red_croc *croc = NULL;
                croc = create_red_croc(sock->renderer, 3);
                add_red_croc(sock->first_croc, sock->first_croc, &croc);
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

void create_socket(int port, SDL_Renderer ** renderer_ptr, struct node ** first_croc, struct node** last_croc){
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
    serv_addr.sin_port = htons(port);

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

    size_t size = sizeof(struct socket_info);
    struct socket_info * sock_info = malloc(size);
    sock_info->socket_ptr = sock;
    sock_info->first_croc = first_croc;
    sock_info->last_croc = last_croc;
    sock_info->renderer = renderer_ptr;

    pthread_create(&receiver_thread, NULL, &read_stream, &sock_info);
    //pthread_join(receiver_thread, NULL);
}


