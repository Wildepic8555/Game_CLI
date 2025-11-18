//
// Created by wildepic on 11/17/25.
//
#include <stdlib.h>
#include "frameManager.h"
#include "frameDraw.h"

int fieldSize[3];
int playerLoc[3];
int object1[4];
int object2[4];
int playerDesign;
int lineDesign;

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
}
void setObject2(int x , int y , char Design) {
    object2[1] = x;
    object2[2] = y;
    object2[3] = Design;
}

void frameUpdate() {
    system("clear");
    init(fieldSize[1] , playerDesign, lineDesign , playerLoc[1] , playerLoc[2],fieldSize[2] , object1 ,object2);
}