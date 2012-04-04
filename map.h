#ifndef __MAP_H__
#define __MAP_H__

// Everything is x,y or width,height

using namespace std;

#include "units.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

class mapC {
  // A 2-D array of custom pointers to units

  friend ostream& operator<<(ostream&, mapC);

  public:
    mapC();
    unitC* occupied(int, int);
    /*
     * Why is this needed?
    int bordered_by(int, int);
    */

    int move(int, int, unitC*);
    void place_on_map(int, int, unitC*);

  private:
    unitC* board[MAP_WIDTH][MAP_HEIGHT];

    void find_and_remove(unitC*);
};

#endif

