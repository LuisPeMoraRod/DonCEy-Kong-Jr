//
// Created by luispedro on 25/4/21.
//

#include "fruits.h"

struct fruit * create_fruit(struct fruit ** first, struct fruit **last, SDL_Renderer **renderer_ptr, int platform, int fruit_type, int points){
    size_t size = sizeof(struct fruit);
    struct fruit * fruit_ptr = malloc(size);

    const char *path = NULL;
    SDL_Texture *texture = NULL;

    if(fruit_type == APPLE) path = APPLE_PATH;
    else if(fruit_type == BANANA) path = BANANA_PATH;
    else if (fruit_type == MANGO) path = MANGO_PATH;

    texture = load_texture(renderer_ptr, path);
    fruit_ptr->texture = texture;
    fruit_ptr->points = points;
    fruit_ptr->next_node = NULL;
    fruit_ptr->visible = true;
    fruit_ptr->platform = platform;

    if (platform == FRUIT0) set_fruit_pos(F0_X, F0_Y, &fruit_ptr);
    else if (platform == FRUIT1) set_fruit_pos(F1_X, F1_Y, &fruit_ptr);
    else if (platform == FRUIT2) set_fruit_pos(F2_X, F2_Y, &fruit_ptr);
    else if (platform == FRUIT3) set_fruit_pos(F3_X, F3_Y, &fruit_ptr);
    else if (platform == FRUIT4) set_fruit_pos(F4_X, F4_Y, &fruit_ptr);
    else if (platform == FRUIT5) set_fruit_pos(F5_X, F5_Y, &fruit_ptr);
    else if (platform == FRUIT6) set_fruit_pos(F6_X, F6_Y, &fruit_ptr);
    else if (platform == FRUIT7) set_fruit_pos(F7_X, F7_Y, &fruit_ptr);
    else if (platform == FRUIT8) set_fruit_pos(F8_X, F8_Y, &fruit_ptr);
    else if (platform == FRUIT9) set_fruit_pos(F9_X, F9_Y, &fruit_ptr);

    return fruit_ptr;
}

/**
 * Set position of fruit image depending on platform number
 * @param x: int
 * @param y: int
 * @param fruit_ptr: struct fruit **
 */
void set_fruit_pos(int x, int y, struct fruit ** fruit_ptr){
    struct fruit * fruit = *fruit_ptr;
    SDL_Rect pos_rect = {x, y, FRUIT_WIDTH, FRUIT_HEIGHT};
    fruit->pos = pos_rect;
}

void add_fruit(struct fruit **first, struct fruit **last, struct fruit ** new_fruit_ptr){
    struct fruit * new_fruit = *new_fruit_ptr;
    if((*first == NULL) && (*last == NULL)){
        *first = new_fruit;
        *last = new_fruit;
    }else{
        struct fruit * last_temp = *last;
        last_temp->next_node = new_fruit;
        last_temp = new_fruit;
        *last = last_temp;
    }
}

void render_fruits(SDL_Renderer ** renderer_ptr, struct fruit **first){
    struct fruit *temp_ptr = *first;
    SDL_Rect * pos = NULL;
    while( temp_ptr != NULL){
        pos = &temp_ptr->pos;
        SDL_RenderCopy(*renderer_ptr, temp_ptr->texture, NULL, pos);
        temp_ptr = temp_ptr->next_node;
    }
}

void free_fruits_list(struct fruit ** first){
    struct fruit *temp_ptr = *first;
    struct fruit *temp_ptr2;
    while(temp_ptr != NULL){
        temp_ptr2 = temp_ptr;
        temp_ptr = temp_ptr->next_node;
        SDL_DestroyTexture(temp_ptr2->texture);
        free(temp_ptr2);
    }
}