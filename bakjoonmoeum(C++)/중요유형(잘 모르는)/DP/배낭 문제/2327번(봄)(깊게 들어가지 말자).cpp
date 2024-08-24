#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H, N, h, s;
vector <pair<int,int>> vt;//학생의 키, 달리기 속도
int dp[100001];//키 높이

void calc(int pos){
    for(int i = H;i>=vt[pos-1].first;i--){
        //min(달리기 속도, 현재 학생의 키를 빼고 남은 키 중 dp값)(더해서 누적시키지 않음)
        dp[i] = max(dp[i], min(vt[pos-1].second, dp[i-vt[pos-1].first]));
    }
}

int main(){
    fill(dp, dp+100001, 0);
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> H >> N;
    dp[0] = 100001;//이거 중요. min값을 정상적으로 구하려면 필요한 듯 하다.
    for(int i = 0;i<N;i++){
        cin >> h >> s;
        vt.push_back({h,s});
    }
    for(int i = 1;i<N+1;i++){
        calc(i);
    }
    for(int i = 1;i<N+1;i++){
        cout << dp[i] << ' ';
    }
    cout << dp[H];
}   
/*
출전 팀 구성원들의 키를 모두 더했을 때 정확히 H가 되어야 한다는 조건이 내 발목을 잡았다.
그럼 이거 경우의 수를 구하고 그 조합들에 대한 가장 느린 사람의 달리기 속도를 구해야 하나? 싶었다.

그렇게 깊게 생각할 필요는 없었다. 다른 분이 도움을 주셨다.

그냥 일반적인 배낭 문제처럼 비슷하게 하지만,
구성원 중 달리기 속도가 가장 느린 사람이 가장 빠르게 되도록 팀을 선발해야 한다는 게 있었다.

dp 값에 키의 합이 H가 아닌 경우도 들어갈 수 있는 거 아냐?라는 걱정을 할 필요가 없다.
결국 dp[i-vt[pos-1].first]를 쓰면 키 높이가 h인 경우에서 현재 검사중인 요소의 키를 빼고 나머지 i-h의 키가 될 수 있는 것들 중의
최대값으로 접근하기 때문이다.

여기서 결국 구해야 하는 건 구성원 중 최소 속도인 경우에서 그 중 최대가 되는 경우를 구해야 하는 것이므로
dp[i] = max(dp[i], min(vt[pos-1].second, dp[i-vt[pos-1].first]));라는 공식이 완성된다.

dp[0] = 100001인 이유? 사실 100000만 넘으면 아무 문제 없다. h의 최댓값이 10만이기 때문

생각해보면 처음 구할 때 i-vt[pos-1].first = 0에 도달할 것이고 이때 최소를 구해야 하는데
min을 구하니까 어떻게 보면 원리는 잘 모르겠지만 필연적인 식이다.
*/