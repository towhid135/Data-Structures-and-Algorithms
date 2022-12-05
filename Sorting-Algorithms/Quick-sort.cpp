#include <bits/stdc++.h>
using namespace std;

void partition(int ara[], int low, int high);
void print_ara(int ara[], int ara_size);
int main(){
    int ara[] = {2,9,4,4,4}, low = 0, high = 4;
    partition(ara,low,high);
    print_ara(ara,5);
    return 0;
}

void partition(int ara[], int low, int high){
    int pivot = ara[high];
    int swap_index = low, i, temp;

    for(i = 0; i < high; i++){
        if(ara[i] < pivot){
            temp = ara[swap_index];
            ara[swap_index] = ara[i];
            ara[i] = temp;

            swap_index++;
        }
    }

    temp = ara[swap_index];
    ara[swap_index] = ara[high];
    ara[high] = temp;
}

void print_ara(int ara[], int ara_size){
    for(int i=0; i<ara_size; i++){
        cout<<ara[i]<<" ";
    }
}