#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // First argument is rows, second cols
    int rows = stoi(argv[1]);
    int cols = stoi(argv[2]);
    // Keep track of whether row/col should be indented
    bool star_indent = true;
    bool dot_indent = false;
    for (int ir = 0; ir < rows; ir++) {
        // Do the indentation
        if (ir % 2 == 0) {
            if (star_indent) {
                cout << " ";
            }
            star_indent = !star_indent;
        }
        else {
            if (dot_indent) {
                cout << " ";
            }
            dot_indent = !dot_indent;
        }
        // Print the symbols
        for (int ic = 0; ic < cols; ic++) {
            if (ir % 2 == 0) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}
