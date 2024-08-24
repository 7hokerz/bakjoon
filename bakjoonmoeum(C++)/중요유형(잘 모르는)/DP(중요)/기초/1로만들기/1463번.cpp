#include <iostream>
using namespace std;
/*
처음 1부터 시작해 N까지 반복하면서 더 낮은 연산을 하는 경우를 저장한다.
*/
int dp[1000001];

int calc(int n){
    if(n==1) return 0;
    if(dp[n] != 0) return dp[n];

    dp[n] = dp[n-1]+1;
    if(n%3 == 0) dp[n] = min(dp[n],dp[n/3]+1);
    if(n%2 == 0) dp[n] = min(dp[n],dp[n/2]+1);
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 1;i<N+1;i++){
        calc(i);
    }
    cout << dp[N];
}
/*

*/