#include <bits/stdc++.h>
using namespace std;

void printGraph(unordered_map< char, unordered_map< char,int > > &graph);
void printLowCostPath(unordered_map<char,char> parent, char &node);
void readInput(unordered_map< char, unordered_map< char,int > > &graph,unordered_map<char,int> &cost,char &source, char &destination);
void low_cost_path(unordered_map< char, unordered_map< char,int > > &graph,unordered_map<char,int> &cost,char &source, char &destination);
int main(){
    freopen("input.txt","r",stdin);
    unordered_map< char, unordered_map< char,int > > graph;
    unordered_map<char,int> cost;
    char source,destination;
    readInput(graph,cost,source,destination);
    low_cost_path(graph,cost,source,destination);
    // function<bool(pair<char,int>,pair<char,int>)> comp = [](const pair<char,int>& a, const pair<char,int>& b) {
    // return a.second > b.second;
    // };

    // priority_queue< pair<char,int>, vector< pair<char,int> >, decltype(comp) > pq(comp);

    // for(int i=0; i<3; i++){
    //     char node;
    //     int val;
    //     cin>>node;
    //     cin>>val;
    //     pq.push({node,val});
    // }

    // while(!pq.empty()){
    //     pair<char,int> top;
    //     top = pq.top();
    //     cout<<"top: "<<top.first<<" "<<top.second<<endl;
    //     pq.pop();
    // }
}

void readInput(unordered_map< char, unordered_map< char,int > > &graph, unordered_map<char,int> &cost, char &source, char &destination){
    int numberOfLines,numOfNode,second_;
    char key,first_;

    cin>>numberOfLines;
    cin>>source;
    cin>>destination;

    // cout<<numberOfLines<<" "<<source<<" "<<destination<<endl;
    cost[destination] = 1000;
    for(int i=1; i<= numberOfLines; i++){
        cin>>numOfNode;
        cin>>key;
        // cout<<numOfNode<<" "<<key<<endl;
        if(numOfNode == 1) {
            graph[key]['\0'] = 0;
            cost[key] = 1000;
        }
        for(int j=1; j<numOfNode; j++){
            if(key == source) cost[key] = 0;
            else cost[key] = 1000;
            cin>>first_;
            cin>>second_;
            // cout<<first_<<" "<<second_<<endl;
            if (first_ != '\0' && second_ != 0){
                graph[key][first_] = second_;
            }
        }
    }

    // printGraph(graph);
}

void printGraph(unordered_map< char, unordered_map< char,int > > &graph){
    for(auto &[key,val] : graph){
        cout<<"key: "<<key<<", ";
        for(auto &[key2,val2] : val){
            if(key2 != '\0') cout<<key2<<" "<<val2<<" ";
        }
        cout<<endl;
    }
}

void printLowCostPath(unordered_map<char,char> parent, char &node){
    // cout<<"entered into shortest path"<<endl;
    if(parent[node] != node) printLowCostPath(parent,parent[node]);
    cout<<node<<" ";
}

void low_cost_path(unordered_map< char, unordered_map< char,int > > &graph, unordered_map<char,int> &cost ,char &source, char &destination){
    function< bool(pair<char,int>, pair<char,int>) > comp = [](const pair<char,int>& a, const pair<char,int>& b){
        return a.second > b.second;
    };

    priority_queue< pair<char,int>, vector< pair<char,int> >, decltype(comp) > pq(comp);
    unordered_map<char,char> parent;
    pair<char,int> tempVal;
    vector<bool> visited(26,false);

    /*updating parent & cost for the nodes directly connected with the source*/
    for(auto &[node,weight] : graph[source]){
        // cout<<"node: "<<node<<" weight: "<<weight<<endl;
        cost[node] = weight;
        parent[node] = source;
        tempVal = {node,weight};
        pq.push(tempVal);
    }
    visited[source - 'a'] = true;


    
    while(!pq.empty()){
        pair<char,int> top;
        top = pq.top();
        pq.pop();

        char topNode = top.first;
        // int topNodeCost = top.second;
        int changedCost;
        pair<char,int> tempPair;

        for(auto &[node,weight] : graph[topNode]){
            int weightPlusCost = cost[topNode] + weight;
            // cout<<"node: "<<cost[node]<<" weightPlusCost: "<<weightPlusCost<<endl;

            if(cost[node] > weightPlusCost ) {
                cost[node] = weightPlusCost;
                parent[node] = topNode;
            }
            tempPair = {node,cost[node]};
            if(!visited[node - 'a']) pq.push(tempPair);
        }
        visited[topNode - 'a'] = true;
        

    }

    printLowCostPath(parent,destination);
}