#include <iostream>

using namespace std;

/*
 * Extend the shapeC class in cricleC
 */

// Declarations ---------------------------
class shapeC {
  public:
    int number;
};

class circleC: public shapeC {
  public:
    int number2;
    circleC();
};


// Definitions ---------------------------
circleC::circleC() {
  number = 10;
}

// main() -------------------------------------
int main() {
  // if shapeP is declared pointer to circleC
  //  number2 can be accessed
  // if shapeP is declared pointer to shapeC
  //  number 2 can not be accessed
  //
  // Oddly enough though, the shapeC pointer can point
  // to either one and it compiles (just can't use number2)
  circleC* shapeP;
  shapeP = new circleC;

  shapeP->number = 10;
  shapeP->number2 = 30;

  cout << shapeP->number << endl;
  cout << shapeP->number2 << endl;

  return 0;
}

