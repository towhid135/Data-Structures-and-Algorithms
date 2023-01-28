#include <bits/stdc++.h>
using namespace std;

class sample_ {
    int a;
    int b;
    public:
      void setValue(void){
        a = 25;
        b = 24;
      }
    //friend function can be declared & defined inside public/private method
    friend float mean(sample_ s);
};

float mean(sample_ s){
    return float(s.a + s.b)/2;
}


int main(){
    sample_ X;
    X.setValue();
    cout<<"mean: "<<mean(X);
}