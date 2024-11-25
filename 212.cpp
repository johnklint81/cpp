#include <iostream>
#include <string>
#include <numeric>
#include <vector>
// For transform
#include <algorithm>
// Needed for multiplies<>()
#include <functional>

using namespace std;


int main(int argc, char *argv[]) {
    int size = stoi(argv[1]);
    vector<int> vec1(size);
    vector<int> vec2(size);
    iota(vec1.begin(), vec1.end(), 0);
    iota(vec2.begin(), vec2.end(), 1);

    // sum
    vector<int> sum(size);
    transform(vec1.begin(), vec1.end(), vec2.begin(), sum.begin(), plus<>());
    // subtract
    vector<int> difference(size);
    transform(vec1.begin(), vec1.end(), vec2.begin(), difference.begin(), 
              minus<>());
    // multiply
    vector<int> product(size);
    transform(vec1.begin(), vec1.end(), vec2.begin(), product.begin(),
              multiplies<>());

    cout << "Sum: ";
    for (int res : sum) {
        cout << res << " ";
    }
    cout << endl;
    cout << "Difference: ";
    for (int res : difference) {
        cout << res << " ";
    }
    cout << endl;
    cout << "Product: ";
    for (int res : product) {
        cout << res << " ";
    }
    cout << endl;
    
}
