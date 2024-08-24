#include <iostream>
using namespace std;
int dp[15];//최대15일째의 가능한 최대를 구하고, 이 중 최대를 찾는다.
int map[15][2];//Ti, Pi

int calc(int n){
    if(dp[n] != 0) return dp[n];
    for(int i = n-1;i>=0;i--){
        if(n-i >= map[i][0]){//처음엔 ==로, 끝나는 날에 대해서만 넣었지만, 예제4를 및 질게를 참고하여 여유가 있는 경우에도 선택할 수 있도록 하였다.
            dp[n] = max(dp[n], map[i][1]+dp[i]);
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, input;
    dp[0] = 0;//1일째에는 할 수 있는 게 없음.
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input;
        map[i][0] = input;
        cin >> input;
        map[i][1] = input;
    }
    for(int i = 1;i<n+1;i++) calc(i);
    int res = 0;
    for(int i = 1;i<n+1;i++){
        res = (dp[i]>res)?dp[i]:res;
        //cout << dp[i] << ' ';
    }
    cout << res;
}   
/*
map 배열에는 주어지는 Ti와 Pi를 각각 대입하였고, dp배열에는 최대 가능한 Pi의 합을 저장한다.
중요한 것은 n일까지가 아닌 n+1일 까지의 Pi합도 구해야 한다. 왜냐하면 N+1일째에 끝나는 상담은 유효하기 때문
**그리고 상담은 자기가 원할 때 선택할 수 있으므로, 상담이 끝났다고 반드시 선택할 필요는 없다.
(예제 4가 그러하다.)
*/