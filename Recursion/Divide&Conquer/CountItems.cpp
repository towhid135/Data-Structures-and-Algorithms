//Count total number of items of an array
/*
Recursive case: If the array has atleast one item then divide the array
Base case: If the array is empty then return 0, because we know the size of an empty array.
*/

#include <bits/stdc++.h>
using namespace std;

int divide_array(int array_size);
int increase_number(int number);
int count_items(int array[], int array_size);
int main(){
    int res;
    int array[] = {102,100,-1,101,1000,-10,0,10}, array_size = 8;
    res = count_items(array,array_size);
    cout<<res;

    return 0;
}

int divide_array(int array_size){
    return array_size - 1;
}

int increase_number(int number){
    return number + 1;
}

int count_items(int array[], int array_size){
    if(array_size == 0) return 0;
    int total_items;
    array_size = divide_array(array_size);

    total_items = count_items(array, array_size);

    return increase_number(total_items);
    
}