#include <iostream>
using namespace std;
/*
수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
부분 수열의 합을 구해야 한다.
이번에는 dp에 최대 합이 저장된다.
*/
int LBS(int n, int dp[], int inp[]){
    if(dp[n] == 0){
        dp[n] = inp[n];//inp[n]을 넣는 이유는 수열의 요소의 합이므로 1개가 있으면 그 수 자체가 합이 된다.

        for(int i = n-1;i>=0;i--){
            if(inp[i] < inp[n]){
                dp[n] = max(dp[n], LBS(i, dp, inp) + inp[n]);//자기자신을 포함한 최대 합
            }
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    int dp[n], inp[n];
    for(int i = 0;i<n;i++){
        cin >> input;
        inp[i] = input;
        dp[i] = 0;
    }
    for(int i = 0;i<n;i++){
        LBS(i, dp, inp);
    }
    int max = dp[0];
    for(int i = 1;i<n;i++){
        max = (dp[i]>max)?dp[i]:max;
    }
    cout << max;
}
