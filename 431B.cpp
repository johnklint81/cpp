#include <iostream>

using namespace std;

class Base {
// If we make these fields protected, the derived class can access them
protected:
    int field1;
    int field2;

public:
    Base() : field1(5), field2(10) {

    };
};

class Derived : public Base {
public:
    int Product() {
        return field1*field2;
    };
};

int main() {
    // This must be inside main
    Derived obj;
    cout << obj.Product() << endl;
    return 0;
}
