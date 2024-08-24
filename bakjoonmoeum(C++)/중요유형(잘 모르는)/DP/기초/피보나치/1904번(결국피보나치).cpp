#include <iostream>
using namespace std;

int dp[1000001];

int fib(int n){
    if(dp[n] != 0) return dp[n];
    if(n == 1) return 1;
    else if (n == 2) return 2;
    return dp[n] = (fib(n-1) + fib(n-2))%15746; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    cout << fib(N);
}
/*
N=1 1 1개
N=2 00 11 2개
N=3 001 100 111 3개
N=4 0000 0011 1100 1001 1111 5개
N=5 00001 00100 10000 00111 10011 11001 11100 11111 8개
N=6 000000 000011 001100 110000 100100 100001 001111 100111 110011 111001 111100 111111 13개
*/