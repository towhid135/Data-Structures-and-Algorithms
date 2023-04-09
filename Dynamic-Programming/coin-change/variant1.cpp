#include <bits/stdc++.h>
using namespace std;

//Q: can we make 15 taka with coins 4, 7, 10
void print_grid(vector< vector<int> > &grid,vector<int> &coins);
int main(){
    vector<int> coins = {4,7,10};
    vector< vector<int> > grid(3,vector<int> (16,0));
    for(int c=0; c<grid.size(); c++){
        for(int t=0; t<grid[0].size(); t++){
            if(t == 0) grid[c][t] = 1;
            else if(t < coins[c]) grid[c][t] = 0;
            else{
                if(grid[c][t - coins[c]]) grid[c][t] = 1;
                else if(c > 0) grid[c][t] = grid[c][t-1];
                else grid[c][t] = 0;
            }
        }
    }
    print_grid(grid,coins);
    return 0;
}

void print_grid(vector< vector<int> > &grid,vector<int> &coins){
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cout<<"coin: "<<coins[i]<<" t:"<<j<<" P:"<<grid[i][j]<<endl;
        }
    }
}