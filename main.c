#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "frameDraw.h"
#include "getKey.h"

//set size of lines
int realsize = 10;
//Player position
int playerX = 1;

//Move 1 time from left to right , right to left
int main(void) {
    //Init size for anim controller
    int size = realsize - 2;
    //Init frame gen
    init(realsize, 87, 35 , playerX);

    while (true) {
        if (97 == getKey()) {
            if (playerX >1) {
                playerX--;
            }
            system("clear");
            frameGen(playerX);
        }

        if (100 == getKey()) {
            if (playerX  < (size)) {
                playerX++;
            }
            system("clear");
            frameGen(playerX);
        }

    }


    return 0;
}