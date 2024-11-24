#include <string>
#include <iostream>
#include <random>

using namespace std;

int main() {
    
    // Generate a seed for the random generator
    random_device rd;
    // Instantiate the random generator engine, mt19937 is the most common
    mt19937 gen(rd());
    // Specifies the desired range of the generator
    uniform_int_distribution<> dist(0, 100);
    // Draw a random number from the generator
    int hidden = dist(gen);
    int counter = 7;
    int guess;
    cout << "Enter your guess: ";
    // Loop until correct answer or 7 guesses
    while (counter > 0) {
        cin >> guess;
        if (guess == hidden) {
            cout << guess << " is correct!" << endl;
            return 0;
        }
        else if (guess < hidden) {
            cout << guess << " is too small!" << endl;
        }
        else {
            cout << guess << " is too big!" << endl;
        }
        counter--;
        if (counter > 0) {
            cout << "Try again: ";
        }
        else {
            cout << "You failed. The correct number was: " << hidden << endl;
        }
    }
}
