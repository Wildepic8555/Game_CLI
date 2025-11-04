#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//set size of lines
int realsize = 50;
//sets player char
int playerCharASCIIValue = 87;
//Sets line char in ascii
int lineChar = 35;

//Size for mask gen and example
int size;
//Generates line
void lineGen() {
    int j = 1;
    while (j < (realsize +1)) {
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
void frameGen(int x) {
    //Calculates were Player is and were the last # is
    int rightMask = size -x;
    int leftMask = x -1;
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

//Move 1 time from left to right , right to left
int main(void) {
    //Init size for masks and example movement
    size = realsize - 2;
    int i = 1;
    while (i < (size + 1)) {
        frameGen(i);
        i++;
        sleep(1);
        system("clear");   
    }
    int ii = size;
    while (ii > 0) {
        frameGen(ii);
        ii--;
        sleep(1);
        system("clear");
    }

    return 0;
}