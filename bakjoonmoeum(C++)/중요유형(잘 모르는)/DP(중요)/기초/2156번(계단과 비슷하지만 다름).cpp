#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001], inp[10001];

/*
중요한 조건: 3번 연속으로 마실 수 없다.
**계단 조건과 다른 점: 얼마를 건너뛰어서 마실 지는 자유다. 계단으로 따지면 원하는 칸으로 한계 없이 올라갈 수 있다는 뜻
마찬가지로 초기값 설정을 해야한다.

2가지 경우가 존재(조건에 따라): 
1. 2연속으로 먹은 경우 >> 이 때는 현재 것과 그 전 것을 마셨다고 가정하고 n-3부터 재귀호출을 시작한다.
2. 2연속으로 먹지 않은 경우>> 이 때는 현재 것을 먹었다고 가정하고 n-2부터 재귀호출을 시작한다.
그 중 최댓값을 dp[n]에 저장하게 된다.
*/

int calc(int n){//n을 먹었다고 가정할 때이다.
    if(dp[n] != -1) return dp[n];//
    
    for(int i = n-3;i>=1;i--){
        dp[n] = max(dp[n], inp[n] + inp[n-1] + calc(i));
    }
    for(int i = n-2;i>=1;i--){
        dp[n] = max(dp[n], inp[n] + calc(i));
    }
    return dp[n];
}

int main(){
    fill(dp, dp+10001, -1);//0으로 초기화하면 값에도 0이 있는 경우 문제 발생.(없는 경우는 상관X)
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        inp[i] = input;
    }
    dp[1] = inp[1];
    dp[2] = inp[1] + inp[2];
    dp[3] = max(inp[1] + inp[3], inp[2] + inp[3]);
    for(int i = 1;i<N+1;i++) calc(i);
    int res = 0;
    for(int i = 1;i<N+1;i++){//dp[N]이 최댓값이 아닐 수 있으므로 비교한다.
        res = (dp[i]>res)?dp[i]:res;
        //cout << dp[i] << ' ';
    }
    cout << res;
}   
