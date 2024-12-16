#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    while (true) {
        cout << "Type (1) to print the file," << endl;
        cout << "Type (2) to enter a string to the file," << endl;
        cout << "Type (3) to overwrite the file," << endl;
        cout << "Type (4) to exit the program." << endl;
        int input;
        cin >> input;
        // without this line, the program loops infinitely when using alt. 2.
        // streamsize defines the size of the data i n the stream. ::max
        // returns the maximum size allowed for the stream.
        // cin.ignore() ignores all characters up until newline \n. this means
        // that any trailing remnants from previous inputs is removed, such
        // as stray newlines that may cause infinite loops.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (input == 4) {
            break;
        }
        if (input == 1) {
            ifstream file("311.txt");
            string line;
            while(getline(file, line)) {
                cout << line << endl;
            }
            // not necessary, done automatically
            file.close();
        }
        if (input == 2) {
            // open to write and ios::app to append
            ofstream file("311.txt", ios::app);
            string instring;
            cin >> instring;
            file << instring << endl;
            file.close();
        }
        if (input == 3) {
            // open file to write and ios::trunc to overwrite
            ofstream file("311.txt", ios::trunc);
            string instring;
            cin >> instring;
            file << instring << endl;
            file.close();
        }
    }
    

}
