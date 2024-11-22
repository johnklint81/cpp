#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    // Compute factorial recursively
    if (n == 0 || n == 1) {
        return result;
    }
    return n * factorial(n - 1);
}

long int combination(int n, int k) {
    // Compute combinations with factorial function
    long int c = factorial(n) / (factorial(k) * factorial(n - k));
    return c;
}


int main(int argc, char *argv[]) {
    int rows = stoi(argv[1]);
    // Set maximal width of each element in the triangle
    int width = 6;
    // Loop through rows
    for (int row = 0; row < rows; row++) {
        // Set the left side padding of the triangle: maximal rows - current
        // row index times the cell width divided by two for each side, but 
        // only used on the left side.
        cout << string((rows - row) * width / 2, ' ');
        for (int col = 0; col <= row; col++) {
            // Same amount of elements in the columns as the row index.
            cout << setw(width) << combination(row, col);
        }
        cout << endl;
    }
    return 0;
}
