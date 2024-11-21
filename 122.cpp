#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int number = stoi(argv[1]);
    int iter = number / 2;
    for (int i = 1; i <= iter; i++) {
        if (number % i == 0) {
            cout << number / i << " ";
        }
    }
    cout << endl;
    return 0;
}
