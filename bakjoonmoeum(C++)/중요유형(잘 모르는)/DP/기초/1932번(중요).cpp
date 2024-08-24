#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int dp[502][502];

int main(){
    fill(dp[0], dp[502], -1);
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<i+1;j++){
            cin >> input;
            dp[i][j] = input;
        }
    }

    for(int i = 1;i<N+1;i++){//바텀업 방식 구현
        for(int j = 0;j<i+1;j++){
            if(j==0) dp[i][j] += dp[i-1][j];
            else if(dp[i-1][j] != -1) dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
            else dp[i][j] += dp[i-1][j-1];
        }
    }

    int res = 0;
    for(int i = 0;i<N;i++){
        res = (dp[N-1][i]>res)?dp[N-1][i]:res;
        //cout << dp[N-1][i] << ' ';
    }
    cout << res;
}
/*
조건식
if(j==0) dp[i][j] = dp[i-1][j];
dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
if(dp[i-1][j] != -1)
*/