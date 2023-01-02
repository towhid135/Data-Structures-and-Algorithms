#include <bits/stdc++.h>
using namespace std;

class Test{
    int code;
    static int count;
    public:
    void setCode(void){
        code = ++count;
    }
    void showCode(void){
        cout<<"Code: "<<code<<endl;
    }
    /*static function can only work with other
    static members
    */ 
    static void showCount(void); //declared but not defined
    /*we can also define it here like this
    static void showCount(void){
        cout<<"count: "<<count<<endl;
    }
    */
};

int Test::count;

void Test::showCount(void){
    cout<<"count: "<<count<<endl;
}

int main(){
    Test First,Second;
    Test::showCount(); //accessing static function
    First.setCode();
    First.setCode();

    First.showCode();
    Test::showCount();
    return 0;
}