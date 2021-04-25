//
// Created by Luis Pedro Morales on 20/4/21.
//
#include "player.h"

/**
 * Creates Donkey Kong Jr struct object
 * @return
 */
struct player *create_player(SDL_Renderer **renderer_ptr){
    size_t size = sizeof(struct player);
    struct player * donkey_jr = malloc(size); //new struct

    const char *donkey_jr_path = NULL;
    SDL_Texture *donkey_jr_txtr = NULL;

    //set all textures (one for every sprite)
    donkey_jr_path = DK_RUN_R0;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->run_right0 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_R1;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->run_right1 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L0;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->run_left0 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L1;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->run_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_RUN_L1;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->run_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_JUMP_R;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->jump_right = donkey_jr_txtr;

    donkey_jr_path = DK_JUMP_L;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->jump_left = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_R0;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->liana_right0 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_R1;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->liana_right1 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_L0;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->liana_left0 = donkey_jr_txtr;

    donkey_jr_path = DK_LIANA_L1;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->liana_left1 = donkey_jr_txtr;

    donkey_jr_path = DK_STAND_R;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->stand_right = donkey_jr_txtr;

    donkey_jr_path = DK_STAND_L;
    donkey_jr_txtr = load_texture(renderer_ptr, donkey_jr_path);
    donkey_jr->stand_left = donkey_jr_txtr;

    int x = DK_X0; int y = DK_Y0; //initial position
    SDL_Rect pos_rect = {x, y, DKJR_WIDTH, DKJR_HEIGHT};
    donkey_jr->pos = pos_rect;
    donkey_jr->y_jump = y;

    donkey_jr->current_texture = donkey_jr->stand_right;
    donkey_jr->sprite = STAND_R0;

    donkey_jr->jump = false;
    donkey_jr->right = true;
    donkey_jr->fall = false;
    donkey_jr->liana = false;

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

    if(!on_platform(&donkey_jr)){
        donkey_jr->fall = true;
    }
    if (donkey_jr->fall) {
        donkey_jr->sprite = JUMP_R;
        donkey_jr->current_texture = donkey_jr->jump_right;
        donkey_jr->pos.y += JUMP;
    }else if (donkey_jr->jump){
        donkey_jr->sprite = JUMP_R;
        donkey_jr->current_texture = donkey_jr->jump_right;
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
    if (donkey_jr->pos.x-MOV >= DK_X0){
        donkey_jr->right = false;
        donkey_jr->pos.x -= MOV;
        if(!on_platform(&donkey_jr)){
            donkey_jr->fall = true;
        }
        if (donkey_jr->fall) {
            donkey_jr->sprite = JUMP_L;
            donkey_jr->current_texture = donkey_jr->jump_left;
            donkey_jr->pos.y += JUMP;
        }else if (donkey_jr->jump){
            donkey_jr->sprite = JUMP_L;
            donkey_jr->current_texture = donkey_jr->jump_left;
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
}

/**
 * Moves is_up the liana (alternates climbing sprites for movement visual sensation)
 * @param donkey_jr_ptr: struct player **
 */
void move_up(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if (!top_liana(donkey_jr->pos.x, donkey_jr->pos.y)){
        donkey_jr->pos.y-=MOV;
        if(donkey_jr->sprite == LIANA_L0){
            donkey_jr->sprite = LIANA_L1;
            donkey_jr->current_texture = donkey_jr->liana_left1;
        }else if(donkey_jr->sprite == LIANA_L1){
            donkey_jr->sprite = LIANA_L0;
            donkey_jr->current_texture = donkey_jr->liana_left0;
        }else if(donkey_jr->sprite == LIANA_R0){
            donkey_jr->sprite = LIANA_R1;
            donkey_jr->current_texture = donkey_jr->liana_right1;
        }else if(donkey_jr->sprite == LIANA_R1){
            donkey_jr->sprite = LIANA_R0;
            donkey_jr->current_texture = donkey_jr->liana_right0;
        }
    }
}

/**
 * Moves down the liana (alternates climbing sprites for movement visual sensation)
 * @param donkey_jr_ptr: struct player **
 */
void move_down(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    donkey_jr->pos.y+=MOV;
    if (fall_liana(donkey_jr->pos.x, donkey_jr->pos.y)){
        donkey_jr->fall = true;
        donkey_jr->liana = false;
        if(donkey_jr->right){
            donkey_jr->sprite = JUMP_R;
            donkey_jr->current_texture = donkey_jr->jump_right;
        }else{
            donkey_jr->sprite = JUMP_L;
            donkey_jr->current_texture = donkey_jr->jump_left;
        }
    }else if(donkey_jr->sprite == LIANA_L0){
        donkey_jr->sprite = LIANA_L1;
        donkey_jr->current_texture = donkey_jr->liana_left1;
    }else if(donkey_jr->sprite == LIANA_L1){
        donkey_jr->sprite = LIANA_L0;
        donkey_jr->current_texture = donkey_jr->liana_left0;
    }else if(donkey_jr->sprite == LIANA_R0){
        donkey_jr->sprite = LIANA_R1;
        donkey_jr->current_texture = donkey_jr->liana_right1;
    }else if(donkey_jr->sprite == LIANA_R1){
        donkey_jr->sprite = LIANA_R0;
        donkey_jr->current_texture = donkey_jr->liana_right0;
    }
}

/**
 * Switches to right side of the liana
 * @param donkey_jr_ptr: struct player **
 */
void r_side_liana(struct player ** donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if(donkey_jr->right) {
        donkey_jr->right = false;
        donkey_jr->pos.x += WIDTH_LIANA;
        donkey_jr->sprite = LIANA_L0;
        donkey_jr->current_texture = donkey_jr->liana_left0;
    }
}


/**
 * Switches to left side of the liana
 * @param donkey_jr_ptr: struct player **
 */
void l_side_liana(struct player ** donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if(!donkey_jr->right){
        donkey_jr->right = true;
        donkey_jr->pos.x -= WIDTH_LIANA;
        donkey_jr->sprite = LIANA_R0;
        donkey_jr->current_texture = donkey_jr->liana_right0;
    }
}

/**
 * Begins jumping routine
 * @param donkey_jr_ptr: struct player **
 */
void jump(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if (!donkey_jr->jump && !donkey_jr->fall){
        donkey_jr->y_jump = donkey_jr->pos.y;
        donkey_jr->jump = true;
        donkey_jr->liana = false;
        donkey_jr->pos.y -= JUMP;
        if (donkey_jr->right){
            donkey_jr->sprite = JUMP_R;
            donkey_jr->current_texture = donkey_jr->jump_right;
        }else{
            donkey_jr->sprite = JUMP_L;
            donkey_jr->current_texture = donkey_jr->jump_left;
        }
    }
}
/**
 * Moves Donkey Kong Jr is_up until a certain height given by JUMP_DIFF
 * @param donkey_jr_ptr: struct player **
 */
void jumping(struct player **donkey_jr_ptr){
    struct player * donkey_jr = *donkey_jr_ptr;
    int difference = donkey_jr->y_jump - donkey_jr->pos.y;
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
void falling(struct player **donkey_jr_ptr){
    struct player * donkey_jr = *donkey_jr_ptr;
    int x = donkey_jr->pos.x;
    if(reached_liana(&donkey_jr)){
        if (!donkey_jr->right || (x >= L0_X && x <= (L0_X + WIDTH_LIANA))){
            if (!(x >= L0_X && x <= (L0_X + WIDTH_LIANA))){
                donkey_jr->pos.x += WIDTH_LIANA;
            }
            donkey_jr->right = false;
            donkey_jr->sprite = LIANA_L0;
            donkey_jr->current_texture = donkey_jr->liana_left0;
        }else{
            donkey_jr->right = true;
            donkey_jr->sprite = LIANA_R0;
            donkey_jr->current_texture = donkey_jr->liana_right0;
        }
        donkey_jr->y_jump = donkey_jr->pos.y;
        donkey_jr->fall = false; //stop falling
        donkey_jr->liana = true;
    }else if (on_platform(&donkey_jr)){
        if(donkey_jr->right){
            donkey_jr->sprite = STAND_R0;
            donkey_jr->current_texture = donkey_jr->stand_right;
        }else{
            donkey_jr->sprite = STAND_L0;
            donkey_jr->current_texture = donkey_jr->stand_left;
        }
        donkey_jr->y_jump = donkey_jr->pos.y;
        donkey_jr->liana = false;
        donkey_jr->fall = false; //stop falling
    }else{
        donkey_jr->pos.y += JUMP; //keep falling
    }
}

/**
 * Checks if Donkey Kong Jr has landed in a platform
 * @param donkey_jr_ptr: struct player **
 * @return bool
 */
bool on_platform(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    int x = donkey_jr->pos.x;
    int y = donkey_jr->pos.y;
    if ( x >= P0_X0 && x <= P0_X1 && y == P0_Y) {
        return true;
    }else if ( x >= P1_X0 && x <= P1_X1 && y == P1_Y) {
        return true;
    }else if ( x >= P2_X0 && x <= P2_X1 && y == P2_Y) {
        return true;
    }else if ( x >= P3_X0 && x <= P3_X1 && y == P3_Y) {
        return true;
    }else if ( x >= P4_X0 && x <= P4_X1 && y == P4_Y) {
        return true;
    }else if ( x >= P5_X0 && x <= P5_X1 && y == P5_Y) {
        return true;
    }else if ( x >= P6_X0 && x <= P6_X1 && y == P6_Y) {
        return true;
    }else if ( x >= P7_X0 && x <= P7_X1 && y == P7_Y) {
        return true;
    }else if ( x >= P8_X0 && x <= P8_X1 && y == P8_Y) {
        return true;
    }else if ( x >= P9_X0 && x <= P9_X1 && y == P9_Y) {
        return true;
    }else if ( x >= P10_X0 && x <= P10_X1 && y == P10_Y) {
        return true;
    }
    return false;

}

/**
 * Checks if Donkey Kong Jr has reached a liana
 * @param donkey_jr_ptr: struct player **
 * @return bool
 */
 bool reached_liana(struct player **donkey_jr_ptr){
     struct player *donkey_jr = *donkey_jr_ptr;
     int x = donkey_jr->pos.x;
     int y = donkey_jr->pos.y;
     if (y >= L0_Y0 && y <= L0_Y1 && x >= L0_X && x<= (L0_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L0_X ;
         return true;
     } else if(y >= L1_Y0 && y <= L1_Y1 && x >= L1_X && x<= (L1_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L1_X ;
         return true;
     }else if(y >= L2_Y0 && y <= L2_Y1 && x >= L2_X && x<= (L2_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L2_X ;
         return true;
     }else if(y >= L3_Y0 && y <= L3_Y1 && x >= L3_X && x<= (L3_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L3_X ;
         return true;
     }else if(y >= L4_Y0 && y <= L4_Y1 && x >= L4_X && x<= (L4_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L4_X ;
         return true;
     }else if(y >= L5_Y0 && y <= L5_Y1 && x >= L5_X && x<= (L5_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L5_X ;
         return true;
     }else if(y >= L6_Y0 && y <= L6_Y1 && x >= L6_X && x<= (L6_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L6_X ;
         return true;
     }else if(y >= L7_Y0 && y <= L7_Y1 && x >= L7_X && x<= (L7_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L7_X ;
         return true;
     }else if(y >= L8_Y0 && y <= L8_Y1 && x >= L8_X && x<= (L8_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L8_X ;
         return true;
     }else if(y >= L9_Y0 && y <= L9_Y1 && x >= L9_X && x<= (L9_X + WIDTH_LIANA)){
         donkey_jr->pos.x = L9_X ;
         return true;
     }else if(y >= L10_Y0 && y <= L10_Y1 && x >= L10_X && x<= (L10_X + WIDTH_LIANA)) {
         donkey_jr->pos.x = L10_X ;
         return true;
     }
     return false;
 }

 /**
  * Checks if Donkey Kong Jr has reached the top of the liana
  * @param donkey_jr_ptr: struct player **
  * @return bool
  */
 bool top_liana(int x, int y){
     y = y - MOV;
     if (y < L0_Y0 && y && x >= L0_X && x<= (L0_X + WIDTH_LIANA)){
         return true;
     }else if (y < L1_Y0 && y && x >= L1_X && x<= (L1_X + WIDTH_LIANA)){
         return true;
     }else if (y < L2_Y0 && y && x >= L2_X && x<= (L2_X + WIDTH_LIANA)){
         return true;
     }else if (y < L3_Y0 && y > L10_Y1 && y && x >= L3_X && x<= (L3_X + WIDTH_LIANA)){
         return true;
     }else if (y < L4_Y0 && y && x >= L4_X && x<= (L4_X + WIDTH_LIANA)){
         return true;
     }else if (y < L5_Y0 && y > L9_Y1 && y && x >= L5_X && x<= (L5_X + WIDTH_LIANA)){
         return true;
     }else if (y < L6_Y0 && y && x >= L6_X && x<= (L6_X + WIDTH_LIANA)){
         return true;
     }else if (y < L7_Y0 && y && x >= L7_X && x<= (L7_X + WIDTH_LIANA)){
         return true;
     }else if (y < L8_Y0 && y && x >= L8_X && x<= (L8_X + WIDTH_LIANA)){
         return true;
     }else if (y < L9_Y0 && y && x >= L9_X && x<= (L9_X + WIDTH_LIANA)){
         return true;
     }else if (y < L10_Y0 && y && x >= L10_X && x<= (L10_X + WIDTH_LIANA)) {
         return true;
     }
     return false;
 }

/**
 * Checks if Donkey Kong Jr has reached the end of the liana
 * @param donkey_jr_ptr: struct player **
 * @return bool
 */
 bool fall_liana(int x, int y){
     if (y > L0_Y1 && y && x >= L0_X && x<= (L0_X + WIDTH_LIANA)){
         return true;
     }else if (y > L1_Y1 && y && x >= L1_X && x<= (L1_X + WIDTH_LIANA)){
         return true;
     }else if (y > L2_Y1 && y && x >= L2_X && x<= (L2_X + WIDTH_LIANA)){
         return true;
     }else if (y > L3_Y1 && y && x >= L3_X && x<= (L3_X + WIDTH_LIANA)){
         return true;
     }else if (y > L4_Y1 && y && x >= L4_X && x<= (L4_X + WIDTH_LIANA)){
         return true;
     }else if (y > L5_Y1 && y && x >= L5_X && x<= (L5_X + WIDTH_LIANA)){
         return true;
     }else if (y > L6_Y1 && y && x >= L6_X && x<= (L6_X + WIDTH_LIANA)){
         return true;
     }else if (y > L7_Y1 && y && x >= L7_X && x<= (L7_X + WIDTH_LIANA)){
         return true;
     }else if (y > L8_Y1 && y && x >= L8_X && x<= (L8_X + WIDTH_LIANA)){
         return true;
     }else if (y > L9_Y1 && y < L5_Y0 && y && x >= L9_X && x<= (L9_X + WIDTH_LIANA)){
         return true;
     }else if (y > L10_Y1 && y < L3_Y0 && y && x >= L10_X && x<= (L10_X + WIDTH_LIANA)) {
         return true;
     }
     return false;
 }

 /**
  * Controls jumping and falling Donkey Kong Jr's movements in game loop
  * @param donkey_jr_ptr
  */
void control_dk_movement(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if(donkey_jr->jump) jumping(&donkey_jr);
    else if (donkey_jr->fall) falling(&donkey_jr);
}

/**
 * Checks if Donkey Kong Jr felt to the water or collided with a crocodile
 * @param donkey_jr_ptr
 * @return
 */
bool death(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    if(donkey_jr->pos.y >= WIN_HEIGHT){
        return true;
    }
    return false;
}

/**
 * Free resources of player struct (including graphics)
 */
void free_player(struct player **donkey_jr_ptr){
    struct player *donkey_jr = *donkey_jr_ptr;
    SDL_DestroyTexture(donkey_jr->current_texture);
    SDL_DestroyTexture(donkey_jr->run_right1);
    SDL_DestroyTexture(donkey_jr->run_right0);
    SDL_DestroyTexture(donkey_jr->run_left0);
    SDL_DestroyTexture(donkey_jr->run_left1);
    SDL_DestroyTexture(donkey_jr->stand_right);
    SDL_DestroyTexture(donkey_jr->stand_left);
    SDL_DestroyTexture(donkey_jr->jump_right);
    SDL_DestroyTexture(donkey_jr->jump_left);
    SDL_DestroyTexture(donkey_jr->liana_right0);
    SDL_DestroyTexture(donkey_jr->liana_right1);
    SDL_DestroyTexture(donkey_jr->liana_left0);
    SDL_DestroyTexture(donkey_jr->liana_left1);
    free(donkey_jr);
}
