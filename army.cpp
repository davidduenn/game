#include "army.h"
#include "units.h"

using namespace std;

/*
 * Here's the idea:
 * The armies are just going to be storage units.
 * Right now I can declare tank1 and gren1 etc. and deal with them explicitly
 * I can't always do that. I need a way to hold them.
 * The armies are just holders
 * In each army there will be one linked list for each unit type
 * The army's units will be in it's linked lists
 */

void armyC::add_mini(miniC *my_inst) {
  mini_ptr_hldr ptr_inst;

  ptr_inst.miniC_ptr = my_inst;
  ptr_inst.id = my_inst->getId();

  this->mini_list.push_back(ptr_inst);
}

/* Make templated
void armyC::add_gren() {
  this->gren_list.push_back();
}

void armyC::add_tank() {
  this->tank_list.push_back();
}
*/


void armyC::del_mini(int id) {
  this->mini_list.pop_back();
}

/* Make templated
void armyC::del_gren() {
  this->gren_list.pop_back();
}

void armyC::del_tank() {
  this->tank_list.pop_back();
}
*/

