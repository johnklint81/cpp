#include <iostream>
#include <string>

using namespace std;

float sinTaylor(float x, int n) {
    float sum = x;
    float term = x;
    // Compute the ratio between two consecutive terms of the Taylor series
    // to get a general expression for the next term with regards to the 
    // previous term. Accumulate in sum for sin(x) approximation.
    for (int i = 1; i <= n; i++) {
        term = -term * (x * x) / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

float cosTaylor(float x, int n) {
    float sum = 1;
    float term = 1;
    // Same as above, divide term n + 1 with term n.
    for (int i = 0; i < n; i++) {
        term = -term * (x * x) / ((2 * i + 2) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    float x = stof(argv[1]);
    int n = stoi(argv[2]);
    float result1 = sinTaylor(x, n);
    float result2 = cosTaylor(x, n);
    cout << "The Taylor approximation of sin(x), x=" << x << " over " <<
        n << " iterations is " << result1 << endl;
        cout << "The Taylor approximation of cos(x), x=" << x << " over " <<
        n << " iterations is " << result2 << endl;
   
}
