
//
// Created by Luis Pedro Morales on 20/4/21.
//

#include "game.h"

//The window to be rendering
SDL_Window* window = NULL;

//The window renderer
SDL_Renderer* renderer = NULL;

//Current displayed background_texture
SDL_Texture* background_texture = NULL;


/**
 * Attempts to initialize and SDL window. In case of success, begins game loop.
 */
void start_game(){
    //Start is_up SDL and create window
    if( !init_window() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load background image
        const char *background_path = BG_PATH;
        background_texture = load_texture(background_path);
        if (background_texture != NULL) {
            game_loop();
        } else {
            printf("Failed to load media!\n");
        }
    }

    //Free resources and close SDL
    close_window();
}

/**
 * Attempts to create a SDL window
 * @return bool
 */
bool init_window(){
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
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
        if(window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
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
                    success = false;
                }
            }
        }
    }
    return success;
}


/**
 * Free SDL graphic resources
 */
void close_window()
{
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

SDL_Texture *load_texture(const char path[MAX_PATH]){
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
            printf( "Unable to createtexture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
void game_loop(){
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event event;

    struct player *donkey_jr = NULL;
    donkey_jr = create_player();

    SDL_Rect *pos = NULL;

    int cont_temp = 0;
    struct red_croc *croc = NULL;

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
            } else if (event.type == SDL_KEYDOWN){
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
                        croc = create_red_croc(cont_temp);
                        cont_temp++;
                        break;;

                }
            }
        }
        //controls jump and falling movements
        control_dk_movement(&donkey_jr);


        //Clear screen
        SDL_RenderClear( renderer );

        //Render background_texture to screen
        SDL_RenderCopy(renderer, background_texture, NULL, NULL );

        pos = &donkey_jr->pos;
        SDL_RenderCopy(renderer, donkey_jr->current_texture, NULL, pos );

        if(croc != NULL){
            pos = &croc->pos;
            SDL_RenderCopy(renderer, croc->current_texture, NULL, pos);

        }

        //Update screen
        SDL_RenderPresent( renderer );

        SDL_Delay( DELAY );
    }

    free_player(&donkey_jr); //free resources
    free_red_croc(&croc);
}


