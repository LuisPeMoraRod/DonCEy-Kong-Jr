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
#define P0_X0 2
#define P0_X1 115
#define P0_Y 572

#define P1_X0 65
#define P1_X1 180
#define P1_Y 390

#define P2_X0 65
#define P2_X1 140
#define P2_Y 268

#define P3_X0 180
#define P3_X1 260
#define P3_Y 532

#define P4_X0 285
#define P4_X1 340
#define P4_Y 552

#define P5_X0 365
#define P5_X1 440
#define P5_Y 532

#define P6_X0 467
#define P6_X1 520
#define P6_Y 512

#define P7_X0 430
#define P7_X1 520
#define P7_Y 329

#define P8_X0 300
#define P8_X1 360
#define P8_Y 167

#define P9_X0 5
#define P9_X1 320
#define P9_Y 147

#define P10_X0 115
#define P10_X1 180
#define P10_Y 68

#endif //CLIENT_CONSTANTS_H
