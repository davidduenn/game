#include <iostream>

using namespace std;

/*
 * Declare an array of pointers to structs.
 * Create a struct for the 0th element to point to.
 * Set 'foo' in the struct.
 * output 'foo'.
 */

// Declarations---------------------------------------
struct hldrS {
  int foo;
  double bar;
};

// main()-------------------------------------
int main() {
  hldrS* arr[10];

  arr[0] = new hldrS;

  arr[0]->foo = 10;

  cout << arr[0]->foo << endl;
}

