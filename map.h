#ifndef __MAP_H__
#define __MAP_H__

using namespace std;

class mapC {
  public:
    mapC();
    bool occupied(int, int);
    int bordered_by(int, int);

  private:
    bool taken[10][10];
};

#endif

