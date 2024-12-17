#include <iostream>
#include <array>
#include <algorithm>
#include <random>

using namespace std;

void printArr(array<int, 10>& arr) {
    for (int number : arr) {
        cout << number << ", ";
    }
    cout << endl;
}

int main() {
    array<int, 10> numbers;
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < 10; i++) {
        numbers[i] = dist(gen);
    }
    cout << "Numbers:" << endl;
    printArr(numbers);
    
    // deprecated and removed in c++17, use shuffle instead
    shuffle(numbers.begin(), numbers.end(), gen);
    cout << "Shuffled:" << endl;
    printArr(numbers);
    
    sort(numbers.begin(), numbers.end());
    cout << "Sorted:" << endl;
    printArr(numbers);
    
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed:" << endl;
    printArr(numbers);
    
}
