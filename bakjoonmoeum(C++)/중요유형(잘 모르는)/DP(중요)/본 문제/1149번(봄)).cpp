#include <iostream>
#include <stack>
using namespace std;

//요런 입력값이 존재하는 유형의 경우는 값을 dp에 받고 특정 조건을 만족하는 경우를 누적시키는 방향으로 보자.

int dp[1001][3];//빨초파

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 0;j<3;j++){
            cin >> input;
            dp[i][j] = input;
        }
    }
    //dp에 입력값을 받고 처음부터 탐색을 시작하는데, dp[i-1][dp[i]의 컬러 제외]의 값 중 더 작은 값을 더해준다.
    //즉 값이 누적된다. 자세히 보면 3개의 컬러에 대해 한 번에 탐색하는데 결국은 dp[i]에 올 수 있는 두 값중 작은 값을 받아들인다.
    for(int i = 2;i<N+1;i++){
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);//i에 빨간색
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);//i에 초록색
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);//i에 파란색을 칠할 경우
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}