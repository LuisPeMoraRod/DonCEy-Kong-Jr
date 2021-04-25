//
// Created by Luis Pedro Morales on 15/4/21.
//

#ifndef CLIENT_CONSTANTS_H
#define CLIENT_CONSTANTS_H

#define IP_ADDRESS "127.0.0.1"
#define PORT 8081
#define MAX_BUFFER 300
#define SA struct sockaddr //socket address

#define WIN_WIDTH 567 //window frame width
#define WIN_HEIGHT 646 //window frame height
#define MAX_PATH 30

//images paths
#define BG_PATH "resources/background.png"
#define DK_RUN_R0 "resources/donkey_jr/run_right0.png"
#define DK_RUN_R1 "resources/donkey_jr/run_right1.png"
#define DK_RUN_L0 "resources/donkey_jr/run_left0.png"
#define DK_RUN_L1 "resources/donkey_jr/run_left1.png"
#define DK_JUMP_R "resources/donkey_jr/jump_right.png"
#define DK_JUMP_L "resources/donkey_jr/jump_left.png"
#define DK_LIANA_R0 "resources/donkey_jr/liana_right0.png"
#define DK_LIANA_R1 "resources/donkey_jr/liana_right1.png"
#define DK_LIANA_L0 "resources/donkey_jr/liana_left0.png"
#define DK_LIANA_L1 "resources/donkey_jr/liana_left1.png"
#define DK_STAND_R "resources/donkey_jr/stand_right.png"
#define DK_STAND_L "resources/donkey_jr/stand_left.png"
#define DK_DEATH "resources/donkey_jr/death0.png"

//crocodiles
#define C_RED_UP0 "resources/enemies/red_croc_up0.png"
#define C_RED_UP1 "resources/enemies/red_croc_up1.png"
#define C_RED_DOWN0 "resources/enemies/red_croc_down0.png"
#define C_RED_DOWN1 "resources/enemies/red_croc_down1.png"
#define C_BLUE_UP0 "resources/enemies/blue_croc_up0.png"
#define C_BLUE_UP1 "resources/enemies/blue_croc_up1.png"
#define C_BLUE_DOWN0 "resources/enemies/blue_croc_down0.png"
#define C_BLUE_DOWN1 "resources/enemies/blue_croc_down1.png"

//statics
#define DK "resources/jail.png"
#define DK_X 10
#define DK_Y 116
#define DK_WIDTH 96
#define DK_HEIGHT 64

#define MARIO "resources/mario.png"
#define M_X 115
#define M_Y 148
#define M_WIDTH 58
#define M_HEIGHT 32

#define KEY "resources/key.png"
#define KEY_X 170
#define KEY_Y 60
#define KEY_WIDTH 34
#define KEY_HEIGHT 36

//fruits
#define APPLE_PATH "resources/apple.png"
#define BANANA_PATH "resources/banana.png"
#define MANGO_PATH "resources/mango.png"

#define FRUIT_WIDTH 28
#define FRUIT_HEIGHT 30

//initial positons
#define DK_X0 2
#define DK_Y0 572

//movement distances
#define JUMP 1
#define MOV 8
#define MOV_CROCS 1
#define JUMP_DIFF 60

//enum for sprites
enum donkey_jr_sprite{
    RUN_R0,
    RUN_R1,
    RUN_L0,
    RUN_L1,
    JUMP_R,
    JUMP_L,
    LIANA_R0,
    LIANA_R1,
    LIANA_L0,
    LIANA_L1,
    STAND_R0,
    STAND_R1,
    STAND_L0,
    STAND_L1,
    DEATH
};

enum crocs_sprite{
    RED_UP0,
    RED_UP1,
    RED_DOWN0,
    RED_DOWN1,
    BLUE_UP0,
    BLUE_UP1,
    BLUE_DOWN0,
    BLUE_DOWN1
};

//Donkey Kong Jr size
#define DKJR_WIDTH 50
#define DKJR_HEIGHT 34
#define CROC_WIDTH 24
#define CROC_HEIGHT 48
#define CROC_ADJ 30 //adjust in x for croc positioning in lianas

#define LIVES 3
#define DELAY 10
#define DELAY_CROCS 10

//platforms
enum platforms{
    P0_X0 = 0,
    P0_X1 = 115,
    P0_Y = 572,

    P1_X0 = 65,
    P1_X1 = 180,
    P1_Y = 390,

    P2_X0 = 65,
    P2_X1 = 140,
    P2_Y = 268,

    P3_X0 = 180,
    P3_X1 = 260,
    P3_Y = 532,

    P4_X0 = 285,
    P4_X1 = 340,
    P4_Y = 552,

    P5_X0 = 365,
    P5_X1 = 440,
    P5_Y = 532,

    P6_X0 = 467,
    P6_X1 = 520,
    P6_Y = 512,

    P7_X0 = 430,
    P7_X1 = 520,
    P7_Y = 329,

    P8_X0 = 300,
    P8_X1 = 452,
    P8_Y = 167,

    P9_X0 = 5,
    P9_X1 = 320,
    P9_Y = 147,

    P10_X0 = 115,
    P10_X1 = 180,
    P10_Y = 68
};

enum lianas{
    LIANA0,
    LIANA1,
    LIANA2,
    LIANA3,
    LIANA4,
    LIANA5,
    LIANA6,
    LIANA7,
    LIANA8,
    LIANA9,
    LIANA10
};
enum lianas_ranges{
    L0_X = 0,
    L0_Y0 = 200,
    L0_Y1 = 545,

    L1_X = 35,
    L1_Y0 = 200,
    L1_Y1 = 526,

    L2_X = 95,
    L2_Y0 = 320,
    L2_Y1 = 545,

    L3_X = 196,
    L3_Y0 = 200,
    L3_Y1 = 480,

    L4_X = 276,
    L4_Y0 = 200,
    L4_Y1 = 355,

    L5_X = 336,
    L5_Y0 = 220,
    L5_Y1 = 480,

    L6_X = 398,
    L6_Y0 = 220,
    L6_Y1 = 440,

    L7_X = 460,
    L7_Y0 = 110,
    L7_Y1 = 480,

    L8_X = 520,
    L8_Y0 = 110,
    L8_Y1 = 480,

    L9_X = 315,
    L9_Y0 = 50,
    L9_Y1 = 95,

    L10_X = 195,
    L10_Y0 = 50,
    L10_Y1 = 95
};

enum fruits{
    FRUIT0,
    FRUIT1,
    FRUIT2,
    FRUIT3,
    FRUIT4,
    FRUIT5,
    FRUIT6,
    FRUIT7,
    FRUIT8,
    FRUIT9,
};
enum fruits_pos{
    F0_X = 200,
    F0_Y = 147,

    F1_X = 420,
    F1_Y = 167,

    F2_X = 120,
    F2_Y = 268,

    F3_X = 160,
    F3_Y = 390,

    F4_X = 450,
    F4_Y = 329,

    F5_X = 95,
    F5_Y = 572,

    F6_X = 220,
    F6_Y = 532,

    F7_X = 312,
    F7_Y = 552,

    F8_X = 402,
    F8_Y = 532,

    F9_X = 493,
    F9_Y = 512
};

enum fruit_type{
    APPLE,
    BANANA,
    MANGO
};

#define WIDTH_LIANA 23

#endif //CLIENT_CONSTANTS_H
