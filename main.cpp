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
  miniC* mini_inst_1 = new miniC;
  grenC* gren_inst_1 = new grenC;
  tankC* tank_inst_1 = new tankC;
  grenC* Regina = new grenC;

  // Print units
  /*
  cout <<	*mini_inst_1 << endl;
  cout <<	*gren_inst_1 << endl;
  cout <<	*tank_inst_1 << endl;
  */

  // Place units on map
  map_inst.place_on_map(1, 2, mini_inst_1);
  map_inst.place_on_map(2, 2, gren_inst_1);
  map_inst.place_on_map(6, 2, tank_inst_1);
  map_inst.place_on_map(7, 3, Regina);

  // Set units' armies
  mini_inst_1->setArmy(2);
  gren_inst_1->setArmy(3);
  tank_inst_1->setArmy(2);
  Regina->setArmy(3);

  // Set units' IDs
  mini_inst_1->setId(7);
  gren_inst_1->setId(8);
  tank_inst_1->setId(9);

  // Print Map
  cout << map_inst << endl;

  // Change Location
  /*
  map_inst.move(8, 7, mini_inst_1);
  cout << map_inst << endl;
  */

  // Change Health
  /*
	gren_inst_1->incHealth(50);
  cout << *gren_inst_1 << endl;

	gren_inst_1->decHealth(10);
  cout << *gren_inst_1 << endl;

	gren_inst_1->decHealth(100);
  cout << *gren_inst_1 << endl;
  */



  delete mini_inst_1;
  delete gren_inst_1;
  delete tank_inst_1;
  delete Regina;

	return 0;
}	

