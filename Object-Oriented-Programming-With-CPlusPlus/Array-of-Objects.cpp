#include <bits/stdc++.h>
using namespace std;

class Employee{
    char name[30];
    float age;
    public:
    void getData(void);
    void putData(void);
};

void Employee::getData(void){
    system("CLS");
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Age: ";
    cin>>age;
}

void Employee::putData(void){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}

const int size_ = 3;

int main(){
    Employee manager[size_];
    for(int i=0; i<size_; i++){
        manager[i].getData();
    }
    for(int i=0; i<size_; i++){
        manager[i].putData();
    }
    return 0;
}