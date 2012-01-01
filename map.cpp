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
/*
 * Is this needed? Why would I need to know if two
 * unit are the same?
bool mapC::operator==(unitC other_unit) {
  // TODO: Use references instead to avoid copying?
  if(this->army == other_unit.army) {
    if(this->type == other_unit.type) {
      if(this->id == other_unit.id) {
        return 1;
      }
    }
  }
  return 0;
}
*/

/*
 * Really need to copy units over eachother?
void mapC::operator=(unitC other_unit) {
  this->army = other_unit.army;
  this->type = other_unit.type;
  this->id = other_unit.id;
}
*/



ostream& operator<<(ostream& output, const overloadC& a) {
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      output << a->board[i][j].getArmy() << "\t";
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
  return map[x][y];
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
  // Perhaps let the armies remember where the units are
  // so that they can tell the map where their unts are
  // and there won't be any searching?
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      if(this->board[i][j] == unit2move) {
        this->board[i][j] = NULL;
      }
    }
  }
}

int mapC::move(int x, int y, unitC unit2move) {
  if(!occupied(x,y)) {
    place_on_map(x, y, unit2move);
    find_and_remove(unit2move);
  }
}

void mapC::place_on_map(int x, int y, unitC* unit2move) {
    this->board[x][y] = unit2move;
}

int mapC::getArmy(int x, int y) {
  return this->board[x][y]->army;
}

void mapC::setArmy(int x, int y, int army) {
  this->board[x][y]->army = army;
}

void mapC::setType(int x, int y, unitE type) {
  this->board[x][y]->type = type;
}

void mapC::setId(int x, int y, int id) {
  this->board[x][y]->id = id;
}

