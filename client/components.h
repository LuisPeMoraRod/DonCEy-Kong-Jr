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

    SDL_Texture *run_right0;
    SDL_Texture *run_right1;
    SDL_Texture *run_left0;
    SDL_Texture *run_left1;
    SDL_Texture *jump_right;
    SDL_Texture *jump_left;
    SDL_Texture *liana_right0;
    SDL_Texture *liana_right1;
    SDL_Texture *liana_left0;
    SDL_Texture *liana_left1;
    SDL_Texture *stand_right;
    SDL_Texture *stand_left;

    int y_height;

    int sprite;
    int lives;
    bool right;
    bool liana;
    bool jump;
    bool fall;
};

struct player * create_player();
void free_player();
void move_left(struct player **donkey_jr_ptr);
void move_right(struct player **donkey_jr_ptr);
void jump(struct player **donkey_jr_ptr);
void move_up(struct player **donkey_jr_ptr);
void move_down(struct player **donkey_jr_ptr);
void control_dk_movement(struct player **donkey_jr_ptr);
bool on_platform(struct player **donkey_jr_ptr);

#endif //CLIENT_COMPONENTS_H
