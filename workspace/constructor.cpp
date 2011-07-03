#include <iostream>
/*
 * The fooC class has a constructor
 */

using namespace std;


class fooC {
	public:
		fooC();
		int get_bar();
		void put_bar(int);
	private:
		int bar;
};


fooC::fooC() {
	bar = 0;
}

int fooC::get_bar() {
  return bar;
}


int main() {
	fooC baz;
  cout << baz.get_bar() << endl;

	return 0;
}

