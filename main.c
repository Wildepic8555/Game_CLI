#include <unistd.h>

#include "frameManager.h"
#include "getKey.h"

int main(void) {
    int i = 0;
    while (1) {
        i++;
        setSize(15, 5);
        setPlayerLocation(9 ,2);
        setPlayerDesign('P');
        setLineDesign('#');
        setObject1(10 ,2 ,'1');
        setObject2(10 ,3 ,'2');
        scoreBoard(0, 0);
        frameUpdate();


    }
    return 5;
}