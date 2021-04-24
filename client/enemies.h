//
// Created by Luis Pedro Morales on 23/4/21.
//

#ifndef CLIENT_ENEMIES_H
#define CLIENT_ENEMIES_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include "constants.h"
#include "player.h"
#include "game.h"

struct red_croc{
    SDL_Rect pos;
    SDL_Texture *current_texture;

    SDL_Texture *up0;
    SDL_Texture *up1;
    SDL_Texture *down0;
    SDL_Texture *down1;
    int sprite;
    bool is_up;
};

struct blue_croc{
    SDL_Rect pos;
    SDL_Texture *current_texture;

    SDL_Texture *up0;
    SDL_Texture *up1;
    SDL_Texture *down0;
    SDL_Texture *down1;
    int sprite;
    bool up;
    bool fall;
};

struct node{
    struct red_croc *red_croc_ptr;
    struct blue_croc *blue_croc_ptr;
    struct node* next_node;
};

struct red_croc* create_red_croc(int liana);
struct red_croc* set_position(int x, int y, struct red_croc ** red_croc_ptr);
void free_red_croc(struct red_croc** red_croc_ptr);
void free_blue_croc(struct blue_croc** blue_croc_ptr);

#endif //CLIENT_ENEMIES_H
