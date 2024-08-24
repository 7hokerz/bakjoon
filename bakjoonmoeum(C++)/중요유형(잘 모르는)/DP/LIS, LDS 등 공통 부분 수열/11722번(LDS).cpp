#include <iostream>
using namespace std;

int LDS(int n, int dp[], int inp[]){
    if(dp[n] == 0){
        dp[n] = 1;
        
        for(int i = n-1;i>=0;i--){
            if(inp[i] > inp[n]){//감소하는 부분 수열이므로 연산자만 바꾸면 정답
                dp[n] = max(dp[n], LDS(i, dp, inp) + 1);
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
        LDS(i, dp, inp);
    }

    int max = dp[0];
    for(int i = 1;i<n;i++){
        max = (dp[i]>max)?dp[i]:max;
    }
    cout << max;
}
