#include <iostream>
#include "units.h"
#include "map.h"

using namespace std;


// Name
void unitC::setName(string new_name) {
	this->name = new_name;
}

string unitC::getName() {
	return this->name;
}


// Health
void unitC::setHealth(int set) {
	this->health = set;
}

void unitC::incHealth(int inc) {
	this->health += inc;
}

void unitC::decHealth(int dec) {
	this->health -= dec;
}

int unitC::getHealth() {
	return this->health;
}

bool unitC::isDead() {
	return (this->health <= 0);
}


// Location
bool unitC::setLocation(int x, int y, mapC map_inst) {
  int x_temp = x;
  int y_temp = y;
  if(!map_inst.occupied(x_temp, y_temp)) {
    this->loc.x_loc = x_temp;
    this->loc.y_loc = y_temp;
    return 1;
  }
  return 0;
}


// Speed
void unitC::setSpeed(int new_speed) {
	this->speed = new_speed;
}

int unitC::getSpeed() {
	return (this->speed * this->getHealth() / 100);
}


// Print
void unitC::printUnit() {
	cout << "unit: " << this->name << " ------------\n";
  cout << "location: " << this->loc.x_loc << " " << this->loc.y_loc << endl;
	cout << "Nominal Speed: " << this->speed << endl;
	cout << "Real Speed: " << getSpeed() << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Dead: " << this->isDead() << endl;
	cout << "----------------\n";
}


// Unit constructor
unitC::unitC() {
  setHealth(100);
  setName("default unit");
  setSpeed(0);
}

// Minigun constructor
mini::mini() {
  setName("mini-gunner");
	setSpeed(10);
}

// Grenader constructor
gren::gren() {
  setName("grenader");
	setSpeed(12);
}

// Tank constructor
tank::tank() {
  setName("tank");
	setSpeed(20);
}

