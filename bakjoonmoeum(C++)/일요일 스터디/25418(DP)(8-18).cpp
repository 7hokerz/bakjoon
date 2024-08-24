#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, A, K, inp, ret = 0;

int dp[1'000'001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill(dp, dp+1'000'001, INF);
    cin >> A >> K;
    dp[A] = 0;

    for(int i = A + 1;i<K+1;i++){
        dp[i] = min(dp[i], dp[i-1] + 1);
        if(!(i % 2)) dp[i] = min(dp[i], dp[i/2] + 1);
    }
    cout << dp[K];
}
/*


*/