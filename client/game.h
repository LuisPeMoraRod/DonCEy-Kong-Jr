//
// Created by luispedro on 20/4/21.
//

#ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
//#include <SDL/SDL.h>
#include "constants.h"

void start_game();
bool init_window();
SDL_Texture *load_texture(const char path[MAX_PATH]);
void close_window();
void game_loop();
void add_player();
//SDL_Surface * create_background();

#endif //CLIENT_GAME_H
