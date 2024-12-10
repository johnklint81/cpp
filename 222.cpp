#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool isPalindrome(char *str, int size) {
    bool palindrome = true;
    for (int i = 0; i < size; i++) {
    if (str[i] != str[size - i -1]) {
            palindrome = false;
        }
    }
    return palindrome;
}

int main(int argc, char *argv[]) {
    char* input = argv[1];
    int size = strlen(input);
    bool palindrome = isPalindrome(input, size);

    if (palindrome) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
