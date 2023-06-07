#include <bits/stdc++.h>
using namespace std;

class space {
    int x;
    int y;
    int z;
    public:
    space(){};
    space(int x,int y, int z);
    void display(void);
    space operator-();
};
space::space(int x,int y,int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void space::display(void){
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
}

/*
If the operator function is a member function then it takes no arguments
in unary operation
*/
space space::operator-(){
    space temp(-x,-y,-z);
    return temp;
}

int main(){
    space S(1,2,3),Res;
    Res = -S;
    Res.display();
    return 0;
}