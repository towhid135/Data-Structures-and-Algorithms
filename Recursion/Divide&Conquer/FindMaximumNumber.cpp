//Find the maximum number of an array

/*
Recursive case: Divide the array untill gets a single element
Base case: If gets a single element then return it, because a single element is always
the maximum element of an array.
*/

#include <bits/stdc++.h>
using namespace std;

int check_maximum(int number1, int number2);
int divide_array(int array_size);
int find_maximum(int array[], int array_size);
int main(){
    int res;
    int array[] = {102,100,-1,101,1000,-10,2000}, array_size = 7;
    res = find_maximum(array,array_size);
    cout<<res;
    return 0;
}

int check_maximum(int number1, int number2){
    int maximum_number = number1 > number2 ? number1 : number2;
    return maximum_number;
}

int divide_array(int array_size){
    return array_size - 1;
}

int find_maximum(int array[], int array_size){
    int maximum;
    if(array_size <= 1) return array[array_size - 1];
    array_size = divide_array(array_size);
    
    maximum = find_maximum(array,array_size);

    return check_maximum(array[array_size], maximum);
}