#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

stack<char> getRadixNumber(int number, int radix) {
    stack<char> result;
    string digits = "0123456789ABCDEF";
    // Guard, now I know how to throw errors.
    if (radix < 2 || radix > 16) {
        throw runtime_error("Radix should be between 2 and 16!");
    }
    if (number == 0) {
        result.push(0);
        return result;
    }
    // Same as before, except now we divide by radix instead of 2.
    // The remainder is the constant we want to put in front of that position
    // in the new number. We map this to the string with digits to accomodate
    // for the extra characters used for bases larger than 10.
    while (number != 0) {
        int remainder = number % radix;
        char newDigit = digits[remainder];
        result.push(newDigit);
        number /= radix;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int number = stoi(argv[1]);
    int radix = stoi(argv[2]);
    // Here we use a different type for the stack since we use letters as bases
    // for bases larger than 10.
    stack<char> newNumber = getRadixNumber(number, radix);
    // Print the number
    while (!newNumber.empty()) {
        // Unfortunately pop() does not return item like in Python
        cout << newNumber.top();
        newNumber.pop();
    }
    cout << endl;

}
