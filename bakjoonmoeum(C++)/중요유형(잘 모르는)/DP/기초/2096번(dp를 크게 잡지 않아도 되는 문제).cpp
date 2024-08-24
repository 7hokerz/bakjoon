#include <iostream>
using namespace std;
int dp[2][3];
int map[100001][3];

int calc(int n, int c, bool check, int i){
    if(!check){
        if(c == 0){
            dp[n][0] = max(dp[n-1][0],dp[n-1][1]) + map[i][0];
        }else if(c == 1){
            dp[n][1] = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) + map[i][1];
        }else if(c == 2){
            dp[n][2] = max(dp[n-1][1],dp[n-1][2]) + map[i][2];
        }
    }else{
        if(c == 0){
            dp[n][0] = min(dp[n-1][0],dp[n-1][1]) + map[i][0];
        }else if(c == 1){
            dp[n][1] = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])) + map[i][1];
        }else if(c == 2){
            dp[n][2] = min(dp[n-1][1],dp[n-1][2]) + map[i][2];
        }
    }
    return dp[n][c];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, input;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    if(n==1){//줄이 1일 때는 0 0만 출력되므로 한 줄의 최대 최소를 직접 출력해주어야 한다.
        cout << max(map[0][0], max(map[0][1], map[0][2])) << ' '
        << min(map[0][0], min(map[0][1], map[0][2]));
        return 0;
    }
    dp[0][0] = map[0][0]; dp[0][1] = map[0][1]; dp[0][2] = map[0][2];
    for(int i = 1;i<n;i++){//최댓값
        for(int j = 0;j<3;j++){
            calc(1, j, false, i);
        }
        dp[0][0] = dp[1][0]; dp[0][1] = dp[1][1]; dp[0][2] = dp[1][2];//한 칸 내리기
    }
    int res1 = 0;
    for(int i = 0;i<3;i++){
        res1 = (dp[1][i]>res1)?dp[1][i]:res1;
    }

    dp[0][0] = map[0][0]; dp[0][1] = map[0][1]; dp[0][2] = map[0][2];
    for(int i = 1;i<n;i++){//최솟값
        for(int j = 0;j<3;j++){
            calc(1, j, true, i);
        }
        dp[0][0] = dp[1][0]; dp[0][1] = dp[1][1]; dp[0][2] = dp[1][2];
    }
    int res2 = 100000000;
    for(int i = 0;i<3;i++){
        res2 = (dp[1][i]<res2)?dp[1][i]:res2;
    }
    cout << res1 << ' ' << res2;
}   
/*
메모리 제한 때문에 dp를 넓게 잡고 풀 수 없다.
대신 dp[2]로만 잡고 dp를 한 칸씩 내리는 방식으로 풀면 순조롭게 풀 수 있다.

최대 최소 때문에 나눠서 계산하느라고 풀이가 길어졌는데, 다른 풀이는 짧게 푸는 것도 많았다.
어떤 변수에다가만 값을 저장시키면 이런 식으로 길게 쓸 필요가 없음.
*/