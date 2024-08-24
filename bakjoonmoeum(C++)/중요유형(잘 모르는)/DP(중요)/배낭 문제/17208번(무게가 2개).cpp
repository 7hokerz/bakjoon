#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int>> vt;
int N, M, K, x, y;
int dp[301][301];//치즈버거 개수, 감자튀김 개수
//값: 최대 처리 주문 수, 주문 중복 불가

void calc(int pos){
    for(int i = M;i>=vt[pos-1].first;i--){
        for(int j = K;j>=vt[pos-1].second;j--){
            dp[i][j] = max(dp[i][j], 1+dp[i-vt[pos-1].first][j-vt[pos-1].second]);
            //주문이 중복될 수 없으므로 M,K에서부터 순회했다. 또한 주문의 가치: 1로 모두 동일하므로 1을 더해줬다.
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0;i<N;i++){
        cin >> x >> y;
        vt.push_back({x,y});
    }
    for(int i = 1;i<N+1;i++){
        calc(i);
    }
    cout << dp[M][K];
}   
/*
무게로 잡히는 기준이 2개였기 때문에 좀 고민했었다.(하지만 처음으로 혼자 힘으로 풀었다!)
원래는 vt에 무게, 가치로 담았는데 여기서 중요한 점은 **주문의 가치는 1로 동일하다는 것이다.
*/