//
// Created by luispedro on 20/4/21.
//

#include "components.h"

/**
 * Creates Donkey Kong Jr struct object
 * @return
 */
struct player *create_player(){
    size_t size = sizeof(struct player);
    struct player * donkey_jr = malloc(size); //new struct

    const char *donkey_jr_path = NULL;
    SDL_Texture *donkey_jr_txtr = NULL;

    //set all textures (one for every sprite)
    donkey_jr_path = DK_RUN_R0;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->run_right0 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_R1;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->run_right1 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L0;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->run_left0 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L1;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->run_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L1;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->run_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_JUMP_R;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->jump_right = donkey_jr_txtr;

    donkey_jr_path = DK_JUMP_L;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->jump_left = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_R0;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->liana_right0 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_R1;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->liana_right1 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_L0;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->liana_left0 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_L1;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->liana_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_STAND_R;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->stand_right = donkey_jr_txtr;

    donkey_jr_path = DK_STAND_L;
    donkey_jr_txtr = load_texture(donkey_jr_path);
    donkey_jr->stand_left = donkey_jr_txtr;

    int x = DK_X0; int y = DK_Y0; //initial position
    SDL_Rect pos_rect = {x, y, DKJR_WIDTH, DKJR_HEIGHT};
    donkey_jr->pos = pos_rect;
    donkey_jr->y_height = y;

    donkey_jr->current_texture = donkey_jr->stand_right;
    donkey_jr->sprite = STAND_R0;

    donkey_jr->jump = false;
    donkey_jr->right = true;
    donkey_jr->fall = false;

    return donkey_jr;
}

/**
 * Moves sprite to the right
 * @param donkey_jr_ptr: struct player **
 */
void move_right(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    donkey_jr->right = true;
    donkey_jr->pos.x += MOV;
    if (donkey_jr->jump) {
        donkey_jr->pos.y -= JUMP;
    } else if (donkey_jr->sprite == STAND_R0){
        donkey_jr->sprite = RUN_R0;
        donkey_jr->current_texture = donkey_jr->run_right0;
    }else if (donkey_jr->sprite == RUN_R0){
        donkey_jr->sprite = STAND_R1;
        donkey_jr->current_texture = donkey_jr->stand_right;
    }else if (donkey_jr->sprite == STAND_R1){
        donkey_jr->sprite = RUN_R1;
        donkey_jr->current_texture = donkey_jr->run_right1;
    }else if(donkey_jr->sprite == RUN_R1){
        donkey_jr->sprite = STAND_R0;
        donkey_jr->current_texture = donkey_jr->stand_right;
    } else{
        donkey_jr->sprite = STAND_R0;
        donkey_jr->current_texture = donkey_jr->stand_right;
    }
}

/**
 * Moves sprite to the left
 * @param donkey_jr_ptr: struct player **
 */
void move_left(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    donkey_jr->right = false;
    donkey_jr->pos.x -= MOV;
    if (donkey_jr->jump){
        donkey_jr->pos.y -= JUMP;
    }else if (donkey_jr->sprite == STAND_L0){
        donkey_jr->sprite = RUN_L0;
        donkey_jr->current_texture = donkey_jr->run_left0;
    }else if (donkey_jr->sprite == RUN_L0){
        donkey_jr->sprite = STAND_L1;
        donkey_jr->current_texture = donkey_jr->stand_left;
    }else if (donkey_jr->sprite == STAND_L1){
        donkey_jr->sprite = RUN_L1;
        donkey_jr->current_texture = donkey_jr->run_left1;
    }else if(donkey_jr->sprite == RUN_L1){
        donkey_jr->sprite = STAND_L0;
        donkey_jr->current_texture = donkey_jr->stand_left;
    }else{
        donkey_jr->sprite = STAND_L0;
        donkey_jr->current_texture = donkey_jr->stand_left;
    }
}

/**
 * Begins jumping routine
 * @param donkey_jr_ptr: struct player **
 */
void jump(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    donkey_jr->jump = true;
    donkey_jr->pos.y -= JUMP;
    if (donkey_jr->right){
        donkey_jr->sprite = JUMP_R;
        donkey_jr->current_texture = donkey_jr->jump_right;
    }else{
        donkey_jr->sprite = JUMP_L;
        donkey_jr->current_texture = donkey_jr->jump_left;
    }
}
/**
 * Moves Donkey Kong Jr up until a certain height given by JUMP_DIFF
 * @param donkey_jr_ptr: struct player **
 */
void move_up(struct player **donkey_jr_ptr){
    struct player * donkey_jr = *donkey_jr_ptr;
    int difference = donkey_jr->y_height - donkey_jr->pos.y;
    if (difference >= JUMP_DIFF){
        donkey_jr->jump = false; //end jump routine
        donkey_jr->fall = true;
    }else{
        donkey_jr->pos.y -= JUMP;
    }
}

/**
 * Moves Donkey Kong Jr down until it finds a platform or liana
 * @param donkey_jr_ptr: struct player **
 */
void move_down(struct player **donkey_jr_ptr){
    struct player * donkey_jr = *donkey_jr_ptr;
    if (on_platform(&donkey_jr)){
        if(donkey_jr->right){
            donkey_jr->sprite = STAND_R0;
            donkey_jr->current_texture = donkey_jr->stand_right;
        }else{
            donkey_jr->sprite = STAND_L0;
            donkey_jr->current_texture = donkey_jr->stand_left;
        }
        donkey_jr->fall = false; //stop falling
    }else{
        donkey_jr->pos.y += JUMP; //keep falling
    }
}

bool on_platform(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    int x = donkey_jr->pos.x;
    int y = donkey_jr->pos.y;
    if ( x >= P0_X0 && x <= P0_X1 && y == P0_Y) {
        return true;
    }
    return false;

}
void control_dk_movement(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if(donkey_jr->jump) move_up(&donkey_jr);
    else if (donkey_jr->fall) move_down(&donkey_jr);
}
/**
 * Free resources of player struct (including graphics)
 */
void free_player(){

}

