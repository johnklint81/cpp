#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector<float> func(const int *x, const int *y, int n) {
    // Using vectors here to learn how they work.
    vector<float> z(n);
    for (int i = 0; i < n; i++) {
        z[i] = 5 * x[i] * x[i] + sin(x[i]) + cosh(y[i]);
    }
    return z;
}

int main(int argc, char *argv[]) {
    int x[] = {0, 1, 2, 3, 4, 5};
    int y[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(x) / sizeof(x[0]);
    // Vectors are supposedly more modern and better than arrays?
    vector<float> z = func(x, y, n);
    // Print a neatly formatted header
    cout << setw(5) << "i" << setw(10) << "x" << setw(10) << "y" << setw(15)
        << "z" << endl;
    cout << string(40, '-') << endl;
    // Print arrays with with iomanip. setw() sets the minimum width of the 
    // output. Values are right-aligned by default. Fixed is used to set
    // precision for floating point numbers, without it only 
    for (int i = 0; i < n; i++) {
        cout << setw(5) << i;
        cout << setw(10) << x[i];
        cout << setw(10) << y[i];
        cout << setw(15) << fixed << setprecision(3) << z[i];
        cout << endl;
    }
}
