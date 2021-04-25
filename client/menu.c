//
// Created by luispedro on 25/4/21.
//

#include "menu.h"
#include "game.h"

/**
 * Attempts to initialize and SDL window. In case of success, begins game loop.
 */
void start_menu(){

    //The window to be rendering
    SDL_Window* window = NULL;

    //The window renderer
    SDL_Renderer* renderer = NULL;

    //Current displayed background_texture
    SDL_Texture* background_texture = NULL;

    window = init_wdw();

    if(window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }else{
        renderer = init_renderer(&window);
        if(renderer != NULL){
            const char *background_path = MENU_BG;
            background_texture = load_texture(&renderer, background_path);
            if (background_texture != NULL) {
                menu_loop(&renderer, &background_texture);
            } else {
                printf("Failed to load media!\n");
            }
        }
    }

    //Free resources and close SDL
    close_window(&window, &renderer, &background_texture);
}

/**
 * Adds images of imprisoned Donkey Kong, Mario and Key
 * @param renderer_ptr: SDL_Renderer **
 */
void add_buttons(SDL_Renderer ** renderer_ptr){
    SDL_Renderer *renderer = *renderer_ptr;
    const char *path = PLAYER0_PATH;

    SDL_Texture *texture = load_texture(&renderer, path);
    SDL_Rect pos_0 = {BTN0_X, BTN0_Y, BTN_WIDTH, BTN_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_0);

    path = PLAYER1_PATH;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_1 = {BTN0_X, BTN1_Y, BTN_WIDTH, BTN_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_1);

    path = OBS0_PATH;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_2 = {BTN0_X, BTN2_Y, BTN_WIDTH, BTN_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_2);

    path = OBS1_PATH;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_3 = {BTN0_X, BTN3_Y, BTN_WIDTH, BTN_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_3);

    path = STAR_PATH;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_4 = {STAR_X, STAR_Y0, STAR_WIDTH, STAR_WIDTH};
    SDL_RenderCopy(renderer, texture, NULL, &pos_4);

    SDL_Rect pos_5 = {STAR_X, STAR_Y1, STAR_WIDTH, STAR_WIDTH};
    SDL_RenderCopy(renderer, texture, NULL, &pos_5);

}

/**
 * Main game loop of the client program
 * @param renderer_ptr: SDL_Renderer **
 * @param bg_txtr_ptr: SDL_Texture **
 */
void menu_loop(SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr){
    SDL_Renderer *renderer = *renderer_ptr;
    SDL_Texture *background_texture = *bg_txtr_ptr;
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event event;

    SDL_Rect *pos = NULL;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while(SDL_PollEvent( &event ) != 0 )
        {
            //User requests quit
            if(event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_RenderClear(renderer);

        //Render background_texture to screen
        SDL_RenderCopy(renderer, background_texture, NULL, NULL );

        add_buttons(&renderer);


        //Update screen
        SDL_RenderPresent( renderer );

        SDL_Delay( DELAY );
    }

}