#include <iostream>
#include <string>

using namespace std;

int main(int arg, char *argv[]) {
    int number = stoi(argv[1]);
    int digits = 0;

    if (number == 0) {
        cout << "The number has 1 digit(s)." << endl;
    }
    else {
        while (number != 0) {
            number /= 10;
            digits++;
        }
        cout << "The number has " << digits << " digit(s)." << endl;
    }
}
