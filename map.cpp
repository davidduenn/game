#include <iostream>
#include "map.h"

  // Use references instead to avoid copying?

using namespace std;

/*
 *  army = 0: empty
 *  army = 1: nature
 *  army = 2: army 1
 *  army = 3: army 2
 *  ...
 */


//// For mapC class ////
ostream& operator<<(ostream& output, mapC a) {
  for(int x=0; x<MAP_WIDTH; x++) {
    for(int y=0; y<MAP_HEIGHT; y++) {
      if(a.occupied(x, y)) {
        output << a.board[x][y]->getArmy() << "\t";
      } else {
        output << 0 << "\t";
      }
    }
    output << endl;
  }

  return output;
}

mapC::mapC() {
  for(int x=0; x<MAP_WIDTH; x++) {
    for(int y=0; y<MAP_HEIGHT; y++) {
      this->board[x][y] = NULL;
    }
  }
}

unitC* mapC::occupied(int x, int y) {
  // If(exists) {returns pointer to unit}
  // if(!exists) {returns pointer to NULL}
  return this->board[x][y];
}

/*
int mapC::bordered_by(int, int, army) {
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
*/

void mapC::find_and_remove(unitC unit2move) {
  // COULD TAKE A LONG TIME FOR BIG MAPS!!!
  // TODO: optimize
  // Perhaps let the units remember their coordinates?
  for(int x=0; x<MAP_WIDTH; x++) {
    for(int y=0; y<MAP_HEIGHT; y++) {
      if(this->board[x][y] == &unit2move) {
        this->board[x][y] = NULL;
      }
    }
  }
}

int mapC::move(int x, int y, unitC* unit2move) {
  if(occupied(x,y) != NULL) {
    place_on_map(x, y, unit2move);
    find_and_remove(*unit2move);
  }
}

void mapC::place_on_map(int x, int y, unitC* unit2move) {
  this->board[x][y] = unit2move;
}

