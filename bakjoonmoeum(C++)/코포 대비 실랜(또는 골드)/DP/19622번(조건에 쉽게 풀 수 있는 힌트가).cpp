#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, inp, ret = 0;
int dp[2][100'001];//0: 한 경우, 1: 안 한 경우
vector <int> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        int s, e, n;
        cin >> s >> e >> n;
        vt.push_back(n);
    }
    dp[0][1] = vt[0];
    dp[0][2] = vt[1];
    dp[1][2] = dp[0][1];

    for(int i = 3;i<N+1;i++){
        dp[0][i] = max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2])) + vt[i-1];
        dp[1][i] = max(dp[0][i-1], max(dp[1][i-2], dp[0][i-2]));
    }
    cout << max(dp[0][N], dp[1][N]);
}

/*
임의의 회의 K(1 ≤ K ≤ N)는 회의 K − 1과 회의 K + 1과는 회의 시간이 겹치고 다른 회의들과는 회의 시간이 겹치지 않는다.


*/