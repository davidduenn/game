#ifndef __MAP_H__
#define __MAP_H__

// Everything is x,y or width,height

using namespace std;

#include "units.h"

/*
  Pointers to structs example:
  There is a test program under ./workspace/struct-example.cpp (or somesuch) which has a pointer to a struct
  The map can be a 2D array of pointers to units or somesuch!

  I think the problem is, though, that I have one main struct for units with the units deriving from it.
  I'm not modifying the struct but I'm not able to declare a general pointer to all the structs (even though
    they're the same type.
  Perhaps I should just have the main struct type and have different functions to set the struct parameters
    to those of a tank, inf, gren...
*/

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

class mapC {
  // A 2-D array of custom pointers to units

  friend ostream& operator<<(ostream&, mapC);

  public:
    mapC();
    unitC occupied(int, int);
    /*
     * Why is this needed?
    int bordered_by(int, int);
    */

    int move(int, int, unitC);
    void place_on_map(int, int, unitC*);


  private:
    unitC* board[MAP_WIDTH][MAP_HEIGHT];

    void find_and_remove(unitC&);
};

#endif

