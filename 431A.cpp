#include <iostream>

using namespace std;

class Base {

public:
    // The call order is Base class constructor, then Derived class constructor,
    // because the Derived class depends on the Base class in its construction.
    Base() {
        cout << "Base class constructor is called" << endl;
    };
};

// Inherits from Base class
class Derived : public Base {

public:
    Derived() {
        cout << "Derived class constructor is called" << endl;
    };
};

int main() {
    Derived obj;
    return 0;
}
