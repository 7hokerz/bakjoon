#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[41][2];//각각 0과 1이 호출되는 횟수를 저장

int calc(int n, int i){
    if(dp[n][i] != 0) return dp[n][i];
    
    if(n == 0){
        if(i == 0) return dp[n][i];
        else return 0;
    }
    if(n == 1){
        if(i == 1) return dp[n][i];
        else return 0;
    }
    dp[n][i] = dp[n-1][i] + dp[n-2][i];
    return dp[n][i];
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0][0] = 1;
    dp[1][1] = 1;
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        for(int i = 0;i<n+1;i++){
            calc(i,0);
            calc(i,1);
        }
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }
}   
/*

*/