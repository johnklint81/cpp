#include <iostream>

using namespace std;

#define N 5

void Increment(int Array[N]) {
    for(int i = 0; i < N; i++) {
        Array[i]++;
    }
}

void Increment(int value) {
    value++;
}


int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    int val = 7;
    // Here arr is passed by reference so changes made to the array inside the
    // loop reflect this. Arrays are always passed by reference in C++ when
    // they are passed to functions. Primitive types, however,are passed by 
    // value as default.
    Increment(arr);

    // Here we pass val as a value and increment it in the local scope of the
    // function. Thus, it does not change outside the scope. We could pass as
    // &val instead if we wanted it to change. But then we would need to change
    // function signature to reflect this.
    Increment(val);
    cout << "array values are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "val is: " << val << endl;
}
