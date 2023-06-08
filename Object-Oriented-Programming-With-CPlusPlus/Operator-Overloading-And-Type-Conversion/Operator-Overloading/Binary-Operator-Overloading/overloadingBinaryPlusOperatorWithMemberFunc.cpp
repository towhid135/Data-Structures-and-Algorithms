#include <bits/stdc++.h>

using namespace std;

class Complex {
    int x; //real part
    int y; //imaginary part

    public:
     Complex() {};
     Complex(int x, int y);
     Complex operator+(Complex &);
     void display();

};

Complex::Complex(int x,int y){
    this->x = x;
    this->y = y;
}

Complex Complex::operator+(Complex &C){
    Complex temp;
    temp.x = x + C.x;
    temp.y = y + C.y;
    return temp;
}

void Complex::display(){
    cout<<x<<" + "<<"j"<<y<<endl;
}


int main(){
    Complex C1,C2,C3;
    C1 = Complex(2,3);
    C2 = Complex(1,2);
    /*
    this line will be executed like
    C3 = C1.operator+(C2)
    */
    C3 = C1 + C2;
    cout<<"C3 = ";
    C3.display();
    return 0;
}