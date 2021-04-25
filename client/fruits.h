//
// Created by luispedro on 25/4/21.
//

#ifndef CLIENT_FRUITS_H
#define CLIENT_FRUITS_H
#include "game.h"

struct fruit{
    int points;
    int platform;
    bool visible;
    SDL_Rect pos;
    SDL_Texture * texture;
    struct fruit * next_node;
};

struct fruit * create_fruit(struct fruit **first, struct fruit **last, SDL_Renderer **renderer_ptr, int platform, int fruit_type, int points);
void set_fruit_pos(int x, int y, struct fruit ** fruit_ptr);
void add_fruit(struct fruit **first, struct fruit **last, struct fruit ** new_fruit);
void render_fruits(SDL_Renderer ** renderer_ptr, struct fruit **first);
void free_fruits_list(struct fruit ** first);
#endif //CLIENT_FRUITS_H