//
// Created by luispedro on 25/4/21.
//

#ifndef CLIENT_MENU_H
#define CLIENT_MENU_H
#include "game.h"

struct box{
    int x;
    int y;
    int width;
    int height;
};
void start_menu();
void add_buttons(SDL_Renderer ** renderer_ptr);
void menu_loop(SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr);

#endif //CLIENT_MENU_H
