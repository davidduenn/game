#include <iostream>
#include "army.h"
#include "map.h"
#include "units.h"

using namespace std;

//TODO: overload << operator instead of using print() functs.

int main() {
  // Construct units
	miniC mini_inst_1;
	grenC gren_inst_1;
	tankC tank_inst_1;

  // Print units
	mini_inst_1.printUnit();
	gren_inst_1.printUnit();
	tank_inst_1.printUnit();

  // Construct Map
  mapC map_inst;


  // TODO: Need a way to easily convert
  // between real units and map_units!!!
  

  // Create special map_units for map
  unit_ptrC mini_ptr_1;
  unit_ptrC gren_ptr_1;
  unit_ptrC tank_ptr_1;

  mini_ptr_1.setArmy(2);
  gren_ptr_1.setArmy(3);
  tank_ptr_1.setArmy(2);

  mini_ptr_1.setType(mini);
  gren_ptr_1.setType(gren);
  tank_ptr_1.setType(tank);

  mini_ptr_1.setId(28);
  gren_ptr_1.setId(30);
  tank_ptr_1.setId(22);

  // Populate map with map_units
  map_inst.place_on_map(1, 2, mini_ptr_1);
  map_inst.place_on_map(2, 2, gren_ptr_1);
  map_inst.place_on_map(6, 2, tank_ptr_1);

  // Print Map
  map_inst.print_map();

  // Effect
	gren_inst_1.incHealth(50);
	gren_inst_1.printUnit();

	gren_inst_1.decHealth(10);
	gren_inst_1.printUnit();

	gren_inst_1.decHealth(100);
	gren_inst_1.printUnit();

	return 0;
}	

