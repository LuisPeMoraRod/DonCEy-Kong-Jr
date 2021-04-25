//
// Created by Luis Pedro Morales on 23/4/21.
//

#include "enemies.h"
/**
 * Creates new enemy (red crocodile). Malloc of new struct with SDL_Textures for rendering
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
        set_position_red(L0_X,L0_Y0, &croc);
    }else if (liana == LIANA1){
        set_position_red(L1_X,L1_Y0, &croc);
    }else if (liana == LIANA2){
        set_position_red(L2_X,L2_Y0, &croc);
    }else if (liana == LIANA3){
        set_position_red(L3_X,L3_Y0, &croc);
    }else if (liana == LIANA4){
        set_position_red(L4_X,L4_Y0, &croc);
    }else if (liana == LIANA5){
        set_position_red(L5_X,L5_Y0, &croc);
    }else if (liana == LIANA6){
        set_position_red(L6_X,L6_Y0, &croc);
    }else if (liana == LIANA7){
        set_position_red(L7_X,L7_Y0, &croc);
    }else if (liana == LIANA8){
        set_position_red(L8_X,L8_Y0, &croc);
    }else if (liana == LIANA9){
        set_position_red(L9_X,L9_Y0, &croc);
    }else if (liana == LIANA10){
        set_position_red(L10_X,L10_Y0, &croc);
    }
    return croc;
}

/**
 * Locates crocodile at the top of given liana
 * @param x: int
 * @param y: int
 * @param red_croc_ptr: struct red_croc **
 * @return struct red_croc*
 */
struct red_croc* set_position_red(int x, int y, struct red_croc ** red_croc_ptr){
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
 * Creates new enemy (blue crocodile). Malloc of new struct with SDL_Textures for rendering
 * @param liana: int
 * @return croc: struct red_croc *
 */
struct blue_croc* create_blue_croc(int liana){
    size_t size = sizeof(struct blue_croc);
    struct blue_croc * croc = malloc(size); //new struct

    const char *blue_croc_path = NULL;
    SDL_Texture *blue_croc_txtr = NULL;

    //set all textures (one for every sprite)
    blue_croc_path = C_BLUE_UP0;
    blue_croc_txtr = load_texture(blue_croc_path);
    croc->up0 = blue_croc_txtr;

    blue_croc_path = C_BLUE_UP1;
    blue_croc_txtr = load_texture(blue_croc_path);
    croc->up1 = blue_croc_txtr;

    blue_croc_path = C_BLUE_DOWN0;
    blue_croc_txtr = load_texture(blue_croc_path);
    croc->down0 = blue_croc_txtr;

    blue_croc_path = C_BLUE_DOWN1;
    blue_croc_txtr = load_texture(blue_croc_path);
    croc->down1 = blue_croc_txtr;

    croc->sprite = BLUE_DOWN0;
    croc->current_texture = croc->down0;
    croc->is_up = false;
    croc->fall = false;

    if (liana == LIANA0){
        set_position_blue(L0_X,L0_Y0, &croc);
    }else if (liana == LIANA1){
        set_position_blue(L1_X,L1_Y0, &croc);
    }else if (liana == LIANA2){
        set_position_blue(L2_X,L2_Y0, &croc);
    }else if (liana == LIANA3){
        set_position_blue(L3_X,L3_Y0, &croc);
    }else if (liana == LIANA4){
        set_position_blue(L4_X,L4_Y0, &croc);
    }else if (liana == LIANA5){
        set_position_blue(L5_X,L5_Y0, &croc);
    }else if (liana == LIANA6){
        set_position_blue(L6_X,L6_Y0, &croc);
    }else if (liana == LIANA7){
        set_position_blue(L7_X,L7_Y0, &croc);
    }else if (liana == LIANA8){
        set_position_blue(L8_X,L8_Y0, &croc);
    }else if (liana == LIANA9){
        set_position_blue(L9_X,L9_Y0, &croc);
    }else if (liana == LIANA10){
        set_position_blue(L10_X,L10_Y0, &croc);
    }
    return croc;
}

/**
 * Locates crocodile at the top of given liana
 * @param x: int
 * @param y: int
 * @param red_croc_ptr: struct red_croc **
 * @return struct red_croc*
 */
struct blue_croc* set_position_blue(int x, int y, struct blue_croc ** blue_croc_ptr){
    struct blue_croc* croc = *blue_croc_ptr;
    if (x == L0_X){
        SDL_Rect pos_rect = {x, y, CROC_WIDTH, CROC_HEIGHT};
        croc->pos = pos_rect;
    } else{
        SDL_Rect pos_rect = {x + CROC_ADJ, y, CROC_WIDTH, CROC_HEIGHT};
        croc->pos = pos_rect;
    }
}
/**
 * Adds new red croc to linked list
 * @param first: struct node **
 * @param last: struct node **
 * @param croc: struct red_croc **
 */
void add_red_croc(struct node ** first, struct node** last, struct red_croc ** croc){
    size_t size = sizeof(struct node);
    struct node * new_node = malloc(size); // create new node

    new_node->red_croc_ptr = *croc;
    new_node->blue_croc_ptr = NULL;
    new_node->next_node = NULL;

    if((*first == NULL) && (*last == NULL)){
        *first = new_node;
        *last = new_node;
    }else{
        struct node * last_temp = *last;
        last_temp->next_node = new_node;
        last_temp = new_node;
        *last = last_temp;
    }
}

/**
 * Adds new blue croc to linked list
 * @param first: struct node **
 * @param last: struct node **
 * @param croc: struct blue_croc **
 */
void add_blue_croc(struct node ** first, struct node** last, struct blue_croc ** croc){
    size_t size = sizeof(struct node);
    struct node * new_node = malloc(size); // create new node

    new_node->red_croc_ptr = NULL;
    new_node->blue_croc_ptr = *croc;
    new_node->next_node = NULL;

    if((*first == NULL) && (*last == NULL)){
        *first = new_node;
        *last = new_node;
    }else{
        struct node * last_temp = *last;
        last_temp->next_node = new_node;
        last_temp = new_node;
        *last = last_temp;
    }
}

void control_crocs_mov(struct node ** first_ptr){
    struct node * first = *first_ptr;
    struct node * temp_ptr = first;
    while(temp_ptr != NULL){
        if(temp_ptr->red_croc_ptr != NULL){
            movement_red_croc(&temp_ptr->red_croc_ptr);
        }
        /*
        if(temp_ptr->blue_croc_ptr != NULL){
            movement_blue_croc(&temp_ptr->blue_croc_ptr);
        }*/
        temp_ptr = temp_ptr->next_node;
    }
}

void movement_red_croc(struct red_croc ** red_croc_ptr){
    struct red_croc * croc = *red_croc_ptr;
    if(top_liana(croc->pos.x - CROC_ADJ, croc->pos.y) || top_liana(croc->pos.x, croc->pos.y)){
        croc->is_up = false;
        croc->sprite = RED_DOWN0;
        croc->current_texture = croc->down0;
    }
    if (fall_liana(croc->pos.x - CROC_ADJ, croc->pos.y) || fall_liana(croc->pos.x, croc->pos.y)) {
        croc->is_up = true;
        croc->sprite = RED_UP0;
        croc->current_texture = croc->up0;
    }
    if(!croc->is_up){
        croc->pos.y += MOV_CROCS;
        if(croc->sprite == RED_DOWN0 && (croc->pos.y%10 == 0)){
            croc->sprite = RED_DOWN1;
            croc->current_texture = croc->down1;
        }else if (croc->sprite == RED_DOWN1 && (croc->pos.y%10 == 0)){
            croc->sprite = RED_DOWN0;
            croc->current_texture = croc->down0;
        }
    }else{
        croc->pos.y -= MOV_CROCS;
        if(croc->sprite == RED_UP0 && (croc->pos.y%10 == 0)){
            croc->sprite = RED_UP1;
            croc->current_texture = croc->up1;
        }else if (croc->sprite == RED_UP1 && (croc->pos.y%10 == 0)){
            croc->sprite = RED_UP0;
            croc->current_texture = croc->up0;
        }
    }
}

/**
 * Renders crocs textures by looping in the linked list
 * @param renderer_ptr: SDL_Rendere **
 * @param first: struct node **
 */
void render_crocs(SDL_Renderer ** renderer_ptr, struct node **first){
    struct node *temp_ptr = *first;

    SDL_Rect * pos = NULL;
    struct red_croc * red = NULL;
    struct blue_croc * blue = NULL;

    while( temp_ptr != NULL){

        if(temp_ptr->red_croc_ptr != NULL){
            red = temp_ptr->red_croc_ptr;
            pos = &red->pos;
            SDL_RenderCopy(*renderer_ptr, red->current_texture, NULL, pos);
        }
        if(temp_ptr->blue_croc_ptr != NULL){
            blue = temp_ptr->blue_croc_ptr;
            pos = &temp_ptr->blue_croc_ptr->pos;
            SDL_RenderCopy(*renderer_ptr, blue->current_texture, NULL, pos);
        }
        temp_ptr = temp_ptr->next_node;
    }

}

/**
 * Free all elements of linked lists
 * @param first: struct node **
 */
void free_croc_list(struct node **first){
    struct node *temp_ptr = *first;
    struct node *temp_ptr2;
    while(temp_ptr != NULL){
        temp_ptr2 = temp_ptr;
        temp_ptr = temp_ptr->next_node;
        if (temp_ptr2->red_croc_ptr != NULL){
            free_red_croc(&temp_ptr2->red_croc_ptr);
        }else if(temp_ptr2->blue_croc_ptr != NULL){
            free_blue_croc(&temp_ptr2->blue_croc_ptr);
        }
        free(temp_ptr2);
    }
}
/**
 * Free resources of a red croc struct
 * @param red_croc_ptr: struc red_croc **
 */
void free_red_croc(struct red_croc** red_croc_ptr){
    struct red_croc* croc = *red_croc_ptr;
    if (croc != NULL){
        SDL_DestroyTexture(croc->current_texture);
        SDL_DestroyTexture(croc->up0);
        SDL_DestroyTexture(croc->up1);
        SDL_DestroyTexture(croc->down0);
        SDL_DestroyTexture(croc->down1);
        free(croc);
    }
}

/**
 * Free resources of a blue croc struct
 * @param blue_croc_ptr: struc red_croc **
 */
void free_blue_croc(struct blue_croc** blue_croc_ptr){
    struct blue_croc* croc = *blue_croc_ptr;
    if (croc != NULL){
        SDL_DestroyTexture(croc->current_texture);
        SDL_DestroyTexture(croc->up0);
        SDL_DestroyTexture(croc->up1);
        SDL_DestroyTexture(croc->down0);
        SDL_DestroyTexture(croc->down1);
        free(croc);
    }
}