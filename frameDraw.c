#include <stdio.h>
#include "frameDraw.h"

//Variables Framegen
int sizeOfLines;
int lineChar;
int sizeX;
int size2;
int lineID =1;

//Player
int player[4];
//Objects
int Object1Frame[4];
int Object2Frame[4];

//Inits the frame gen variables
void init(int sizeOfLinesLocal , int playerCharASCIIValueLocal , char lineCharASCIIValueLocal , int playerXLocal , int playerYLocal , int sizeYlocal , int Object1Local[4] , int Object2Local[4]) {
    //Object 1
    Object1Frame[1] = Object1Local[1];
    Object1Frame[2] = Object1Local[2];
    Object1Frame[3] = Object1Local[3];
    //Object2
    Object2Frame[1] = Object2Local[1];
    Object2Frame[2] = Object2Local[2];
    Object2Frame[3] = Object2Local[3];

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
        //This func is for Object 1 to spawn him
       if (Object1Frame[1] == i && Object1Frame[2] == lineID) {
            putchar(Object1Frame[3]);
       }

        else if (Object2Frame[1] == i && Object2Frame[2] == lineID) {
            putchar(Object2Frame[3]);
        }

       else {
            putchar(32);
       }i++;
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
        if (Object1Frame[1] == i && Object1Frame[2] == lineTrackLeft) {
            putchar(Object1Frame[3]);
        }

        else if (Object2Frame[1] == i && Object2Frame[2] == lineTrackLeft) {
            putchar(Object2Frame[3]);
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
        if (Object1Frame[1] == helper && Object1Frame[2] == lineTrackRight) {
            putchar(Object1Frame[3]);
        }

        else if (Object2Frame[1] == helper && lineTrackRight == Object2Frame[2]) {
            putchar(Object2Frame[3]);
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
    int leftMask =player[1] -1;
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

    //Tracks on which line are we
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
}