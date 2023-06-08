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
    friend space operator-(space &);
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
If the operator function is a friend function then it takes one arguments
in unary operation.
*/
space operator-(space &s){
    space temp(-s.x,-s.y,-s.z);
    return temp;
}

int main(){
    space S(1,2,3),Res;
    Res = operator-(S);
    Res.display();
    return 0;
}