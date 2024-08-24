#include <iostream>
using namespace std;

int dp[1001];

int calc(int n){
    if(dp[n] != 0) return dp[n]%10007;
    if(n == 1) return 1;
    if(n == 2) return 2;
    dp[n] = dp[n-1]%10007+dp[n-2]%10007;
    return dp[n]%10007;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 1;i<n+1;i++){
        calc(i);
    }
    cout << dp[n]%10007;
}   
/*
1 1
2 2
3 3
4 5
5 8
6 13
7 21
8 34
9 55

*/