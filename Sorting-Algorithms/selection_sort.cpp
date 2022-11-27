#include <bits/stdc++.h>

using namespace std;

int find_minimum(int ara[], int startIndx, int endIndx);
int main()
{
    int nums[] = {64,25,12,22,11,0,-10,100,80,55,101,33,23,0,2},Len = 15,min_indx,temp, i;
    
    for(i=0; i<Len; i++){
        min_indx = find_minimum(nums,i,Len-1);
        if(min_indx != i){
            temp = nums[i];
            nums[i] = nums[min_indx];
            nums[min_indx] = temp;
        }
    }
    
    for(i=0; i<Len; i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}

//find minimum value of an array of given range
int find_minimum(int ara[], int startIndx, int endIndx){
    int min_val_indx = startIndx, i;
    for(i=startIndx+1; i<=endIndx; i++){
        if(ara[i] < ara[min_val_indx]){
            min_val_indx = i;
        }
    }
    return min_val_indx;
}