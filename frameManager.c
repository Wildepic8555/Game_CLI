//
// Created by wildepic on 11/17/25.
//
#include <stdlib.h>
#include "frameManager.h"
#include <stdio.h>
#include <unistd.h>

#include "frameDraw.h"
#include "scoreboard_draw.h"

int fieldSize[3];
int playerLoc[3];
int object1[4];
int object2[4];
int playerDesign;
int lineDesign;

bool scoreboardused = false;
int scoreBoardScore = 0;
int scoreBoardScore1 = 0;

bool object1Used = false;
bool object2Used = false;

//This all is a Layer for better commands
void setSize(int x , int y) {
    fieldSize[1] = x;
    fieldSize[2] = y;

}

void setPlayerLocation(int x, int y) {
    playerLoc[1] = x;
    playerLoc[2] = y;
}

void setPlayerDesign(char Design) {
    playerDesign = Design;
}

void setLineDesign(char Design) {
    lineDesign = Design;
}

void setObject1(int x , int y , char Design) {
    object1[1] = x;
    object1[2] = y;
    object1[3] = Design;
    object1Used = true;
}
void setObject2(int x , int y , char Design) {
    object2[1] = x;
    object2[2] = y;
    object2[3] = Design;
    object2Used = true;
}

void scoreBoard(int score , int score2) {
    scoreboardused = true;
    scoreBoardScore = score;
    scoreBoardScore1 = score2;

}

void frameUpdate() {
    //60 fps
    usleep(1000000 / 60);
    system("clear");
    //If scoreboard isnt set or objects arent set they arent showed
    if (object1Used == false) {
        object1[3] = 32;
    }
    if (object2Used == false) {
        object2[3] = 32;
    }

    if (scoreboardused) {
        scoreBoardManager(scoreBoardScore ,scoreBoardScore1 , fieldSize[1] , lineDesign);
    }

    init(fieldSize[1] , playerDesign, lineDesign , playerLoc[1] , playerLoc[2],fieldSize[2] , object1 ,object2);

}

