//
// Created by wildepic on 11/4/25.
//
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#include "getKey.h"


//AI Generated
int getKey() {
    struct termios oldt, newt;

    // alte Terminal-Einstellungen sichern
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Terminal auf raw mode setzen
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char c;
    c = getchar();  // wartet nicht auf Enter

    // Terminal-Einstellungen wiederherstellen
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}
