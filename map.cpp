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
      output << a.board[x][y].getArmy() << "\t";
    }
    output << endl;
  }

  return output;
}

mapC::mapC() {
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      this->board[i][j] = new unitC;
      // Or should this point to null and
      // get pointed to a unit if there is one?
    }
  }
}

// This doesn't do what it seems it should do.
unitC mapC::occupied(int x, int y) {
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
      if(this->board[x][y] == unit2move) {
        this->board[x][y] = NULL;
      }
    }
  }
}

int mapC::move(int x, int y, unitC unit2move) {
  if(occupied(x,y) != NULL) {
    place_on_map(x, y, unit2move);
    find_and_remove(unit2move);
  }
}

void mapC::place_on_map(int x, int y, unitC* unit2move) {
  this->board[x][y] = unit2move;
}

int mapC::getArmy(int x, int y) {
  return this->board[x][y].army;
}

unitE mapC::getType(int x, int y) {
  return this->board[x][y].type;
}

int mapC::getId(int x, int y) {
  return this->board[x][y].id;
}

void mapC::setArmy(int x, int y, int army) {
  this->board[x][y].army = army;
}

void mapC::setType(int x, int y, unitE type) {
  this->board[x][y].type = type;
}

void mapC::setId(int x, int y, int id) {
  this->board[x][y].id = id;
}

