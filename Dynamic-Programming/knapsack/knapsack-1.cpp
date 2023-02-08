#include <bits/stdc++.h>
using namespace std;

void read_items(unordered_map<string,pair<int,int> > &items);
void printItem(unordered_map<string,pair<int,int> > &items);
void maximize_item(unordered_map<string,pair<int,int> > &items);
void printGrid(int grid[][5],unordered_map<int, string > &string_to_index);
int main(){
    freopen("knapsack-1.txt","r",stdin);
    unordered_map<string,pair<int,int> > items;
    read_items(items);
    printItem(items);
    maximize_item(items);
    return 0;
}

void read_items(unordered_map<string,pair<int,int> > &items){
    int totalItems;
    string key;
    int price,knapsackSize;

    cin>>totalItems;
    for(int i=1; i <= totalItems; i++){
        cin>>key>>price>>knapsackSize;
        items[key] = {price,knapsackSize};
    }
}

void printItem(unordered_map<string,pair<int,int> > &items){
    cout<<"Items: "<<endl;
    for(auto &[key,value]: items){
        cout<<key<<" "<<value.first<<" "<<value.second<<endl;
    }
    cout<<endl;
}

void maximize_item(unordered_map<string,pair<int,int> > &items){
    unordered_map<int, string > string_to_index = { {0,"s"},{1,"l"},{2,"g"},{3,"i"} };
    int grid[4][5];

    int row,col,itemKnapsackSize;
    for(row = 0; row < 4; row++){
        for(col=0; col < 5; col++){
            if(col == 0) grid[row][col] = 0;
            else if (row == 0){
                itemKnapsackSize = items[ string_to_index[row] ].second;
                if(itemKnapsackSize <= col) grid[row][col] = items[ string_to_index[row] ].first;
                else grid[row][col] = 0;
            }
            else{
                
                int previousPrice = grid[row-1][col];
                int newPrice;
                itemKnapsackSize = items[ string_to_index[row] ].second;
                if(itemKnapsackSize == col) {
                    newPrice = items[ string_to_index[row] ].first;
                    newPrice = max(previousPrice,newPrice);
                    grid[row][col] = newPrice;
                }
                else if( itemKnapsackSize < col ){
                    newPrice = items[ string_to_index[row] ].first + grid[row-1][col - itemKnapsackSize];
                    newPrice = max(previousPrice, newPrice);
                    grid[row][col] = newPrice;
                }
                else grid[row][col] = grid[row - 1][col];
            }
        }
    }

    printGrid(grid,string_to_index);

    // for(int i=0; i<4; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    
}

void printGrid(int grid[][5],unordered_map<int, string > &string_to_index){
    for(int i=0; i<4; i++){
        cout<<string_to_index[i]<<" ";
        for(int j=0; j<5; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

