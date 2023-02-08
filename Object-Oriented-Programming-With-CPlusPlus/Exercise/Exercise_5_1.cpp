#include<bits/stdc++.h>
using namespace std;

class Account{
    string depositor_name;
    string account_number;
    string account_type;
    int balance;
    public:
    /*while defining constructor in inside class and using arguments name same as data member then while
    need to use "this->'*/
        Account(string depositor_name,string account_type){
            balance = 0;
            this->depositor_name = depositor_name;
            this->account_type = account_type;
        }
        Account(){};
        void deposit(int amount);
        void display(void);
        void withdraw(int amount);
};

/*while defining constructor in outside of class we can't use arguments name same as data members 
and we don't need to use "this->' keyword*/
// Account::Account(string name,string type){
//     balance = 0;
//     depositor_name = name;
//     account_type = type;
// }

void Account::display(void){
    cout<<"name: "<<depositor_name<<endl;
    cout<<"balance: "<<balance<<endl;
}
void Account::deposit(int amount){
    balance += amount;
}
void Account::withdraw(int amount){
    if(balance >= amount) balance -= amount;
    else cout<<"insufficient balance"<<endl;
}

int main()
{
    Account account[10];
   
   
    int key,amount,account_indx = 0,account_number;
    
    while(1){
        cout<<"Enter 1 for deposite"<<endl;
        cout<<"Enter 2 for withdraw"<<endl;
        cout<<"Enter 3 for display"<<endl;
        cout<<"Enter 4 for create new account: "<<endl;
        cout<<"Enter 0 for exit"<<endl;
        
        cin>>key;
        
        if(key == 0) break;
        if(account_indx == 10){
            cout<<"maximum account limit reached";
            break;
        }
        else if(key == 1){
            
            cout<<"Enter Account Number: ";
            cin>>account_number;
            cout<<"enter deposite amount: ";
            cin>>amount;
            account[account_number].deposit(amount);
        }
        else if(key == 2){
            cout<<"Enter Account Number: ";
            cin>>account_number;
            cout<<"enter withdraw amount: ";
            cin>>amount;
            account[account_number].withdraw(amount);
        }
        else if(key == 3) {
            cout<<"Enter Account Number: ";
            cin>>account_number;
            account[account_number].display();
        }
        else if(key == 4){
            string name,type;
            cout<<"Enter Account Name: ";
            cin>>name;
            cout<<"Enter Account Type: ";
            cin>>type;
            account[account_indx] = Account(name,type);
            account_indx++;
        }
        
    
    }
    return 0;
}


