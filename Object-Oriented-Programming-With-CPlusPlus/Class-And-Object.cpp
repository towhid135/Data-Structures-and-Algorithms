#include <bits/stdc++.h>
using namespace std;

class item {
    int number; // private by default
    float cost; // private by default

    public:
    void getdata(int a, float b); //declared but not defined
    void putdata(void){
        cout<<"number: "<<number<<endl;
        cout<<"cost: "<<cost<<endl;
    }

};

// Member function definition out side of class

//used membership label "item"
void item::getdata(int a, float b){
    //private variables directly used
    number = a; 
    cost = b;
}

//<<<<<<<<<<<<<<<<<<Main Program>>>>>>>>>>>>>>>>>>>>>>

int main(){
    // here fruits is the object/instance of the class item
    item fruits;
    fruits.getdata(10,100.10);
    fruits.putdata();

    return 0;
}