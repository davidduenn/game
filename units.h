#ifndef __UNITS_H__
#define __UNITS_H__

#include "map.h"

using namespace std;

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


class mini: public unitC {
	public:
		mini();
};


class gren: public unitC {
	public:
		gren();
};


class tank: public unitC {
	public:
		tank();
};


#endif

