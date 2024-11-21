#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {
    int number = stoi(argv[1]);
    int remainder;
    // We store on a stack because this method gives us the binary digits in
    // reversed order (least significant to most significant). We then print
    // by popping from the stack.
    stack<int> binaries;
    // Base case
    if (number == 0) {
        cout << "0" << endl;
        return 0;
    }
    // Divide by 2, the remainder is the constant in front of that binary 
    // position. It is either 0 or 1. Push to stack.
    while (number != 0) {
        remainder = number % 2;
        number /= 2;
        binaries.push(remainder);
    }
    while (!binaries.empty()) {
        // Unfortunately pop() does not return item like in Python
        cout << binaries.top();
        binaries.pop();
    }
    cout << endl;
}
