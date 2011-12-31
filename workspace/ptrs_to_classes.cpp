#include <iostream>

using namespace std;


// Declarations ---------------------------
class shapeC {
  public:
    int number;
};

class circleC: public shapeC {
  public:
    int number2;
    int number3;
    circleC();
};


// Definitions ---------------------------
circleC::circleC() {
  number = 10;
}

// main() -------------------------------------
int main() {
  shapeC* shapeP;
  shapeP = new circleC;

  shapeP->number = 10;
  shapeP->number2 = 30;
  shapeP->number3 = 40;

  cout << shapeP->number << endl;
  cout << shapeP->number2 << endl;
  cout << shapeP->number3 << endl;
}

