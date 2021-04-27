//
// Created by Luis Pedro Morales on 20/4/21.
//

#ifndef CLIENT_PLAYER_H
#define CLIENT_PLAYER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <pthread.h>
#include "constants.h"
#include "game.h"
#include "fruits.h"
#include "enemies.h"

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
    SDL_Texture *death;

    int y_jump;

    int sprite;
    int points;
    int lives;
    int level;
    bool right;
    bool liana;
    bool jump;
    bool fall;
    bool is_dead;
};

struct player * create_player(SDL_Renderer **renderer_ptr, int lives, int level, int points);
void free_player(struct player **donkey_jr_ptr);
void move_left(struct player **donkey_jr_ptr);
void move_right(struct player **donkey_jr_ptr);
void move_up(struct player **donkey_jr_ptr);
void move_down(struct player **donkey_jr_ptr);
void jump(struct player **donkey_jr_ptr);
void jumping(struct player **donkey_jr_ptr);
void falling(struct player **donkey_jr_ptr);
void control_dk_movement(struct player **donkey_jr_ptr);
bool on_platform(struct player **donkey_jr_ptr);
bool reached_liana(struct player **donkey_jr_ptr);
void r_side_liana(struct player ** donkey_jr_ptr);
void l_side_liana(struct player ** donkey_jr_ptr);
bool death(struct player **donkey_jr_ptr);
bool top_liana(int x, int y);
bool fall_liana(int x, int y);
void enemy_collision(struct player **donkey_jr_ptr, struct node **first);
void fruit_collision(struct player **donkey_jr_ptr, struct fruit ** first);
bool is_collision(int x0, int y0, int x1, int y1, int width, int height);
bool win(struct player **donkey_jr_ptr);

void* print_stats(struct player ** donkey_jr_ptr);
#endif //CLIENT_PLAYER_H
