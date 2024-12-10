#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    int size = input.size();
    // Keep track of whether a char is repeated
    bool found = false;
    for (int i = 0; i < size; i++) {
        char currentChar = input[i];
        for (int j = 0; j < size; j++) {
            // exclude currentChar and see if a any position matches
            // currentChar
            if (i != j && currentChar == input[j]) {
                found = true;
            }
        }
        if (!found) {
            cout << input[i];
        }
        found = false;
    }
    cout << endl;
    return 0;
}
