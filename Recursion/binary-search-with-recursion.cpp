/*
Recursive case: if ara[mid] != value and low <= high.
Base case: if ara[mid] == value then return or if low > high then return.
*/

#include <bits/stdc++.h>
using namespace std;

int mid(int left_index, int right_index);
int left(int mid_index);
int right(int mid_index);
void print_result(int result);
int binary_search(int ara[],int searched_value,int left_index, int right_index);
int main(){
    int ara[] = {1,2,3,4,5,6}, left_index = 0, right_index = 5, result, searched_value = 1;
    result = binary_search(ara,searched_value,left_index,right_index);
    print_result(result);
    return 0;
}

int mid(int left_index, int right_index){
    return (left_index + right_index) / 2;
}

int left(int mid_index){
    return mid_index + 1;
}

int right(int mid_index){
    return mid_index - 1;
}

int binary_search(int ara[],int searched_value,int left_index, int right_index){
    int result,mid_index;
    mid_index = mid(left_index,right_index);
    if(ara[mid_index] == searched_value) return mid_index;
    else if(left_index > right_index) return -1;
    else if( ara[mid_index] < searched_value ) left_index = left(mid_index);
    else right_index = right(mid_index);

    return result = binary_search(ara,searched_value,left_index, right_index);

}

void print_result(int result){
    bool found = result >= 0 ? true : false;
    if(found) cout<<"result found at index: "<<result;
    else cout<<"result not found!";
}