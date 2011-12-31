#ifndef __MAP_H__
#define __MAP_H__

using namespace std;

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

enum unitE {
  empty,
  tank,
  mini,
  gren
};

// This creates one of these unit_ptrC classes at each spot on the board
// This shouldn't be so. This class is not needed at each spot.
// Alternatively, there could be the same functions which the map owns.
// If asked, the map could tell what was happening at any of it's spots.
class unit_ptrC {
  // Map uses this to keep track of units
  // Map gives this data to an army to 
  // access the unit
  public:
    unit_ptrC();
    bool operator==(unit_ptrC);
    void operator=(unit_ptrC);

    void setArmy(int);
    void setType(unitE);
    void setId(int);

    int getArmy();

  private:
    int army;
    unitE type;
    int id;
};

class mapC {
  // A 2-D array of custom pointers to units
  public:
    mapC();
    unit_ptrC occupied(int, int);
    /*
     * Why is this needed?
    int bordered_by(int, int);
    */

    int move(int, int, unit_ptrC);
    void place_on_map(int, int, unit_ptrC);

    void print_map();

  private:
    // Is the width/height supposed to be height/width?
    unit_ptrC board[MAP_WIDTH][MAP_HEIGHT];

    bool cell_is_free(int, int);
    void find_and_remove(unit_ptrC);
};

#endif

