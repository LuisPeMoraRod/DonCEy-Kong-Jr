//
// Created by luispedro on 20/4/21.
//

#ifndef CLIENT_COMPONENTS_H
#define CLIENT_COMPONENTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constants.h"
#include "game.h"

struct player{
    SDL_Rect pos;
    SDL_Texture *current_texture;
    //SDL_Texture *run_right0;
    //SDL_Texture *run_right1;
    //SDL_Texture *run_left0;
    //SDL_Texture *run_left1;
    //char image_path[MAX_PATH];
    //int lives;
    //bool right_direction;
    //bool liana;
};

struct player * create_player();
void free_player();

#endif //CLIENT_COMPONENTS_H
