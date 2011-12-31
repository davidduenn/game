#ifndef __MAP_H__
#define __MAP_H__

using namespace std;

/*
So here's the idea:
  You were having trouble making pointers to structs previuosly.
  There is a test program under ./workspace/struct-example.cpp (or somesuch) which has a pointer to a struct
  Look at that program.
  The map can be a 2D array of pointers to units or somesuch!
  */

enum unitE {
  empty,
  tank,
  mini,
  gren
};

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
    int bordered_by(int, int);

    int move(int, int, unit_ptrC);
    void place_on_map(int, int, unit_ptrC);

    void print_map();

  private:
    unit_ptrC board[10][10];

    bool cell_is_free(int, int);
    void find_and_remove(unit_ptrC);
};

#endif

