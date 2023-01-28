#include <bits/stdc++.h>
using namespace std;

class ABC; //forward declaration of class
class XYZ{
    int data;
    public:
    void setValue(void){
        data = 25;
    }
    friend void add(XYZ, ABC);
};

class ABC{
    int data;
    public:
    void setValue(void){
        data = 25;
    }
    friend void add(XYZ, ABC);
};

void add(XYZ x, ABC a){
    cout<<" sum of data of class XYZ and ABC:  "<<x.data+a.data;
}

int main(){
    XYZ X;
    ABC A;
    X.setValue();
    A.setValue();
    add(X,A);
}