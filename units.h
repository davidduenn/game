#ifndef __UNITS_H__
#define __UNITS_H__

using namespace std;

#include <string>


enum unitE {
  empty,
  tank,
  mini,
  gren
};


// should the units know their coordinates on the map?
class unitC {
  friend class mapC;

  friend ostream& operator<<(ostream&, unitC&);

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

    bool operator==(unitC);
    void operator=(unitC);

	private:
		string name;
    int id;
		int health;
		int speed;
		int firepower;
    int army;
    unitE type;
    //TODO: bool is_damagable (1 for regular. 0 for nature.)
};


// This whole declaration of sub-units should work...
// That means that I should be able to have a single
// pointer type to point to any of them
// See ./workspace/ptrs_to_classes.cpp
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

