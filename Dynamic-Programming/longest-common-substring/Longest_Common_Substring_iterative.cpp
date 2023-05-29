#include <bits/stdc++.h>
using namespace std;

int find_longest_common_substring(vector< vector<int> > &grid, string &mainString, string &pattern);
void print_grid(vector< vector<int> > &grid, int &row, int &col);
int main(){
    string mainString = "towhidul islam",pattern = "idul";
    int mainStringLen = mainString.length();
    int patternLen = pattern.length(), res;
    vector< vector<int> > grid(patternLen, vector<int> (mainStringLen,0));
    
    res = find_longest_common_substring(grid,mainString,pattern);
    print_grid(grid,patternLen,mainStringLen);
    cout<<"substring len: "<<res<<endl;
    
    return 0;
}

void print_grid(vector< vector<int> > &grid, int &row, int &col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int find_longest_common_substring(vector< vector<int> > &grid, string &mainString, string &pattern){
    int mLen = mainString.length();
    int pLen = pattern.length();
    int maxSubStringLen = 0;
    for(int pIndx = 0; pIndx < pLen; pIndx++){
        for(int mStrIndx = 0; mStrIndx < mLen; mStrIndx++){
            if(pattern[pIndx] == mainString[mStrIndx]){
                if(pIndx == 0){
                    grid[pIndx][mStrIndx] = 1;
                }else{
                    grid[pIndx][mStrIndx] = grid[pIndx - 1][mStrIndx - 1] + 1;
                }
                if(grid[pIndx][mStrIndx] > maxSubStringLen) maxSubStringLen = grid[pIndx][mStrIndx];
            }else{
                grid[pIndx][mStrIndx] = 0;
            }
         }
    }
    return maxSubStringLen;
}
