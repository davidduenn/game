#ifndef __MAP_H__
#define __MAP_H__

using namespace std;

//#include "units.h"

// Should be in units.h
enum unitE {
  empty,
  tank,
  mini,
  gren
};

struct unit {
  int army;
  unitE type;
  int id;
};

class mapC {
  public:
    mapC();
    unit occupied(int, int);
    int bordered_by(int, int);

  private:
    unit board[10][10];
};

#endif

