//
// Created by wildepic on 11/4/25.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "frameDraw.h"

//set size of lines
int sizeNormalX;
//sets player char
int playerCharASCIIValue;
//Sets line char in ascii
int lineChar;
//PlayerX
int x1;
//PlayerY
int y1;

//Size for mask gen and example
int sizeX;
//Size y mask gen
int sizeY;

//Test Object
int testX = 2;
int testY = 3;

//Inits the frame gen variables
void init(int sizemaxlocal , int playerCharASCIIValueLocal , char lineCharASCIIValueLocal , int objectXLocal , int objectYLocal , int sizeYlocal) {
    sizeNormalX = sizemaxlocal + 2;
    playerCharASCIIValue = playerCharASCIIValueLocal;
    lineChar = lineCharASCIIValueLocal;
    sizeX = sizeNormalX -2;
    sizeY = sizeYlocal;
    frameGen(objectXLocal , objectYLocal);
}
//Generates lines were players is not
void voidLineGen(int v) {
    putchar(lineChar);
    int i = 1;
    while (i <= v) {
        //Work in Progress
       /* if (testX == i) {
            putchar(55);
        }
        else {
            putchar(32);
        } */
        putchar(32);
        i++;
    }
    putchar(lineChar);
}
//Generates the two lines top and bottom
void lineGen() {
    int j = 1;
    while (j < (sizeNormalX +1)) {
        putchar(lineChar);
        j++;
    }
}
//Generates void from first # to player
void leftMasker(int l, int lineTrackLeft) {
    int i = 1;
    while (i <= l) {
        //Puts in on the right place the object if its before the player
        if (testX == i && testY == lineTrackLeft) {
            putchar(55);
        }
        else {
            putchar(32);
        }
        i++;
    }
}
//Generates void from player to last #
void rightMasker(int r , int lineTrackRight) {
    int ii = 1;
    while (ii <= r) {
        int helper = ii +x1;
        //Puts in on the right place the object if its after the player
        if (testX == helper && testY == lineTrackRight) {
            putchar(55);
        }
        else {
            putchar(32);
        }
        ii++;
    }
}
//Manages lines before and after player
int voidLineManager(int v , int mask) {
    int i = 1;
    while (i <= mask) {
        i++;
        printf("\n");
        voidLineGen(v );
    }
    return i;
}

//Generates frame with position of player
//int x is player location x
void frameGen(int x , int y) {
    x1 = x;
    //Calculates were Player is and were the last # is
    int rightMask = sizeX -x1;
    int leftMask = x1 -1;
    int downMask = sizeY - y;
    int upMask = y -1;
    //Tracks on which line is the player
    int lineTracker;

    //Generates the top line
    lineGen();
    //Makes lines before player after top line
    lineTracker =voidLineManager(sizeX , upMask) ;

    //New line and first #
    printf("\n");
    putchar(lineChar);

    //Move player from first #
    leftMasker(leftMask , lineTracker);

    //Places player char
    putchar(playerCharASCIIValue);

    //Generates void between player and last #
    rightMasker(rightMask, lineTracker);

    //Spawns last #
    putchar(lineChar);
    //Makes lines after Player and before last line
    voidLineManager(sizeX , downMask);

    //Whitout bottom line to high
    printf("\n");

    //Generates bottom line
    lineGen();

    //DONT DELETE whitout this bottom line works incorrect
    printf("\n");
}