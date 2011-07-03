#include <iostream>
#include "units.h"
#include "map.h"

using namespace std;


int main() {
  mapC map_inst;

	mini mini_inst_1;
	gren gren_inst_1;
	tank tank_inst_1;

  mini_inst_1.setLocation(9, 9, map_inst);
  gren_inst_1.setLocation(8, 9, map_inst);
  tank_inst_1.setLocation(9, 8, map_inst);

  cout << "constructed\n";
	mini_inst_1.printUnit();
	gren_inst_1.printUnit();
	tank_inst_1.printUnit();

  cout << "dec gren health\n";
	gren_inst_1.decHealth(50);
	gren_inst_1.printUnit();

  cout << "dec gren health\n";
	gren_inst_1.decHealth(10);
	gren_inst_1.printUnit();

  cout << "dec gren health\n";
	gren_inst_1.decHealth(50);
	gren_inst_1.printUnit();

	return 0;
}	

