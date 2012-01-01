#include <iostream>
#include "army.h"
#include "map.h"
#include "units.h"

using namespace std;

//TODO: overload << operator instead of using print() functs.

int main() {
  // Construct Map
  mapC map_inst;

  // Construct units
  miniC* mini_ptr_1 = new miniC;
  grenC* gren_ptr_1 = new grenC;
  tankC* tank_ptr_1 = new tankC;

  // Print units
	mini_inst_1->printUnit();
	gren_inst_1->printUnit();
	tank_inst_1->printUnit();

  // Set units' armies
  mini_ptr_1->setArmy(2);
  gren_ptr_1->setArmy(3);
  tank_ptr_1->setArmy(2);

  // Set units' types
  mini_ptr_1->setType(mini);
  gren_ptr_1->setType(gren);
  tank_ptr_1->setType(tank);

  // Set units' IDs
  mini_ptr_1->setId(28);
  gren_ptr_1->setId(30);
  tank_ptr_1->setId(22);

  // Populate map with map_units
  map_inst.place_on_map(1, 2, mini_ptr_1);
  map_inst.place_on_map(2, 2, gren_ptr_1);
  map_inst.place_on_map(6, 2, tank_ptr_1);
  /*
   * shouldn't touch *_ptr_1 from here on.
   * everything should be done through map?
   */

  // Print Map
  cout << map_inst << endl;

  // Effect
	gren_inst_1->incHealth(50);
	gren_inst_1->printUnit();

	gren_inst_1->decHealth(10);
	gren_inst_1->printUnit();

	gren_inst_1->decHealth(100);
	gren_inst_1->printUnit();

  delete miniC;
  delete grenC;
  delete tankC;

	return 0;
}	

