#include <unistd.h>

#include "frameManager.h"
#include "getKey.h"

int main(void) {
    setSize(5, 5);
    setPlayerLocation(1 ,1);
    setPlayerDesign('P');
    setLineDesign('#');
    setObject1(4 ,1 ,'1');
    frameUpdate();
}