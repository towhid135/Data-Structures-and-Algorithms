#include <bits/stdc++.h>

using namespace std;

int sum(int n);
int main()
{
    int result;
    result = sum(5);
    cout<<result;

    return 0;
}

int sum(int n){
    if(n == 1) return 1;
    else return n + sum(n -1);
}