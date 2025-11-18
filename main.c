#include <unistd.h>

#include "frameManager.h"
#include "getKey.h"

int main(void) {
    setSize(15, 5);
    setPlayerLocation(5 ,2);
    setPlayerDesign('P');
    setLineDesign('#');
    setObject1(10 ,1 ,'1');
    setObject2(10 ,2 ,'2');
    frameUpdate();
}