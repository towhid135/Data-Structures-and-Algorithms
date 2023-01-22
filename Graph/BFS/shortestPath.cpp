#include <bits/stdc++.h>

using namespace std;

void take_input(unordered_map< char,vector<char> > &graph,char &source,char &destination);
void printGraph(unordered_map< char, vector<char> > &graph);
void findShortestPath(unordered_map< char, vector<char> > &graph,char &source,char &destination);
void printShortestPath(unordered_map<char,char> parent, char &node);
int main(){
    unordered_map< char,vector<char> > graph;
    char source,destination;
    freopen("input.txt","r",stdin);
    take_input(graph,source,destination);
    findShortestPath(graph,source,destination);
    // printGraph(graph);
    
}

void take_input(unordered_map< char,vector<char> > &graph,char &source,char &destination){
    int numberOfLines, nodeNumber;;
    char key,val;

    cin>>numberOfLines;
    cin>>source;
    cin>>destination;

    for(int i=1; i<=numberOfLines; i++){
    cin>>nodeNumber;
    cin>>key;
    // cout<<numberOfLines<<" "<<nodeNumber<<" "<<key;
    if(nodeNumber == 1) graph[key].push_back('\0');
    for(int j=1; j<nodeNumber; j++){
        cin>>val;
        // cout<<"val: "<<val<<endl;
        graph[key].push_back(val);
    }

    }
}

void printGraph(unordered_map< char, vector<char> > &graph){
    for(auto &[key,val] : graph){
        cout<<"key: "<<key<<" values: ";
        for(char &ch : val){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void printShortestPath(unordered_map<char,char> parent, char &node){
    // cout<<"entered into shortest path"<<endl;
    if(parent[node] != node) printShortestPath(parent,parent[node]);
    cout<<node<<" ";
}

void findShortestPath(unordered_map< char, vector<char> > &graph,char &source,char &destination){
    queue<char> Q;
    Q.push(source);
    unordered_map<char,char> parent;
    vector<bool> markVisitedNode(26,false);

    markVisitedNode[source - 'a'] = true;
    parent[source] = source;

    while(!Q.empty()){
        char top = Q.front();
        // cout<<"top: "<<top<<endl;
        Q.pop();
        // cout<<"des: "<<destination<<" top: "<<top<<endl;
        if(top == destination) break;
        else{
            // cout<<"childNode: ";
            for(char &childNode : graph[top]){
                // cout<<childNode<<" mark:"<<markVisitedNode[childNode - 'a']<<endl;
                if(!markVisitedNode[childNode - 'a'] && childNode != '\0'){
                    // cout<<childNode<<" pushed into Q"<<endl;
                    parent[childNode] = top;
                    markVisitedNode[childNode - 'a'] = true;
                    Q.push(childNode);
                }
            }
            cout<<endl;
            
        }
    }
    cout<<"shortest path: ";
    printShortestPath(parent,destination);


}
