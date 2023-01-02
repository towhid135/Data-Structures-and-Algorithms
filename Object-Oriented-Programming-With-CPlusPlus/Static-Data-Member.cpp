#include <bits/stdc++.h>
using namespace std;

/*Static data members are also known as class variable*/

class Item{
    static int count;
    int number;
    public:
    void getData(int a){
        number = a;
        count++;
    }
    void getCount(void){
        cout<<"count: "<<count<<endl;
    }
};

//needs to define static class member outside the class definition otherwise it will generate error
int Item::count;

int main(){
    //count is initialized with zero, when first object is created.
    Item first,second,third;

    first.getCount();
    second.getCount();
    third.getCount();

    first.getData(100);
    second.getData(200);

    cout<<"After Reading data"<<endl;
    first.getCount();
    second.getCount();
    third.getCount();

    return 0;
}