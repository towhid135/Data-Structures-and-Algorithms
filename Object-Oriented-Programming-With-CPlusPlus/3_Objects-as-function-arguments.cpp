#include <bits/stdc++.h>
using namespace std;

class Time{
    int hours;
    int minutes;
    public:
    void getTime(void){
        cout<<"Enter hour: ";
        cin>>hours;
        cout<<"Enter minutes: ";
        cin>>minutes;
    }
    void putTime(void){
        cout<<"total hours: "<<hours;
        cout<<"total minutes: "<<minutes;
    }
    void sum(Time t1, Time t2);
};

void Time::sum(Time t1, Time t2){
    int totalHours = t1.hours + t2.hours;
    int totalMinutes = t1.minutes + t2.minutes;

    cout<<"total hours: "<<totalHours<<endl;
    cout<<"total minutes: "<<totalMinutes<<endl;
}

int main(){
    Time T1,T2;
    T1.getTime();
    T2.getTime();

    T1.sum(T1,T2);
    T1.putTime();

    return 0;
}