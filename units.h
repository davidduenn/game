#ifndef __UNITS_H__
#define __UNITS_H__

using namespace std;

#include <string>
#include "map.h"

struct location {
  int x_loc;
  int y_loc;
};

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

    bool setLocation(int, int, mapC);

		void printUnit();
	
	private:
		string name;
		int health;
		int speed;
    struct location loc;
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

