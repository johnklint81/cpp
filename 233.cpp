#include <iostream>
#include <vector>

using namespace std;

// Pass matrix by reference for "speed" (algorithm is O(n!) so maybe not the
// most important factor)
float det(vector<vector<float>> &matrix) {

    int size = matrix.size();
    float determinant = 0;
    
    // Base cases
    if (size == 1) {
        return matrix[0][0];
    }

    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    
    // Loop over each column and expand the determinant using Laplace expansion
    for (int col = 0; col < size; ++col) {
        // Create the minor matrix by excluding the current row and current
        // column
        vector<vector<float>> minor;

        // Loop over the rows, exclude the first row since we always start
        // at col 0
        for (int row = 1; row < size; ++row) {
            // Container to store the current row of the current matrix minor
            vector<float> row_minor;
            for (int rm = 0; rm < size; ++rm) {
                // Exclude the current column (col)
                if (rm != col) {
                    row_minor.push_back(matrix[row][rm]);
                }
            }
            // Once row_minor is full, append it to the minor matrix
            minor.push_back(row_minor);
        }
        // Determine the sign for the current element
        float polarity;
        if (col % 2 == 0) {
            polarity = 1;
        }
        else {
            polarity = -1;
        }
        // The element at the first row and current column
        float element = matrix[0][col];

        // Recursively compute the determinant of the minor and accumulate the
        // result
        determinant += polarity * element * det(minor);
    } 
    return determinant;
}

int main() {
    // Determinant is = 1*(-2)*3 - 1*1*3 = -6 -3 = -9
    vector<vector<float>> matrix1 = {
        {1, 1, 0},
        {1, -2, 5},
        {0, 0, 3}
    };
    cout << "The determinant is: " << det(matrix1) << endl;
    // Determinant is = 1*(-2) - 1*1 = -3
    vector<vector<float>> matrix2 = {
        {1, 1},
        {1, -2}
    };    
    cout << "The determinant is: " << det(matrix2) << endl;
        // Determinant is = 1*(-2)*3 - 1*1*3 = -6 -3 = -9
    vector<vector<float>> matrix3 = {{99}};
    
    cout << "The determinant is: " << det(matrix3) << endl; // Output the determinant

    return 0;
}

