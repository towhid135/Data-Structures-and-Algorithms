#include <iostream>
#include <string>
using namespace std;

class student {
    string name;
    int id;

public:
    student() {};
    student(string name, int id = 5); // constructor overloading with default values
    void display() {
        cout << "name: " << name << " id: " << id << endl;
    }
};

student::student(string name, int id) {
    this->name = name;
    this->id = id;
}

int main() {
    student St2("towhid");
    St2.display();
    student St3("towhid",135);
    St3.display();
    return 0;
}
