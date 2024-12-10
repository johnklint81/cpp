#include <iostream>

using namespace std;

void printMatrix(int* matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Print flattened array
            cout << matrix[i * size + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size = 5;
    // Does not work to use size here, because size needs to be known at
    // compile time. VLAs like matrix[][] are not standard,
    // use vector<> instead.
    int matrix[5][5] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
               matrix[i][j] = i*j; 
            }
        }
    }
    // Pass stack address of matrix 
    printMatrix(&matrix[0][0], size);
    return 0;
}
