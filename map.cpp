#include "map.h"

using namespace std;

mapC::mapC() {
  for(int i=0; i<10; i++) {
    for(int j=0; j<10; j++) {
      this->taken[i][j] = 0;
    }
  }
  this->taken[0][0] = 1;
  this->taken[1][1] = 1;
  this->taken[2][2] = 1;
  this->taken[3][3] = 1;
}

bool mapC::occupied(int x, int y) {
  return this->taken[x][y];
}

