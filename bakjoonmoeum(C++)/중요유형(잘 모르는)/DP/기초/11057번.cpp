#include <iostream>
using namespace std;
int dp[10][1001];//0~9의 수, 자릿수

int calc(int num, int n){
    if(dp[num][n] != 0) return dp[num][n]%10007;
    for(int i = num;i>=0;i--){
        dp[num][n] += dp[i][n-1]%10007;
    }
    return dp[num][n]%10007;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<10;i++){
        dp[i][1] = 1;//1자릿수의 오르막 수는 무조건 1개
    }
    for(int j = 1;j<n+1;j++){
        for(int i = 0;i<10;i++){
            calc(i,j);
        }
    }
    int res = 0;
    for(int i = 0;i<10;i++){
        res += dp[i][n]%10007;
        res %= 10007;
    }
    cout << res;
}   
/*
쉬운 계단 수와 유사한 문제
*/