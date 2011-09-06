#include "map.h"

using namespace std;

/*
 *  army = 0: empty
 *  army = 1: nature
 *  army = 2: army 1
 *  army = 3: army 2
 *  ...
 */

mapC::mapC() {
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      this->board[i][j].army = 0;
      this->board[i][j].type = empty;
      this->board[i][j].id = -1;
    }
  }
}

unit mapC::occupied(int x, int y) {
  return this->board[x][y];
}

int mapC::bordered_by(int, int/*, army*/) {
  // Returns:
  // 0 if nothing borders
  // 1 if friendly or rock borders
  // 2 if enemy borders
  if(0) {
    return 2;
  } else if(0) {
    return 1;
  } else {
    return 0;
  }
}

