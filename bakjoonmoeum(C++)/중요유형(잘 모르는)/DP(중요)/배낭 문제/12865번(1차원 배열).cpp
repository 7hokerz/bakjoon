#include <iostream>
#include <vector>
using namespace std;
int n, k, w, v;

int dp[100001];
vector <pair<int,int>> vt;

void calc(int pos){
    for(int i = k;i>=vt[pos-1].first;i--){
        dp[i] = max(dp[i], dp[i - vt[pos-1].first] + vt[pos-1].second);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cin >> n >> k;
        for(int i = 0;i<n;i++){
            cin >> w >> v;
            vt.push_back({w,v});
        }

        for(int i = 1;i<n+1;i++){
            calc(i);
        }
        cout << dp[k];
}
/*
맨 뒤에서부터 해당 무게인 first까지 순환한다.
2차원과 다르게 앞에서부터 순회하면 안되는 이유는 현재 조건에 따라 물건은 1개만 쓸 수 있는데,
계속 누적이 되는 문제가 있기 때문이다.

뒤에서부터 w까지만 순환하면 자기자신을 건드리지 않는다는 것이다. << 중요
요약: 한 물건을 중복하여 쓸 수 없는 경우 뒤에서부터 순회하면 중복이 되지 않는다.
*/