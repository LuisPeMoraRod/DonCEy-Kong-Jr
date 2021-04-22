//
// Created by luispedro on 20/4/21.
//

#include "components.h"

struct player{
    SDL_Rect pos;
    SDL_Texture *texture;
    char image_path[MAX_PATH];
    int lives;
    bool right_direction;
    bool liana;
};

