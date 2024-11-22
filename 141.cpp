#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float trapezoidInt(const float a, const float b, const float p = 0.001) {
    /*
    Idea: Partition the interval (b - a) into n subintervals, then compute 
    a trapezoid for each subinterval. Sum these up and as the length of the
    subintervals tends to 0, the sum approaches the value of the integral.
    */
    int n = 1;
    float intervalSize = b - a;
    float stepSize = intervalSize / n;
    float currentPoint;
    // test function is exp, handle edge cases which are divided by 2.
    float newIntegral;
    float previousIntegral = 0.0;

    while (true) {
        // Compute the endpoint contributions.
        float integral = 0.5 * (exp(a) + exp(b));
        // Update the stepsize
        stepSize = intervalSize / n;
        // Compute the current position in the partition and then the value
        // of the function at that position.
        for (int i = 1; i < n; i++) {
            currentPoint = a + i * stepSize;
            integral += exp(currentPoint);
        }
        // Scales the integral by stepSize since this is left out above.
        newIntegral = integral * stepSize;
        // Determine if newIntegral has reached the convergence criteria,
        // if so, we are done.
        if (abs(newIntegral - previousIntegral) < p) {
            return newIntegral;
        }
        // If not, we update the value of the previousIntegral.
        previousIntegral = newIntegral;
        // Refine the number of intervals in our partition.
        n += 1;
    }
    return newIntegral;
}

int main(int argc, char *argv[]) {
    // [a,b] are integration limits, p is precision
    float a = stof(argv[1]);
    float b = stof(argv[2]);
    // Check if precision is user specified or initialise as default value
    float p = (argc == 4) ? stof(argv[3]) : 0.001;
    float integral = trapezoidInt(a, b, p);
    cout << "The numerical value of the integral is: " << integral << endl;
}
