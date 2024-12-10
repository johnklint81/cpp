#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Function to multiply two matrices and print their product
void matmul(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
    int row1 = matrix1.size();
    int col1 = matrix1[0].size();
    int row2 = matrix2.size();
    int col2 = matrix2[0].size();
    
    // Need to match for matmul operation to be defined
    if (col1 != row2) {
        cout << "Dimensions do not match, aborting." << endl;
        return;
    }

    vector<vector<int>> result(row1, vector<int>(col2, 0));
    
    // Multiply matrice elements 
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Loop through the rows containing vector<int> and print
    for (vector<int> &row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<vector<int>> matrix2 = {
        {1, 2},
        {3, 4},
        {5, 6}};

    matmul(matrix1, matrix2);

    return 0;
}

