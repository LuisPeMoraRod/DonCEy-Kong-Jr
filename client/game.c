
//
// Created by Luis Pedro Morales on 20/4/21.
//

#include "game.h"

/**
 * Attempts to initialize and SDL window. In case of success, begins game loop.
 */
void start_game(){

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
            const char *background_path = BG_PATH;
            background_texture = load_texture(&renderer, background_path);
            if (background_texture != NULL) {
                game_loop(&renderer, &background_texture);
            } else {
                printf("Failed to load media!\n");
            }
        }
    }

    //Free resources and close SDL
    close_window(&window, &renderer, &background_texture);
}

/**
 * Creates windor
 * @return SDL_Window *
 */
SDL_Window * init_wdw(){
    SDL_Window *window = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Set background_texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear background_texture filtering not enabled!" );
        }
        //Create window
        window = SDL_CreateWindow("DonCEy Kong Jr", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN );
    }
    return window;
}

/**
 * Creates graphic renderer
 * @param window_ptr: SDL_Window **
 * @return SDL_Renderer *
 */
SDL_Renderer *init_renderer(SDL_Window ** window_ptr){
    SDL_Window *window = *window_ptr;
    SDL_Renderer *renderer = NULL;

    //Create renderer for window
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Initialize renderer color
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        }
    }
    return renderer;
}

/**
 * Free SDL graphic resources
 */
void close_window(SDL_Window **window_ptr, SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr)
{
    SDL_Window *window = *window_ptr;
    SDL_Renderer *renderer = *renderer_ptr;
    SDL_Texture *background_texture = *bg_txtr_ptr;
    //Free loaded image
    SDL_DestroyTexture(background_texture);
    background_texture = NULL;

    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

/**
 * Loads png image to be rendered
 * @param renderer_ptr: SDL_Renderer **
 * @param path : char
 * @return SDL_Texture *
 */
SDL_Texture *load_texture(SDL_Renderer **renderer_ptr, const char path[MAX_PATH]){
    SDL_Renderer *renderer = *renderer_ptr;
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Create new texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void add_static_textures(SDL_Renderer ** renderer_ptr){
    SDL_Renderer *renderer = *renderer_ptr;
    const char *path = DK;

    SDL_Texture *texture = load_texture(&renderer, path); //Add Donkey Kong in jail image
    SDL_Rect pos_dk = {DK_X, DK_Y, DK_WIDTH, DK_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_dk);

    path = MARIO;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_m = {M_X, M_Y, M_WIDTH, M_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_m);

    path = KEY;
    texture = load_texture(&renderer, path);
    SDL_Rect pos_k = {KEY_X, KEY_Y, KEY_WIDTH, KEY_HEIGHT};
    SDL_RenderCopy(renderer, texture, NULL, &pos_k);

}

/**
 * Main game loop of the client program
 * @param renderer_ptr: SDL_Renderer **
 * @param bg_txtr_ptr: SDL_Texture **
 */
void game_loop(SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr){

    SDL_Renderer *renderer = *renderer_ptr;
    SDL_Texture *background_texture = *bg_txtr_ptr;
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event event;

    struct player *donkey_jr = NULL;
    donkey_jr = create_player(renderer_ptr);

    SDL_Rect *pos = NULL;

    struct node * first_croc = NULL;
    struct node * last_croc = NULL;
    struct red_croc *croc = NULL;
    //struct blue_croc *croc = NULL;
    int cont_temp = 0;

    struct fruit * first_fruit = NULL;
    struct fruit * last_fruit = NULL;
    struct fruit * temp_fruit = NULL;

    //While application is running
    while( !quit )
    {
        quit = death(&donkey_jr);
        //Handle events on queue
        while(SDL_PollEvent( &event ) != 0 )
        {
            //User requests quit
            if(event.type == SDL_QUIT )
            {
                quit = true;
            } else if (event.type == SDL_KEYDOWN && !donkey_jr->is_dead){
                switch (event.key.keysym.sym) {

                    case SDLK_d: //move to the right
                        if(donkey_jr->liana){
                            r_side_liana(&donkey_jr);
                        }else{
                            move_right(&donkey_jr);
                        }
                        break;

                    case SDLK_a: //move to the left
                        if(donkey_jr->liana){
                            l_side_liana(&donkey_jr);
                        }else{
                            move_left(&donkey_jr);
                        }
                        break;

                    case SDLK_w: //climb is_up the liana
                        if(donkey_jr->liana){
                            move_up(&donkey_jr);
                        }
                        break;

                    case SDLK_s:
                        if(donkey_jr->liana){
                            move_down(&donkey_jr);
                        }
                        break;

                    case SDLK_SPACE:
                        jump(&donkey_jr);
                        break;

                    case SDLK_c:
                        croc = create_red_croc(renderer_ptr, cont_temp);
                        add_red_croc(&first_croc, &last_croc, &croc);
                        //croc = create_blue_croc(renderer_ptr, cont_temp);
                        //add_blue_croc(&first_croc, &last_croc, &croc);

                        temp_fruit = create_fruit(&first_fruit, &last_fruit, renderer_ptr, cont_temp, APPLE, 100);
                        add_fruit(&first_fruit, &last_fruit, &temp_fruit);
                        cont_temp++;
                        break;

                    case SDLK_e:
                        delete_fruit(&first_fruit, cont_temp - 1);
                        break;

                }
            }
        }

        //controls jump and falling movements
        control_dk_movement(&donkey_jr);

        //Clear screen
        SDL_RenderClear(renderer);

        //Render background_texture to screen
        SDL_RenderCopy(renderer, background_texture, NULL, NULL );

        add_static_textures(&renderer);

        //paint all crocs
        if(first_croc != NULL){
            enemy_collision(&donkey_jr, &first_croc);//checks for collisions with enemies
            control_crocs_mov(&first_croc);
            render_crocs(&renderer, &first_croc);
        }

        if (first_fruit != NULL) {
            fruit_collision(&donkey_jr, &first_fruit);
            render_fruits(&renderer, &first_fruit);
        }

        pos = &donkey_jr->pos;
        SDL_RenderCopy(renderer, donkey_jr->current_texture, NULL, pos );

        //Update screen
        SDL_RenderPresent( renderer );

        SDL_Delay( DELAY );
    }

    free_player(&donkey_jr); //free resources
    free_croc_list(&first_croc);
    free_fruits_list(&first_fruit);
}