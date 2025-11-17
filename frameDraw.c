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
int sizeOfLines;
//Sets line char in ascii
int lineChar;

int player[4];
int lineID =1;

//Size for mask gen and example
int sizeX;
//Size 2 mask gen
int size2;

//TestObject
int testObject[4];

//Inits the frame gen variables
void init(int sizeOfLinesLocal , int playerCharASCIIValueLocal , char lineCharASCIIValueLocal , int playerXLocal , int playerYLocal , int sizeYlocal) {
    //Test Object
    testObject[1] = 1;
    testObject[2] = 2;
    testObject[3] = 55;

    sizeOfLines = sizeOfLinesLocal + 2;
    player[3] = playerCharASCIIValueLocal;
    lineChar = lineCharASCIIValueLocal;
    sizeX = sizeOfLines -2;
    size2 = sizeYlocal;
    frameGen(playerXLocal , playerYLocal);
}
//Generates lines were players is not
void voidLineGen(int v) {
    putchar(lineChar);
    int i = 1;
    while (i <= v) {
        //Work in Progress
       if (testObject[1] == i && testObject[2] == lineID) {
            putchar(testObject[3]);
        }
        else {
            putchar(32);
        }
        i++;
    }
    putchar(lineChar);
}
//Generates the two lines top and bottom
void lineGen() {
    int j = 1;
    while (j < (sizeOfLines +1)) {
        putchar(lineChar);
        j++;
    }
}
//Generates void from first # to player
void leftMasker(int l, int lineTrackLeft) {
    int i = 1;
    while (i <= l) {
        //Puts in on the right place the object if its before the player
        if (testObject[1] == i && testObject[2] == lineTrackLeft) {
            putchar(testObject[3]);
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
        int helper = ii +player[1];
        //Puts in on the right place the object if its after the player
        if (testObject[1] == helper && testObject[2] == lineTrackRight) {
            putchar(testObject[3]);
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
        lineID++;
        printf("\n");
        voidLineGen(v);
    }
    return i;
}

//Generates frame with position of player
//int x is player location x
void frameGen(int x , int y) {
    lineID = 0;
    player[1] = x;
    //Calculates were Player is and were the last # is
    int rightMask = sizeX -player[1];
    int leftMask = player[1] -1;
    int downMask = size2 - y;
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

    lineID++;

    //Move player from first #
    leftMasker(leftMask , lineTracker);

    //Places player char
    putchar(player[3]);

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