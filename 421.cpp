#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Student {

private:
    int id;
    string name;
    int age;
    string PlaceOfBirth;
    // new student id
    static int new_id;

public:
    Student(string name, int age, string PlaceOfBirth) {
        this->id = new_id++;
        this->name = name;
        this->age = age;
        this->PlaceOfBirth = PlaceOfBirth;
    }

    int get_id() const {
        return id;
    }
    string get_name() const {
        return name;
    }
    int get_age() const {
        return age;
    }
    string get_PlaceOfBirth() const {
        return PlaceOfBirth;
    }

    void Print() {
        cout << "id: " << id << ", name: " << name << ", age: " << age
        << ", PlaceOfBirth: " << PlaceOfBirth << endl;
    }
    // Comparison functions to be used for sorting
    static bool CompareByID(const Student& a, const Student& b) {
        return a.id < b.id;
    }
    static bool CompareByName(const Student& a, const Student& b) {
        return a.name < b.name;
    }
    static bool CompareByAge(const Student& a, const Student& b) {
        return a.age < b.age;
    }
    static bool CompareByPlaceOfBirth(const Student& a, const Student& b) {
        return a.PlaceOfBirth < b.PlaceOfBirth;
    }

};

// All static members must be defined in global scope!
int Student::new_id = 1;
int main() {
    list<Student> students;
    int selection;

    while(true) {
        cout << "1: Add a student" << endl;
        cout << "2: Remove a student by id" << endl;
        cout << "3: Print students" << endl;
        cout << "4: Sort students" << endl;
        cout << "5: Exit" << endl;
        cout << "Select 1-5: ";
        cin >> selection;
        // remove newline symbol
        cin.ignore();

        if (selection == 1) {
            string name;
            string placeOfBirth;
            int age;
            cout << "Name: ";
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            // to prevent crashing if chars are entered as age
            while (true) {
                if (cin.fail()) {
                    cout << "Invalid input, try again: ";
                    // clear error state
                    cin.clear();
                    // ignore everything up until newline
                    cin.ignore(1000, '\n');
                }
                else {
                    // ignore 
                    cin.ignore();
                    break;
                }
            }
            cin.ignore();
            cout << "Place of birth: ";
            getline(cin, placeOfBirth);
            // Put new student in the back of the list;
            students.emplace_back(name, age, placeOfBirth);
            cout << "Student added." << endl;
        }
        else if (selection == 2) {
            int remove;
            cout << "Enter student id to remove: ";
            cin >> remove;

            students.remove_if([remove](const Student& s) {
                return s.get_id() == remove;
            });

            cout << "Student removed." << endl;
        }
        else if (selection == 3) {
            for (Student student : students) {
                student.Print();
            }
        }
        else if (selection == 4) {
            int sort_choice;
            cout << "Sort by: " << endl;
            cout << "1: id " << endl;
            cout << "2: name " << endl;
            cout << "3: age " << endl;
            cout << "4: PlaceOfBirth " << endl;
            cout << "Select 1-4: ";
            cin >> sort_choice;
            // Compare the chosen properties using the custom comparison
            // functions
            if (sort_choice == 1) {
                students.sort(Student::CompareByID);
            }
            else if (sort_choice == 2) {
                students.sort(Student::CompareByName);
            }
            else if (sort_choice == 3) {
                students.sort(Student::CompareByAge);
            }
            else if (sort_choice == 4) {
                students.sort(Student::CompareByPlaceOfBirth);
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }
        else if (selection == 5) {
            cout << "Exiting." << endl;
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
