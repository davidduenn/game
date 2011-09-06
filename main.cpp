#include <iostream>
#include "army.h"
#include "map.h"
#include "units.h"

using namespace std;

int main() {
  mapC map_inst;

	miniC mini_inst_1;
	grenC gren_inst_1;
	tankC tank_inst_1;

  mini_inst_1.setLocation(9, 9, map_inst);
  gren_inst_1.setLocation(8, 9, map_inst);
  tank_inst_1.setLocation(9, 8, map_inst);

	mini_inst_1.printUnit();
	gren_inst_1.printUnit();
	tank_inst_1.printUnit();

	gren_inst_1.incHealth(50);
	gren_inst_1.printUnit();

	gren_inst_1.decHealth(10);
	gren_inst_1.printUnit();

	gren_inst_1.decHealth(100);
	gren_inst_1.printUnit();

	return 0;
}	

