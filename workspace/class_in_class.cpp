#include <iostream>
/*
 * This main() creates a fooC which has
 * barC as a public member. The barC of
 * fooC is then used.
 */

using namespace std;


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
	private:
		int baz;
};


int barC::get_Num() {
	return num;
}

void barC::set_Num(int a) {
	this->num = a;
}

void fooC::printNothing() {
	cout << "nothing\n";
}


int main() {
	fooC foo_inst;
	foo_inst.printNothing();
	foo_inst.bar_inst.set_Num(23);
	cout << foo_inst.bar_inst.get_Num() << endl;

	return 0;
}

