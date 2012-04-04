#include <iostream>
/*
 * two classes: fooC and barC
 *  barC is a regular class
 *  fooC has barC as a public member
 * Declare a foo.
 * Use a function in foo normally.
 * Set a bar var using a bar function through foo.
 * Get a bar var using a bar function through foo.
 */

using namespace std;


// Declarations-----------------------------
class barC {
	public:
		int get_Num();
		void set_Num(int);
	private:
		int num;
};

class fooC {
	public:
		barC bar_inst;
		void printNothing();
};


// Definitions--------------------------------
int barC::get_Num() {
	return num;
}

void barC::set_Num(int a) {
	this->num = a;
}

void fooC::printNothing() {
	cout << "nothing\n";
}


// main()------------------------------------
int main() {
	fooC foo_inst;
	foo_inst.printNothing();
	foo_inst.bar_inst.set_Num(23);
	cout << foo_inst.bar_inst.get_Num() << endl;

	return 0;
}

