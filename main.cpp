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

  // Print units
  cout <<	mini_inst_1 << endl;
  cout <<	gren_inst_1 << endl;
  cout <<	tank_inst_1 << endl;

  // Place units on map
  map_inst.place_on_map(1, 2, mini_inst_1);
  map_inst.place_on_map(2, 2, gren_inst_1);
  map_inst.place_on_map(6, 2, tank_inst_1);

  // Set units' armies
  map_inst.setArmy(1, 2, 2);
  map_inst.setArmy(2, 2, 3);
  map_inst.setArmy(6, 2, 2);

  // Set units' types
  map_inst.setType(1, 2, mini);
  map_inst.setType(2, 2, gren);
  map_inst.setType(6, 2, tank);

  // Set units' IDs
  map_inst.setId(1, 2, 28);
  map_inst.setId(2, 2, 30);
  map_inst.setId(6, 2, 22);

  // Print Map
  cout << map_inst << endl;

  // Effect
	gren_inst_1->incHealth(50);
	gren_inst_1->printUnit();

	gren_inst_1->decHealth(10);
	gren_inst_1->printUnit();

	gren_inst_1->decHealth(100);
	gren_inst_1->printUnit();

  delete mini_inst_1;
  delete gren_inst_1;
  delete tank_inst_1;

	return 0;
}	

