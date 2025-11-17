//
// Created by wildepic on 11/17/25.
//

#include "frameManager.h"

#include <stdlib.h>

#include "frameDraw.h"

int fieldSize[3];
int playerLoc[3];
int playerDesign;
int lineDesign;


void setSize(int x , int y) {
    fieldSize[1] = x;
    fieldSize[2] = y;
}
void setPlayerLocation(int x, int y) {
    playerLoc[1] = x;
    playerLoc[2] = y;
}
void setPlayerDesign(int Design) {
    playerDesign = Design;
}
void setLineDesign(int Design) {
    lineDesign = Design;
}
void frameUpdate() {
    system("clear");
    init(fieldSize[1] , playerDesign, lineDesign , playerLoc[1] , playerLoc[2],fieldSize[2]);
}