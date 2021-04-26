//
// Created by Luis Pedro Morales on 15/4/21.
//

#ifndef CLIENT_SOCKET_CLIENT_H
#define CLIENT_SOCKET_CLIENT_H

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "constants.h"
#include "game.h"

struct socket_info{
    void *socket_ptr;
    SDL_Renderer *renderer;
    struct node ** first_croc;
    struct node** last_croc;
    struct fruit** first_fruit;
    struct fruit** last_fruit;
};
void *read_stream(struct socket_info **socket_ptr);
void *send_stream(void *socket_ptr);

void create_socket(int port, SDL_Renderer ** renderer_ptr, struct node ** first_croc, struct node** last_croc, struct fruit** first_fruit, struct fruit** last_fruit);

#endif //CLIENT_SOCKET_CLIENT_H
