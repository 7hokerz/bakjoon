#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp, ret = 0;

vector <pii> vt;

long double dp[1001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    int x, y;
    for(int i = 1;i<N+1;i++){
        cin >> x >> y;
        vt.push_back({x,y});
    }
    sort(vt.begin(), vt.end());

    for(int i = 0;i<N;i++){
        for(int j = i-1;j >= 0;j--){
            ll xd = vt[i].first - vt[j].first;
            if(!xd) continue;
            
            ll yd = vt[i].second - vt[j].second;
            double d = sqrt(xd * xd + yd * yd);  
            
            dp[i] = max(dp[i], dp[j] + d);
        }
    }
    long double ret = 0.0;
    for(int i = 0;i<N;i++){
        ret = max(ret, dp[i]);
    }
    cout << fixed << setprecision(10);
    cout << ret;
}
/*
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1

1 1 
1 3
3 1
3 3
5 1
5 3

x좌표가 반드시 증가하는 순서대로 이어야 한다.
*/