#include<bits/stdc++.h>
using namespace std;

#define FEET_TO_METER 0.3048

class Distance_in_Feet;
class Distance_in_Meter{
    float distance;
    public:
     Distance_in_Meter(){distance = 0;};
     void set_distance_in_meter(int meter);
     void set_distance_in_centimeter(int centimeter);
     void display(void);
     friend Distance_in_Meter add_distance(Distance_in_Meter,Distance_in_Feet);
};

class Distance_in_Feet{
    float distance;
    public:
     Distance_in_Feet(){distance = 0;};
     void set_distance_in_feet(int feet);
     void set_distance_in_inch(int inch);
     void display(void);
     friend Distance_in_Meter add_distance(Distance_in_Meter,Distance_in_Feet);
};

void Distance_in_Meter::set_distance_in_meter(int meter){
    distance += meter;
}
void Distance_in_Meter::set_distance_in_centimeter(int centimeter){
    distance += (centimeter/100);
}

void Distance_in_Meter::display(void){
   printf("distance in meter %0.2llf",distance);
}

void Distance_in_Feet::set_distance_in_feet(int feet){
    distance += feet;
}
void Distance_in_Feet::set_distance_in_inch(int inch){
    distance += (inch / 12);
}

void Distance_in_Feet::display(void){
    cout<<"distance in feet: "<<distance<<endl;
}

Distance_in_Meter add_distance(Distance_in_Meter DM, Distance_in_Feet DF){
    Distance_in_Meter DM_;
    float distance = (DF.distance * FEET_TO_METER) + DM.distance;
    DM_.set_distance_in_meter(distance);
    return DM_;

}

int main(){
    Distance_in_Meter DM, DM_;
    Distance_in_Feet DF;
    DM.set_distance_in_meter(100);
    DM.set_distance_in_centimeter(500);
    DM.display();

    DF.set_distance_in_feet(100);
    DF.set_distance_in_inch(60);
    DF.display();

    DM_ = add_distance(DM,DF);
    cout<<"after calling friend function: "<<endl;
    DM_.display();
    return 0;
}