#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<float> quadratic(const float a, const float b, const float c) {
    if (b * b - 4 * a * c < 0) {
        cerr << "Error: The polynomial has complex roots." << endl;
    }
    // Initialise a vector of size 2 and type float, filled with zeros.
    vector<float> result(2, 0.0f);
    result[0] = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    result[1] = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    return result;
}


int main(int argc, char *argv[]) {
    float a = stof(argv[1]);
    float b = stof(argv[2]);
    float c = stof(argv[3]);
    vector<float> result = quadratic(a, b, c);
    string str = "The roots of the polynom ";
    if (string(argv[1]) == "1") {
        str += "x^2 + ";
    }
    else {
        str += string(argv[1]) + "x^2 + ";
    }
    str += string(argv[2]) + "x + " + string(argv[3]) + " are:"; 
    cout << str << endl;
    for (float root : result) {
        cout << root << endl;
    }

}
