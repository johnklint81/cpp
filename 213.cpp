#include <iostream>
#include <string>

using namespace std;

// Using a template so we can work with both char and int and to avoid
// overloading functions. NEEDS TO BE IN FRONT OF ALL FUNCTIONS USING THE 
// TEMPLATE!

template <typename T>
void sort(T array[], int size, bool ascending = true) {
    // Bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Bool to determine if we swap two elements
            bool swap;
            if (ascending) {
                // If list is ascending, smaller elements should come first
                swap = array[j] > array[j + 1];
            } 
            else {
                // If list is descending, larger elements should come first
                swap = array[j] < array[j + 1];
            }
            // If we should swap, do it.
            if (swap) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
        }
    }
}

// Also needs template!
template <typename T>
void printArray(T array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    // Int test
    int intArray[] = {4, 2, 3, 54, 1, 0, -99, -3};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "Unsorted array: ";
    printArray(intArray, intArraySize);
    sort(intArray, intArraySize);
    cout << "Sorted array: ";
    printArray(intArray, intArraySize);
    cout << "Sorted descending: ";
    sort(intArray, intArraySize, false);
    printArray(intArray, intArraySize);

    cout << "--------------------------------------" << endl;

    // char test
    char charArray[] = {'x', 'c', 'g', 'o', 'd', 'z', 'z', 'a'};
    int charArraySize = sizeof(charArray) / sizeof(charArray[0]);
    cout << "Unsorted array: ";
    printArray(charArray, charArraySize);
    sort(charArray, charArraySize);
    cout << "Sorted array: ";
    printArray(charArray, charArraySize);
    cout << "Sorted descending: ";
    sort(charArray, charArraySize, false);
    printArray(charArray, charArraySize);
}
