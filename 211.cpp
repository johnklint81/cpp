#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int size = 100;
    // Note, can NOT be const int, because vector needs to be able to modify
    // elements!
    vector<int> numbers(size);
    // iota works like np.arange() except args are:
    // (iterator pointing to the position in the container where the sequence
    // will begin, iterator pointing to the end, value to begin iterating from).
    // The reason that iterators are used and not just raw pointers is to 
    // provide an abstraction that works consistently across all types of
    // containers (arrays, maps, lists, etc.
    iota(numbers.begin(), numbers.end(), 0);
    float average = static_cast<float>(accumulate(numbers.begin(),
                                                  numbers.end(),
                                                  0)) / numbers.size();
    // min_element and max_element returns pointers to iterators so they need
    // to be dereferenced
    const int minElement = *min_element(numbers.begin(), numbers.end());
    const int maxElement = *max_element(numbers.begin(), numbers.end());
    cout << "The elements in the vector are:" << endl;
    // for_each iterates from start to end and applies the provided function
    // to each element. in this case the cout that prints the value. 
    // [](int num) {cout << num << " ";} is a lambda function, or anonymous
    // function.
    for_each(numbers.begin(), numbers.end(), [](int num) {
        cout << num << " ";
    });
    cout << endl;
    cout << "Mean:" << average << endl;
    cout << "Max: " << maxElement << endl;
    cout << "Min: " << minElement << endl;
}
