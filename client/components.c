//
// Created by luispedro on 20/4/21.
//

#include "components.h"

/**
 * Creates Donkey Kong Jr struct object
 * @return
 */
struct player *create_player(){
    const char *donkey_jr_path = DK_RUN_R1;
    SDL_Texture *player_txtr = load_texture(donkey_jr_path);
    size_t size = sizeof(struct player);
    struct player * donkey_jr = malloc(size);
    donkey_jr->current_texture = player_txtr;
    int x = 115, y = 572; //initial position
    SDL_Rect pos_rect = {x, y, DKJR_WIDTH, DKJR_HEIGHT};
    donkey_jr->pos = pos_rect;
    return donkey_jr;
}

/**
 * Free resources of player struct (including graphics)
 */
void free_player(){

}

