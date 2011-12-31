#include <iostream>

using namespace std;


// Declare Class
class overloadC {
  friend ostream& operator<<(ostream& output, const overloadC& a);

  public:
    int number;

    bool operator<(overloadC);
};


// Overload < operator in class
bool overloadC::operator<(overloadC a) {
  cout << "in place"<< endl;
  return 1;
}

// Overload << operator in class
ostream& operator<<(ostream& output, const overloadC& a) {
  output << a.number;
  return output;
}

  
// Use overloaded < operator
int main() {
  overloadC class1;
  overloadC class2;

  cout << "5<1:\t" << (5<1) << endl;
  cout << "5<1:\t" << (class1 < class2) << endl;

  class1.number = 12;
  cout << class1 << endl;
}

