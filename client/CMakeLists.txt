cmake_minimum_required(VERSION 3.19)
project(client C)

set(CMAKE_C_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-pthread")

add_executable(client main.c socket_client.c socket_client.h constants.h game.c game.h player.c player.h game.c enemies.c enemies.h fruits.c fruits.h menu.c menu.h)