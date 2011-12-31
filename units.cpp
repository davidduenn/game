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
    this->health = 0;
  }
}

int unitC::getHealth() {
	return this->health;
}

bool unitC::isDead() {
	return (this->health <= 0);
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

