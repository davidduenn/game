#include <iostream>

using namespace std;


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

