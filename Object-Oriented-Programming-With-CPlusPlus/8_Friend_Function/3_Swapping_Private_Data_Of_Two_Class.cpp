#include <bits/stdc++.h>
using namespace std;

class class_2; //forward declaration of class

class class_1{
    int data_1;
    public:
        void setData(int val){
            data_1 = val;
        }
        void showData(void){
            cout<<"data_1 of class_1: "<<data_1<<endl;
        }
        //friend function
        friend void swap(class_1 &x, class_2 &y);

};

class class_2{
    int data_2;
    public:
        void setData(int b){
            data_2 = b;
        }
        void showData(void){
            cout<<"data_2 of class_2: "<<data_2<<endl;
        }
        //friend function
        friend void swap(class_1 &x, class_2 &y);
};

void swap(class_1 &x, class_2 &y){
    //swapping private data of class_1 and class_2
    int temp = x.data_1;
    x.data_1 = y.data_2;
    y.data_2 = temp;
}

int main(){
    class_1 X;
    class_2 Y;
    X.setData(5);
    Y.setData(10);

    cout<<"Before calling friend function: "<<endl;
    X.showData();
    Y.showData();

    swap(X,Y);
    
    cout<<"After calling friend function: "<<endl;
    X.showData();
    Y.showData();

    return 0;
}