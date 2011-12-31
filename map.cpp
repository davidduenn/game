#include <iostream>
#include "map.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

using namespace std;

/*
 *  army = 0: empty
 *  army = 1: nature
 *  army = 2: army 1
 *  army = 3: army 2
 *  ...
 */


//// For unit_ptrC class ////
// Should this be in it's own cpp file? 
unit_ptrC::unit_ptrC() {
  army = 0;
  type = empty;
  id = -1;
}

bool unit_ptrC::operator==(unit_ptrC other_unit) {
  // Use references instead to avoid copying?
  if(this->army == other_unit.army) {
    if(this->type == other_unit.type) {
      if(this->id == other_unit.id) {
        return 1;
      }
    }
  }
  return 0;
}

void unit_ptrC::operator=(unit_ptrC other_unit) {
  this->army = other_unit.army;
  this->type = other_unit.type;
  this->id = other_unit.id;
}

void unit_ptrC::setArmy(int army) {
  this->army = army;
}

void unit_ptrC::setType(unitE type) {
  this->type = type;
}

void unit_ptrC::setId(int id) {
  this->id = id;
}


int unit_ptrC::getArmy() {
  // Use references instead to avoid copying?
  return this->army;
}


//// For mapC class ////

mapC::mapC() {
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      unit_ptrC new_unit_ptr;
      this->board[i][j] = new_unit_ptr;
    }
  }
}

// This doesn't do what it seems it should do.
// Also see cell_is_free() below
unit_ptrC mapC::occupied(int x, int y) {
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

bool mapC::cell_is_free(int x, int y) {
  if(board[x][y].getArmy() == 0) {
    return 1;
  }
  return 0;
}

void mapC::find_and_remove(unit_ptrC unit2move) {
  // COULD TAKE A LONG TIME FOR BIG MAPS!!!
  // TODO: optimize
  // Perhaps let the armies remember where the units are
  // so that they can tell the map where their unts are
  // and there won't be any searching?
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      if(this->board[i][j] == unit2move) {
        unit_ptrC empty_unit;
        this->board[i][j] = empty_unit;
      }
    }
  }
}

int mapC::move(int x, int y, unit_ptrC unit2move) {
  if(cell_is_free(x,y)) {
    find_and_remove(unit2move);
    place_on_map(x, y, unit2move);
  }
}

void mapC::place_on_map(int x, int y, unit_ptrC unit2move) {
    this->board[x][y] = unit2move;
}

void mapC::print_map() {
  for(int i=0; i<MAP_WIDTH; i++) {
    for(int j=0; j<MAP_HEIGHT; j++) {
      cout << this->board[i][j].getArmy() << "\t";
    }
    cout << endl;
  }
}

