#include <iostream>
#include "units.h"
#include "map.h"

using namespace std;


// print unit
ostream& operator<<(ostream& output, unitC& a) {
	output << "unit: " << a.name << " ------------\n";
	output << "Nominal Speed: " << a.speed << endl;
	output << "Real Speed: " << a.getSpeed() << endl;
	output << "Health: " << a.getHealth() << endl;
	output << "Dead: " << a.isDead() << endl;
	output << "----------------\n";
  return output;
}

// Name
// Probably not needed except for debugging
void unitC::setName(string new_name) {
	this->name = new_name;
}

string unitC::getName() {
	return this->name;
}


// Health
void unitC::setHealth(int set) {
  if(set > 100) {
    this->health = 100;
  } else if(set < 0) {
    this->health = 0;
  } else {
    this->health = set;
  }
}

void unitC::incHealth(int inc) {
  cout << "health incrementing\n";
	this->health += inc;
  if(this->health > 100) {
    this->health = 100;
  }
}

void unitC::decHealth(int dec) {
  cout << "health decrementing\n";
	this->health -= dec;
  if(this->health < 0) {
    delete this;
  }
}

int unitC::getHealth() {
	return this->health;
}

bool unitC::isDead() {
  // Is this needed?
  // If a unit is dead shouldn't it disappear?
	return (this->health <= 0);
}


// Speed
void unitC::setSpeed(int new_speed) {
	this->speed = new_speed;
}

int unitC::getSpeed() {
	return (this->speed * this->getHealth() / 100);
}

bool unitC::operator==(unitC other_unit) {
  // TODO: Use references instead to avoid copying?
  if(this->id == other_unit.id) {
    return 1;
  }
  return 0;
}

void unitC::operator=(unitC other_unit) {
  this->army = other_unit.army;
  this->type = other_unit.type;
  this->id = other_unit.id;
}


// Unit constructor
unitC::unitC() {
  setHealth(100);
  setName("default unit");
  setSpeed(0);
}

// Minigun constructor
miniC::miniC() {
  cout << "Constructing Mini+++\n";
  setName("mini-gunner");
	setSpeed(10);
}

// Grenader constructor
grenC::grenC() {
  cout << "Constructing Gren+++\n";
  setName("grenader");
	setSpeed(12);
}

// Tank constructor
tankC::tankC() {
  cout << "Constructing Tank+++\n";
  setName("tank");
	setSpeed(20);
}

