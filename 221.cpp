#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string input;
    string pattern;
    int count = 0;
    cout << "Enter string: ";
    getline(cin, input);
    cout << "Enter pattern: ";
    getline(cin, pattern);
    // Search for the first position of the pattern. If not found it is set to
    // string::npos
    int pos = input.find(pattern);
    while (pos != string::npos) {
        count++;
        // Continue the search from current pos + size of last pattern.
        pos = input.find(pattern, pos + pattern.size());
    }
    cout << "The pattern was found " << count << " times." << endl;
}
