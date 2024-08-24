#include <iostream>
#include <vector>
using namespace std;
int dp[101][10001];
vector <pair<int,int>> vt;
int N, T, K, S;

int calc(int pos, int weight){

    if(vt[pos-1].first <= weight){//공부 시간 이상인 경우
        dp[pos][weight] = max(dp[pos-1][weight], dp[pos-1][weight-vt[pos-1].first] + vt[pos-1].second);
        //단원을 공부하지 않는 경우, 공부하는 경우로 나뉨
    }else{//해당 단원을 공부한 시간이 부족한 경우
        dp[pos][weight] = dp[pos-1][weight];
    }
    return dp[pos][weight];
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T;
    for(int i = 0;i<N;i++){
        cin >> K >> S;
        vt.push_back({K,S});
    }
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<T+1;j++){
            calc(i,j);
        }
    }
    cout << dp[N][T];
}
/* 

*/