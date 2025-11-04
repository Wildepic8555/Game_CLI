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
int sizemax;
//sets player char
int playerCharASCIIValue;
//Sets line char in ascii
int lineChar;
//PlayerX
int x1;

//Size for mask gen and example
int size2;

//Inits the frame gen variables
void init(int sizemaxlocal , int playerCharASCIIValueLocal , char lineCharASCIIValueLocal , int objectXLocal) {
    sizemax = sizemaxlocal;
    playerCharASCIIValue = playerCharASCIIValueLocal;
    lineChar = lineCharASCIIValueLocal;
    size2 = sizemax -2;
    frameGen(objectXLocal);
}
//Generates the two lines top and bottom
void lineGen() {
    int j = 1;
    while (j < (sizemax +1)) {
        putchar(lineChar);
        j++;
    }
}
//Generates void from first # to player
void leftMasker(int l) {
    int i = 1;
    while (i <= l) {
        putchar(32);
        i++;
    }
}
//Generates void from player to last #
void rightMasker(int r) {
    int ii = 1;
    while (ii <= r) {
        putchar(32);
        ii++;
    }
}

//Generates frame with position of player
//int x is player location x
void frameGen(int x) {
    //Option to not change player x if new x is 0
    if (x != 0) {
        x1 = x;
    }
    //Calculates were Player is and were the last # is
    int rightMask = size2 -x1;
    int leftMask = x1 -1;
    //Generates the top line
    lineGen();
    //New line and first #
    printf("\n");
    putchar(lineChar);
    //Move player from first #
    leftMasker(leftMask);
    //Places player char
    putchar(playerCharASCIIValue);
    //Generates void between player and last #
    rightMasker(rightMask);
    //Spawns last #
    putchar(lineChar);
    //Whitout bottom line to high
    printf("\n");
    //Generates bottom line
    lineGen();
    //DONT DELETE whitout this bottom line works incorrect
    printf("\n");
}