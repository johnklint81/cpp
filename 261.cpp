#include <iostream>
#include <random>

using namespace std;

int main() {
    int size;
    cin >> size;
    //int *arr = (int*)malloc(size * sizeof(int));
    int *arr = new int[size];
    // Provide seed for generator
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(rng);
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
