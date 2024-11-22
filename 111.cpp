#include <iostream>
#include <string>

// Fel, det ska printas varannan karaktär
using namespace std;

int main(int argc, char *argv[]) {
    // First argument is rows, second cols
    int rows = stoi(argv[1]);
    int cols = stoi(argv[2]);
    // Keep track of whether current row should start with a dot or asterisk
    bool beginsWithDot = true;
    for (int ir = 0; ir < rows; ir++) {
        for (int ic = 0; ic < cols; ic++) {
            if (beginsWithDot) {
                if (ic % 2 == 0) {
                    cout << ".";
                }
                else {
                    cout << "*";
                }
            }
            else {
                if (ic % 2 == 0) {
                    cout << "*";
                }
                else {
                    cout << ".";
                }
            }
        }
        beginsWithDot = !beginsWithDot;
        cout << endl;
    }
}
