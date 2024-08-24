#include <iostream>
#include <vector>
using namespace std;
int N, K, I, T;
int dp[10001];
vector <pair<int,int>> vt;//중요도, 공부시간

void calc(int pos){
    for(int i = N;i >= vt[pos-1].second;i--){
        dp[i] = max(dp[i], vt[pos-1].first + dp[i - vt[pos-1].second]);
        //pos의 공부를 하게되었을 때와 하지 않았을 때의 값중 더 큰 값
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0;i<K;i++){
        cin >> I >> T;
        vt.push_back({I,T});//중요도, 공부시간
    }
    for(int i = 1;i<K+1;i++){
        calc(i);
    }
    cout << dp[N];
}
/*
과목은 중복되지 않으므로 뒤에서부터 해당 T까지 순회
*/