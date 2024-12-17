#include <iostream>
#include <cmath>

using namespace std;

class Point {

private:
    float x;
    float y;
    float z;

public:
    // Default constructor
    Point() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    // Parametrised constructor. Assign class member x value x from constructor
    Point(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Print method
    int Print() {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
        return 0;
    }
    // Radius method
    float Radius() {
        float radius = sqrt(x * x + y * y + z * z);
        return radius;
    }
    // PrintSpherical method
    int PrintSpherical() {
        float r = Radius();
        float theta = acos(z / r);
        float phi = atan2(y, x);
        cout << "r = " << r << ", theta = " << theta << ", phi = "
             << phi << endl;
        return 0;
    }
};


int main() {
    Point point(1.0, 2.0, 3.0);
    point.Print();
    point.Radius();
    point.PrintSpherical();

    return 0;

}
