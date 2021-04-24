//
// Created by Luis Pedro Morales on 23/4/21.
//

#include "enemies.h"
/**
 * Creates new enemy. Malloc of new struct with SDL_Textures for rendering
 * @param liana: int
 * @return croc: struct red_croc *
 */
struct red_croc* create_red_croc(int liana){
    size_t size = sizeof(struct red_croc);
    struct red_croc * croc = malloc(size); //new struct

    const char *red_croc_path = NULL;
    SDL_Texture *red_croc_txtr = NULL;

    //set all textures (one for every sprite)
    red_croc_path = C_RED_UP0;
    red_croc_txtr = load_texture(red_croc_path);
    croc->up0 = red_croc_txtr;

    red_croc_path = C_RED_UP1;
    red_croc_txtr = load_texture(red_croc_path);
    croc->up1 = red_croc_txtr;

    red_croc_path = C_RED_DOWN0;
    red_croc_txtr = load_texture(red_croc_path);
    croc->down0 = red_croc_txtr;

    red_croc_path = C_RED_DOWN1;
    red_croc_txtr = load_texture(red_croc_path);
    croc->down1 = red_croc_txtr;

    croc->sprite = RED_DOWN0;
    croc->current_texture = croc->down0;
    croc->is_up = false;

    if (liana == LIANA0){
        set_position(L0_X,L0_Y0, &croc);
    }else if (liana == LIANA1){
        set_position(L1_X,L1_Y0, &croc);
    }else if (liana == LIANA2){
        set_position(L2_X,L2_Y0, &croc);
    }else if (liana == LIANA3){
        set_position(L3_X,L3_Y0, &croc);
    }else if (liana == LIANA4){
        set_position(L4_X,L4_Y0, &croc);
    }else if (liana == LIANA5){
        set_position(L5_X,L5_Y0, &croc);
    }else if (liana == LIANA6){
        set_position(L6_X,L6_Y0, &croc);
    }else if (liana == LIANA7){
        set_position(L7_X,L7_Y0, &croc);
    }else if (liana == LIANA8){
        set_position(L8_X,L8_Y0, &croc);
    }else if (liana == LIANA9){
        set_position(L9_X,L9_Y0, &croc);
    }else if (liana == LIANA10){
        set_position(L10_X,L10_Y0, &croc);
    }
    return croc;
}

struct red_croc* set_position(int x, int y, struct red_croc ** red_croc_ptr){
    struct red_croc* croc = *red_croc_ptr;
    if (x == L0_X){
        SDL_Rect pos_rect = {x, y, CROC_WIDTH, CROC_HEIGHT};
        croc->pos = pos_rect;
    } else{
        SDL_Rect pos_rect = {x + CROC_ADJ, y, CROC_WIDTH, CROC_HEIGHT};
        croc->pos = pos_rect;
    }
}

/**
 * Free resources of a red croc struct
 * @param red_croc_ptr: struc red_croc **
 */
void free_red_croc(struct red_croc** red_croc_ptr){
    struct red_croc* croc = *red_croc_ptr;
    SDL_DestroyTexture(croc->current_texture);
    SDL_DestroyTexture(croc->up0);
    SDL_DestroyTexture(croc->up1);
    SDL_DestroyTexture(croc->down0);
    SDL_DestroyTexture(croc->down1);
    free(croc);
}

/**
 * Free resources of a blue croc struct
 * @param blue_croc_ptr: struc red_croc **
 */
void free_blue_croc(struct blue_croc** blue_croc_ptr){
    struct blue_croc* croc = *blue_croc_ptr;
    SDL_DestroyTexture(croc->current_texture);
    SDL_DestroyTexture(croc->up0);
    SDL_DestroyTexture(croc->up1);
    SDL_DestroyTexture(croc->down0);
    SDL_DestroyTexture(croc->down1);
    free(croc);
}

