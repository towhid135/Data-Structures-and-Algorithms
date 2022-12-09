
#include <bits/stdc++.h>
using namespace std;

int smaller_between_two(int number1, int number2);
int divide(int divisor, int dividend);
int gcd(int number1, int number2);
int main(){
    int result,num1=15,num2=5;
    result = gcd(num1,num2);
    cout<<result;
    return 0;
}

int smaller_between_two(int number1, int number2){
    return number1 < number2 ? number1 : number2;
}

int divide(int number1, int number2){
    int divisor,dividend,remainder,smaller;
    smaller = smaller_between_two(number1,number2);
    divisor = smaller;
    dividend = smaller == number1 ? number2 : number1; 

    return remainder = dividend % divisor;
}

int gcd(int number1, int number2){
    int remainder,smaller,result;
    if(number1 == 0 || number2 == 0) return number1+number2;
    smaller = smaller_between_two(number1, number2);
    remainder = divide(number1, number2);
    return result = gcd(smaller,remainder);
}