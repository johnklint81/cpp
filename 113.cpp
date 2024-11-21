#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int size = stoi(argv[1]); 
    string pattern = argv[2]; 
    int patternWidth = pattern.length();
    string leftPadding = "";
    int leftPaddingSize;
    int lineWidth = size + 2;
    int middlePaddingSize = lineWidth - 2 * patternWidth;
    // Upper part of the picture
    while (middlePaddingSize > 0) {
        string middlePadding = string(middlePaddingSize, ' ');
        cout << leftPadding << pattern << middlePadding << pattern << endl;
        middlePaddingSize -= 2;
        leftPaddingSize += 1;
        leftPadding = string(leftPaddingSize, ' ');
    }
    // Middle part of the picture, take into account even or odd size of figure
    if (size % 2 == 0) {
    cout << leftPadding << pattern << pattern << endl;
    }
    else {
    cout << leftPadding << pattern.substr(1) << pattern << endl;
    }
    // Lower part of the figure
    while (leftPaddingSize > 0) {
        leftPaddingSize -= 1;
        leftPadding = string(leftPaddingSize, ' ');
        middlePaddingSize += 2;
        string middlePadding = string(middlePaddingSize, ' ');
        cout << leftPadding << pattern << middlePadding << pattern << endl;
    }

    return 0;
}

