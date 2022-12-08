#include <bits/stdc++.h>
using namespace std;

int partition(int ara[], int low, int high);
void print_ara(int ara[], int ara_size);
void quick_sort(int ara[], int low, int high);
int main(){
    int ara[] = {1,5,6,3,5,8,7,2,9}, low = 0, high = 8;
    quick_sort(ara,low,high);
    print_ara(ara,9);
    return 0;
}

int partition(int ara[], int low, int high){
    int pivot = ara[high];
    int swap_index = low, i, temp;

    //partition will happen from low to (high-1) of given array
    for(i = low; i < high; i++){
        if(ara[i] <= pivot){
           /*if i==swap_index that means the value already on its position.
           So, no need to swap just increase the swap_index because its a swap case.
           */
           if(i != swap_index){
                temp = ara[swap_index];
                ara[swap_index] = ara[i];
                ara[i] = temp;
           }
           swap_index++;
        }
    }

    temp = ara[swap_index];
    ara[swap_index] = ara[high];
    ara[high] = temp;

    return swap_index;
}

void quick_sort(int ara[], int low, int high){
    if(low >= high) return;
    int pivot_index;
    pivot_index = partition(ara,low,high);
    quick_sort(ara,low,pivot_index - 1);
    quick_sort(ara,pivot_index + 1,high);
    
}

void print_ara(int ara[], int ara_size){
    for(int i=0; i<ara_size; i++){
        cout<<ara[i]<<" ";
    }
}