// Find out the sum of all element of an array

/*
Recursive case: If array has more than zero element then divide it
Base case: If array has zero element return zero, because sum of all element is zero when 
size of array is zero.
*/

#include <bits/stdc++.h>
using namespace std;

int divide_array(int array_size);
int add_two_numbers(int number1, int number2);
int sumOfAllElement(int array[], int array_size);
int main(){
    int res;
    int array[] = {1,2}, array_size = 2;
    res = sumOfAllElement(array,array_size);
    cout<<res;
    return 0;
}

int divide_array(int array_size){
    return array_size - 1;
}

int add_two_numbers(int number1, int number2){
    return number1 + number2;
}

int sumOfAllElement(int array[], int array_size){
    if(array_size == 0) return 0;
    array_size = divide_array(array_size);
    int result = sumOfAllElement(array, array_size);
    // cout<<endl<<" return: "<<result<<endl;
    return add_two_numbers(array[array_size], result);
    return 0;
}