#include <iostream>
#include <random>

using namespace std;

int main() {
    int rows = 3;
    int cols = 3;

    // Allocate a contiguous memory block for the entire 2D array
    
    int *data = new int[rows * cols];

    // Allocate an array of pointers to each row
    int **arr = new int*[rows];

    // Initialize the pointers to point to the start of 
    // each row in the contiguous block
    for (int i = 0; i < rows; i++) {
        // Point each row pointer to the correct location in the contiguous block
        arr[i] = &data[i * cols];  
    }

    // Random generator seed
    random_device rand;
    // Mersenne twister engine
    mt19937 gen(rand());
    // tell generator to create uniform numbers between 1 and 100
    uniform_int_distribution<> dist(1, 100);

    // Fill 2D array with random values using generator defined above
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = dist(gen);
        }
    }
    int *pointer = &arr[0][0];
    // Print with pointer arithmetic and incrementing the pointer
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(pointer + j + i * rows) << " ";
        }
        cout << endl;
    }

    // Print all elements by iterating through the array of pointers
    cout << "Printing using array of pointers:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Note that this syntax includes automatically dereferencing
            // the pointer at location j. Could deference manually with:
            // cout << *(arr[i] + j) << " ";
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory, this only works because we have allocated contiguous memory
    // We would have ot iterate otherwise
    delete[] arr;
    delete[] data; 

    return 0;
}

