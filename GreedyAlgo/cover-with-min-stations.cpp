#include<bits/stdc++.h>
using namespace std;


void find_best_stations(unordered_set<string> &states_needed, unordered_map< string,unordered_set<string> > &stations);
int main(){
    unordered_set<string> states_needed = {"mt", "wa", "or", "id", "nv", "ut"};
    unordered_map< string,unordered_set<string> > stations = { 
        {"kone", {"id", "nv", "ut"} } ,
        {"ktwo", {"wa", "id", "mt"} },
        {"kthree", {"or", "nv", "ca"} },
        {"kone", {"nv", "ut"} },
        {"kone", {"ca", "az"} }

        };

    find_best_stations(states_needed,stations);

}

void find_best_stations(unordered_set<string> &states_needed, unordered_map< string,unordered_set<string> > &stations){

    unordered_set<string > final_stations;
    unordered_set<string > intersactionSet;
    unordered_set<string > differenceSet;
    unordered_set<string > states_covered_by_best_station;
    string best_station_so_far;
    int max_station_covered = 0;

    unordered_set<string>::iterator sn;

    while(!states_needed.empty()){
        for(auto &[station, states_covered_by_station] : stations){
            set_intersection(states_needed.begin(),states_needed.end(), states_covered_by_best_station.begin(), states_covered_by_best_station.end(), inserter(intersactionSet,intersactionSet.begin()));
            if(intersactionSet.size() > max_station_covered){
                best_station_so_far = station;
                max_station_covered = intersactionSet.size();
            }

            set_difference(states_needed.begin(),states_needed.end(), intersactionSet.begin(), intersactionSet.end(), inserter(differenceSet,differenceSet.begin()));
        }
        states_needed = differenceSet;
        final_stations.insert(best_station_so_far);
    }

    cout<<"final stations: ";
    for(auto &st : final_stations){
        cout<<st<<" ";
    }
    cout<<endl;

}

