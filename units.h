#ifndef __UNITS_H__
#define __UNITS_H__

using namespace std;

#include <string>
#include "map.h"

class unitC {
	public:
    unitC();
		void setHealth(int);
		void incHealth(int);
		void decHealth(int);
		int  getHealth();
		bool isDead();

		void setName(string);
		string getName();

		void setSpeed(int);
		int  getSpeed();

		void printUnit();

	private:
		string name;
		int health;
		int speed;
		int firepower;
};


class miniC: public unitC {
	public:
		miniC();
};


class grenC: public unitC {
	public:
		grenC();
};


class tankC: public unitC {
	public:
		tankC();
};


#endif

