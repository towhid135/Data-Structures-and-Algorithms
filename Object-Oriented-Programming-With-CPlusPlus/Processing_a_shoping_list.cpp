#include <bits/stdc++.h>
using namespace std;

const int size_ = 50;

class Item{
    int item_code[size_];
    float item_price[size_];
    int index_pointer;

    public:
    void initialize_index_pointer(void){
        index_pointer = 0;
    }
    void get_item_code_and_price(void);
    void sum_of_all_item_price(void);
    void remove_item(void);
    void show_all_item_code_and_price(void);

};

void Item::get_item_code_and_price(void){
    cout<<"Enter Item Code: ";
    cin>>item_code[index_pointer];
    cout<<"Enter Item Price: ";
    cin>>item_price[index_pointer];
    index_pointer++;
}

void Item::sum_of_all_item_price(void){
    float sum = 0;
    for(int i=0; i<index_pointer; i++){
        sum += item_price[i];
    }
    cout<<"All Items Price: "<<sum<<endl;
}

void Item::remove_item(void){
    int itemCode;
    cout<<"Enter the item code to remove: ";
    cin>>itemCode;
    for(int i=0; i<index_pointer; i++){
        if(item_code[i] == itemCode){
            item_price[i] = 0;
        }
    }
    cout<<"Item successfully removed"<<endl;
}

void Item::show_all_item_code_and_price(void){
    for(int i=0; i<index_pointer; i++){
        if(item_price[i] != 0){
            cout<<"Item code: "<<item_code[i]<<" Item price: "<<item_price[i]<<endl;
        }
    }
    cout<<endl;
}


int main(){

    Item grocery;

    grocery.initialize_index_pointer();
    int pressed_btn_value;

    while(pressed_btn_value != 5){
        cout<<"Choose one of the following functions: "<<endl;
        cout<<"Press '1' to Add an Item"<<endl;
        cout<<"Press '2' to Display Total Price"<<endl;
        cout<<"Press '3' to Display All Items"<<endl;
        cout<<"Press '4' to Remove an Item"<<endl;
        cout<<"Press '5' to Quit"<<endl;
        cout<<"Please enter your choice: ";

        cin>>pressed_btn_value;

        switch(pressed_btn_value){
            case 1:
                system("CLS");
                grocery.get_item_code_and_price();
                break;
            case 2:
                system("CLS");
                grocery.sum_of_all_item_price();
                break;
            case 3:
                system("CLS");
                grocery.show_all_item_code_and_price();
                break;
            case 4:
                system("CLS");
                grocery.remove_item();
                break;
            case 5:
                break;
            default:
                cout<<"Error in Input; try again...";
            
        }
    }

    return 0;
}