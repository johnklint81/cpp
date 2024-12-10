#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#define PI 3.14159

using namespace std;
// FIX THIS
float bisection(float a, float b, const float accuracy) {
    float testValue;
    int iter = 0;
    int maxIter = 10000;
    float midpoint;
    // Test function can be done like this too!
    auto testFunctionLambda = sinf;
    // [] is a capture list, it specifies how the lambda function can access
    // variables from the surrounding scope. Lambdas can carry a state.
    function<float(float)> testFunction = [](float x) {
        return -sin(x);
    };
    // If one of the endpoints is a root.
    if (testFunction(a) == 0.0) {
        return a;
    }
    if (testFunction(b) == 0.0) {
        return b;
    }
    // Interval halving method.
    while (iter < maxIter) {
        // Compute midpoint.
        midpoint = (b + a) / 2;
        // Compute a function value for the midpoint.
        testValue = testFunction(midpoint);
        // Check if the function value at the left endpoint and the function
        // value of the midpoint has different signs. Then we can safely set
        // the right end point to midpoint and retain the root inside the 
        // interval.
        if (testFunction(a) * testValue < 0) {
            b = midpoint;
        }
        // Otherwise we set the left endpoint to midpoint.
        else {
            a = midpoint;
        }
        // Check if we found the true root or are within the require accuracy.
        if (abs(testValue) == 0.0 || abs(b - a) < accuracy) {
            return midpoint;
        }
        iter++;
    }
    cout << "No solution found in " << to_string(maxIter) << " iterations.";
    return NAN;
}

int main(int argc, char *argv[]) {
    float a = stof(argv[1]);
    float b = stof(argv[2]);
    float accuracy = stof(argv[3]);
    float result = bisection(a, b, accuracy);
    if (!isnan(result)) {
        cout << "A root is " << result << endl;
    }
    else {
        cout << "NaN value encountered." << endl;
    }
}
