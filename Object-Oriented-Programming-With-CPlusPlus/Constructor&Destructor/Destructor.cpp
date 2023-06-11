#include <bits/stdc++.h>
using namespace std;

class test {
    char *ch;
    
    public:
    test(int size);
    ~test();
};
test::test(int size){
    cout<<"allocating memory for ch"<<endl;
    ch = new char[size];
}

test::~test(){
    cout<<"deleting memory for ch"<<endl;
    delete ch;
}

int main(){
    test t1(5);
}