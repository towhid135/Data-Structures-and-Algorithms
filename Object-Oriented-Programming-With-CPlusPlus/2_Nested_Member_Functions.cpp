/*This is an example of using nested member function. Here we have use "is_binary_number"
member funtion inside of "create_ones_complement" member function. And "create_ones_complement" member function
was nested inside "print" member function.*/

#include<bits/stdc++.h>

using namespace std;

class ones_complement {
    //private variable
    string binary_number;

    public:
    void get_the_number(string number){
        binary_number = number;
    }
    bool is_binary_number(){
        for(char &c : binary_number){
            // cout<<"c: "<<c<<endl;
            if(c != '0' && c != '1') return false;
        }
        return true;
    }

    void create_ones_complement(){
        bool isBinary = is_binary_number();
        if(isBinary){
            for(char &c : binary_number){
                if(c == '0') c = '1';
                else c = '0';
            }
        }
        else cout<<"Can't create ones complement, Since the number is not binary";
    }

    void print(){
        create_ones_complement();
        cout<<"1's complement of the given binary is: ";
        for(char &ch : binary_number){
            cout<<ch;
        }
        cout<<endl;
    }

};

int main(){
    bool result;
    ones_complement obj1;
    obj1.get_the_number("101010");
    obj1.print();
    // result = obj1.is_binary_number();
    // cout<<result;
    return 0;
}