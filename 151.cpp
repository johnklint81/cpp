#include <iostream>
#include <string>

using namespace std;

float geometric(int elem, const float ratio, int n) {
    // If n = 1 we just return the element.
    if (n == 1) {
        return elem;
    }
    // Otherwise we compute the element recursively, the function continues
    // calling itself and decreasing n with each step until n = 1. It then
    // returns 1, the results are then successively multiplied by the ratio
    // "unwinding" the recursion until the final value is returned.
    else {
        elem = ratio * geometric(elem, ratio, n - 1);
        return elem;
    }
}


int main(int argc, char *argv[]) {
    int elem = stoi(argv[1]);
    float ratio = stof(argv[2]);
    const int n = stof(argv[3]);
    float result = geometric(elem, ratio, n);
    cout << "The element is " << result << endl;
}
