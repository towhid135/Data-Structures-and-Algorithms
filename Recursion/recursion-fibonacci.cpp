#include <bits/stdc++.h>

using namespace std;
vector<long long int> mapFibo(100,0);

long long int fibo(long long int n);
int main()
{
    long long int result;
    result = fibo(50);
    cout<<result;
    return 0;
}
long long int fibo(long long int n){
    if(mapFibo[n] != 0) return mapFibo[n];
    else{
      if(n==1) return 0;
      else if(n == 2) return 1;
      else {
        mapFibo[n] = fibo(n-1) + fibo(n-2);
        return mapFibo[n];
      }
    }
}
