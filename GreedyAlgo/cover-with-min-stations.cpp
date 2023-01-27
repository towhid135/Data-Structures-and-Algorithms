#include<bits/stdc++.h>
using namespace std;


void find_best_stations(set<string> &states_needed, unordered_map< string,set<string> > &stations);
void printSet(set<string > &uset);
int main(){
    set<string> states_needed = {"mt", "wa", "or", "id", "nv", "ut"};
    unordered_map< string,set<string> > stations = { 
        {"kone", {"id", "nv", "ut"} } ,
        {"ktwo", {"wa", "id", "mt"} },
        {"kthree", {"or", "nv", "ca"} },
        {"kfour", {"nv", "ut"} },
        {"kfive", {"ca", "az"} }
        };

    find_best_stations(states_needed,stations);

}

void find_best_stations(set<string> &states_needed, unordered_map< string,set<string> > &stations){

    set<string > final_stations;
    set<string > intersactionSet;
    set<string > differenceSet;
    set<string > states_covered_by_best_station;


    set<string>::iterator sn;

    int cnt = 0;
    while(!states_needed.empty()){
        int max_station_covered = 0;
        string best_station_so_far = "\0";
        for(auto &[station, states_covered_by_station] : stations){
            /*Any stl's set operation function doesn't works with unordered_set*/
            set_intersection(states_needed.begin(),states_needed.end(), states_covered_by_station.begin(), states_covered_by_station.end(), inserter(intersactionSet,intersactionSet.begin()));
           
            if(intersactionSet.size() > max_station_covered){
                best_station_so_far = station;
                max_station_covered = intersactionSet.size();
                states_covered_by_best_station = intersactionSet;
            }

            intersactionSet.clear();
            
        }
        set_difference(states_needed.begin(),states_needed.end(), states_covered_by_best_station.begin(), states_covered_by_best_station.end(), inserter(differenceSet,differenceSet.begin()));
        states_needed = differenceSet;
        final_stations.insert(best_station_so_far);
        differenceSet.clear();
        states_covered_by_best_station.clear();
        
    }


    cout<<"final stations: ";
    printSet(final_stations);

}

void printSet(set<string > &uset){
    for(auto &val : uset){
        cout<<val<<" ";
    }
    cout<<endl;
}

