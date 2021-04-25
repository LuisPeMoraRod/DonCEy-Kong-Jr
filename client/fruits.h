//
// Created by luispedro on 25/4/21.
//

#ifndef CLIENT_FRUITS_H
#define CLIENT_FRUITS_H
#include "game.h"

struct fruit{
    int points;
    SDL_Rect *pos;
    SDL_Texture * texture;
};

#endif //CLIENT_FRUITS_H
