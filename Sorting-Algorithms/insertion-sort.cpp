#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,lastSortIndx,holdRunningIndx,unSortIndx,sortIndx,flag,temp,totalCases,test;
    //printf("Enter number of input element inside array: ");
    freopen("read.txt", "r", stdin);
    freopen("write.txt", "w", stdout);
    //printf("Enter number of test cases: ");
    scanf("%d",&totalCases);
    for(test = 1; test <= totalCases; test++ ){
        //printf("Enter number of input element inside array: ");
        scanf("%d",&n);
        int ara[n];
        //printf("Enter numbers: ");
        
        //Taking input
        for(i = 0; i < n; i++){
            cin>>ara[i];
            //cout<<ara[i]<<" ";
        }
        
        //sorting
        // one approach
        /*for(unSortIndx = 1; unSortIndx < n; unSortIndx++){
            holdRunningIndx = unSortIndx;
            lastSortIndx = unSortIndx-1;
            for(sortIndx = lastSortIndx; sortIndx >= 0; sortIndx--){
                flag = 0;
                if(ara[holdRunningIndx] < ara[sortIndx]){
                    temp = ara[sortIndx];
                    ara[sortIndx] = ara[holdRunningIndx];
                    ara[holdRunningIndx] = temp;

                    holdRunningIndx = sortIndx;
                    flag = 1;
                }
                if(flag == 0) break;

            }
        }*/

        //another approach
        for(unSortIndx = 1; unSortIndx < n; unSortIndx++){
            key = ara[unSortIndx];
            lastSortIndx = unSortIndx - 1;

            while(lastSortIndx >= 0 && ara[lastSortIndx] > key){
                ara[lastSortIndx+1] = ara[lastSortIndx];
                lastSortIndx--;
            }
            ara[lastSortIndx+1] = key;
        }
        
        //printing the sorted array
        for(i=0; i<n; i++){
            cout<<ara[i]<<" ";
        }
        cout<<"\n";
        
        }
    
    
    return 0;
}