#ifndef __ARMY_H__
#define __ARMY_H__

#include <list>
#include "units.h"

struct mini_ptr_hldr {
  miniC *miniC_ptr;
  int id;
};

/*
struct gren_ptr_hldr {
  miniC *grenC_ptr;
  int id;
};

struct tank_ptr_hldr {
  miniC *tankC_ptr;
  int id;
};
*/

class armyC {
  public:
    void add_mini(miniC*);
    /*
    void add_gren();
    void add_tank();
    */

    void del_mini(int);
    /*
    void del_gren();
    void del_tank();
    */

  private:
    list<mini_ptr_hldr> mini_list;
    /*
    list<grenC> gren_list;
    list<tankC> tank_list;
    */
};

#endif
