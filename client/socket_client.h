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

void *read_stream(void *socket_ptr);
void *send_stream(void *socket_ptr);

void create_socket1();

void create_socket();

#endif //CLIENT_SOCKET_CLIENT_H
