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
#define BPP 16 //bits per pixel
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

//initial positons
#define DK_X0 2;
#define DK_Y0 572;

//movement distances
#define JUMP 1
#define MOV 8
#define JUMP_DIFF 45

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
    STAND_L1
};

//Donkey Kong Jr size
#define DKJR_WIDTH 50
#define DKJR_HEIGHT 34

#define DELAY 10

//platforms
enum platforms{
    P0_X0 = 2,
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
    L0_X = 0,
    L0_Y0 = 200,
    LO_Y1 = 545,

    L1_X = 35,
    L1_Y0 = 200,
    L1_Y1 = 526,

    L2_X = 95,
    L2_Y0 = 320,
    L2_Y1 = 455,

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

#endif //CLIENT_CONSTANTS_H
