//
// Created by Luis Pedro Morales on 20/4/21.
//

#ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include "constants.h"
#include "player.h"
#include "enemies.h"

void start_game();
SDL_Window *init_wdw();
SDL_Renderer *init_renderer(SDL_Window ** window_ptr);
void add_static_textures(SDL_Renderer ** renderer_ptr);
SDL_Texture *load_texture(SDL_Renderer **renderer_ptr, const char path[MAX_PATH]);
void close_window(SDL_Window **window_ptr, SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr);
void game_loop(SDL_Renderer **renderer_ptr, SDL_Texture **bg_txtr_ptr);

#endif //CLIENT_GAME_H