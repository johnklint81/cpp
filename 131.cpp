#include <iostream>
#include <string>
#include <stack>

using namespace std;


stack<int> getBinary(int number) {
    // We store on a stack because this method gives us the binary digits in
    // reversed order (least significant to most significant). We then print
    // by popping from the stack.
    stack<int> binary;

    // Base case
    if (number == 0) {
        binary.push(0);
        return binary;
    }

    // Divide by 2, the remainder is the constant in front of that binary 
    // position. It is either 0 or 1. Push to stack.
    while (number != 0) {
        int remainder = number % 2;
        binary.push(remainder);
        number /= 2;
    }
    return binary;
}


int main(int argc, char *argv[]) {
    int number = stoi(argv[1]);
    int remainder;
    stack<int> binary = getBinary(number);

    while (!binary.empty()) {
        // Unfortunately pop() does not return item like in Python
        cout << binary.top();
        binary.pop();
    }
    cout << endl;
}
