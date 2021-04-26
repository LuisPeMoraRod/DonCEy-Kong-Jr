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
                const char delim[] = ";";
                char *message = strtok(buffer + 2, delim);
                int token_cont = 0;
                int action, type, pos;

                while(message != NULL){
                    switch (token_cont) {
                        case ACTION:
                            action = atoi(message);
                            break;
                        case TYPE:
                            type = atoi(message);
                            break;;
                        case POSITION:
                            pos = atoi(message);
                            break;
                    }
                    ++token_cont;
                    printf("%s\t", message);
                    message = strtok(NULL, delim);
                }
                printf("action %d", action);
                if (action == ADD_CROC){
                    if (type == RED){
                        struct red_croc *croc = NULL;
                        croc = create_red_croc(sock->renderer, pos);
                        add_red_croc(sock->first_croc, sock->first_croc, &croc);
                    }else if (type == BLUE){
                        struct blue_croc *croc = NULL;
                        croc = create_blue_croc(sock->renderer, pos);
                        add_blue_croc(sock->first_croc, sock->first_croc, &croc);
                    }
                }else if (action == ADD_FRUIT){
                    struct fruit * temp_fruit = NULL;
                    if (type == BANANA){
                        temp_fruit = create_fruit(sock->first_fruit, sock->last_fruit, sock->renderer, pos, BANANA, BANANA_PTS);
                        add_fruit(sock->first_fruit, sock->last_fruit, &temp_fruit);
                    }else if (type == MANGO){
                        temp_fruit = create_fruit(sock->first_fruit, sock->last_fruit, sock->renderer, pos, MANGO, MANGO_PTS);
                        add_fruit(sock->first_fruit, sock->last_fruit, &temp_fruit);
                    }else if (type == APPLE){
                        temp_fruit = create_fruit(sock->first_fruit, sock->last_fruit, sock->renderer, pos, APPLE, APPLE_PTS);
                        add_fruit(sock->first_fruit, sock->last_fruit, &temp_fruit);
                    }
                }else if(action == DELETE_FRUIT){
                    delete_fruit(sock->first_fruit, pos);
                }
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

void create_socket(int port, SDL_Renderer ** renderer_ptr, struct node ** first_croc, struct node** last_croc, struct fruit** first_fruit, struct fruit** last_fruit){
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
    sock_info->first_fruit = first_fruit;
    sock_info->last_fruit = last_fruit;

    pthread_create(&receiver_thread, NULL, &read_stream, &sock_info);
    //pthread_join(receiver_thread, NULL);
}


