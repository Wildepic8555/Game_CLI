#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "frameDraw.h"
#include "getKey.h"

//set size of lines
int realsizeX = 5;
int realsizeY = 5;
//Player position
int playerX = 1;
int playerY = 5;

//Move 1 time from left to right , right to left
int main(void) {
    //Init frame gen
    init(realsizeX , 87, 49 , playerX , playerY,realsizeY);

    while (true) {
        if (97 == getKey()) {
            if (playerX >1) {
                playerX--;
            }
            system("clear");
            frameGen(playerX , playerY);
        }

        if (100 == getKey()) {
            if (playerX  < (realsizeX)) {
                playerX++;
            }
            system("clear");
            frameGen(playerX , playerY);
        }
        if (119 == getKey()) {
            if (playerY >1) {
                playerY--;
            }
            system("clear");
            frameGen(playerX , playerY);
        }
        if (115 == getKey()) {
            if (playerY < realsizeX) {
                playerY++;
            }
            system("clear");
            frameGen(playerX , playerY);
        }

    }


    return 0;
}