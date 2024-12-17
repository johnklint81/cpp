#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names = {"Bert", "Adam", "Eric", "Charlie", "Isac", "Fido"};
    sort(names.begin(), names.end());

    for (const auto name : names) {
        cout << name << endl;
    }
    char toRemove = 'A';
    // std::erase_if(container, predicate); (only in c++20 and higher)
    // container: vector, list, etc
    // predicate: lambda function, function pointer, etc
    // [toRemove] is a capture variable
    // (const string& name) each string in names vector is passed into the
    // lambda function as name
    erase_if(names, [toRemove](const string& name) {
        // return true if condition satisfied, indicating element should be
        // removed
        return name[0] == toRemove;
    });
    cout << "----------------------------" << endl;
    for (const auto name : names) {
        cout << name << endl;
    }
    return 0;
}
