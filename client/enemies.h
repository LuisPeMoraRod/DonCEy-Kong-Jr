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
    bool dissapeared;
};

struct node{
    struct red_croc *red_croc_ptr;
    struct blue_croc *blue_croc_ptr;
    struct node* next_node;
};

void add_red_croc(struct node ** first, struct node** last, struct red_croc ** croc);
void add_blue_croc(struct node ** first, struct node** last, struct blue_croc ** croc);
void render_crocs(SDL_Renderer ** renderer_ptr, struct node **first);
void free_croc_list(struct node **first);
struct red_croc* create_red_croc(SDL_Renderer **renderer_ptr, int liana);
struct red_croc* set_position_red(int x, int y, struct red_croc ** red_croc_ptr);
struct blue_croc* create_blue_croc(SDL_Renderer **renderer_ptr, int liana);
struct blue_croc* set_position_blue(int x, int y, struct blue_croc ** blue_croc_ptr);
void free_red_croc(struct red_croc** red_croc_ptr);
void free_blue_croc(struct blue_croc** blue_croc_ptr);
void control_crocs_mov(struct node ** first_ptr);
void movement_blue_croc(struct blue_croc ** blue_croc_ptr);
void movement_red_croc(struct red_croc ** red_croc_ptr);

#endif //CLIENT_ENEMIES_H
