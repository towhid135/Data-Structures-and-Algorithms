#include <bits/stdc++.h>
using namespace std;

int main(){

    // auto comp = [](pair<char,int> a, pair<char,int> b){
    //     return a.second > b.second;
    // }
    function<bool(pair<char,int>,pair<char,int>)> comp = [](const pair<char,int>& a, const pair<char,int>& b) {
    return a.second > b.second;
    };

    priority_queue< pair<char,int>, vector< pair<char,int> >, decltype(comp) > pq(comp);

    for(int i=0; i<3; i++){
        char node;
        int val;
        cin>>node;
        cin>>val;
        pq.push({node,val});
    }

    while(!pq.empty()){
        pair<char,int> top;
        top = pq.top();
        cout<<"top: "<<top.first<<" "<<top.second<<endl;
        pq.pop();
    }
}