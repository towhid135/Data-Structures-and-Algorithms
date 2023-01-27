#include<bits/stdc++.h>
using namespace std;

void printSet(set<string > &uset);
int main(){
    set<string> states_needed = {"mt", "wa", "or", "id", "nv", "ut"};
    set<string> covered = {"wa", "id", "mt"};
    set<string> intersactionSet;

    set_intersection(states_needed.begin(),states_needed.end(),covered.begin(),covered.end(),inserter(intersactionSet,intersactionSet.begin()));
    printSet(intersactionSet);



}

void printSet(set<string > &uset){
    for(auto &val : uset){
        cout<<val<<" ";
    }
    cout<<endl;
}