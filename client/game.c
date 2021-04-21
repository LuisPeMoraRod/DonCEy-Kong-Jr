//
// Created by luispedro on 21/4/21.
//

//
// Created by luispedro on 20/4/21.
//

#include "game.h"
/*
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
}*/

/*
void start_game(){
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "DonCEy Kong Jr", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
*/

//The window to be rendering
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screen_surface = NULL;

//The image to be loaded and shown on the screen
SDL_Surface* background = NULL;

void start_game(){
    //Start up SDL and create window
    if( !init_window() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !load_media() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( background, NULL, screen_surface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Free resources and close SDL
    close_window();
}

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
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN );
        if(window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            screen_surface = SDL_GetWindowSurface(window );
        }
    }
    return success;
}

bool load_media()
{
    const char *background_path = BG_PATH;
    //Loading success flag
    bool success = true;

    //Load splash image
    background = SDL_LoadBMP(background_path );
    if(background == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", background_path, SDL_GetError() );
        success = false;
    }

    return success;
}

void close_window()
{
    //Deallocate surface
    SDL_FreeSurface(background);
    background = NULL;

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}