#include <iostream>
using namespace std;

long long dp[91];

long long calc(long long n){
    if(dp[n] != 0) return dp[n];
    if(n==0) return 0;
    if(n==1) return 1;
    else dp[n] = calc(n-1) + calc(n-2);
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    cout << calc(n);
}   
/*
1 1 1 
2 10 1
3 100 101 2
4 1000 1001 1010 3
5 10000 10001 10010 10100 10101 5
*/