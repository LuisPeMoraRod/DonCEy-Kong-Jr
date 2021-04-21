//
// Created by luispedro on 20/4/21.
//

#include "game.h"
void start_game(){
    SDL_Surface  *screen;
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't init SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    screen = SDL_SetVideoMode(WIN_WIDTH,WIN_HEIGHT, BPP, SDL_HWSURFACE);
    if (screen == NULL) {
        printf("Error while trying to init graphic mode: %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("DonCEy Kong Jr", "DonCEy Kong Jr");

    screen = create_background(&screen);

    SDL_Delay(50000);

    SDL_Quit();
}

SDL_Surface * create_background(SDL_Surface **screen_ptr){
    const char *background_path = BG_PATH;
    //SDL_Surface * image = IMG_Load("PICT3159.JPG");

    SDL_Surface *screen = *screen_ptr;
    SDL_Surface  *background;
    SDL_Surface *donkey_jr;
    SDL_Rect rect;

    background = SDL_LoadBMP(background_path);

    //background located at origin (0,0)
    rect.x = 0;
    rect.y = 0;
    SDL_BlitSurface(background, NULL, screen, &rect);

    SDL_Flip(screen);

    return screen;
}