#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, K, xf, yf, xs, ys;
ll dp[102][102];

vector <t4> vt;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    
    for(int i = 1;i<K+1;i++){
        cin >> xf >> yf >> xs >> ys;
        vt.push_back({xf+1,yf+1,xs+1,ys+1});
        vt.push_back({xs+1,ys+1,xf+1,yf+1});
    }

    dp[1][1] = 1;

    for(int i = 1;i<N+2;i++){
        for(int j = 1;j<M+2;j++){
            if(i == 1 && j == 1) continue;

            bool chk = true;
            for(int k = 0;k<vt.size();k++){
                auto[xf, yf, xs, ys] = vt[k];
                if(xf == i && xs == i-1 && yf == j && ys == j){
                    chk = false; break;
                }
            }
            if(chk) dp[i][j] += dp[i-1][j];

            chk = true;
            for(int k = 0;k<vt.size();k++){
                auto[xf, yf, xs, ys] = vt[k];
                if(xf == i && xs == i && yf == j && ys == j - 1){
                    chk = false; break;
                }
            }
            if(chk) dp[i][j] += dp[i][j-1];
        }
    }
    
    cout << dp[N+1][M+1];
}
/*
점화식 자체는 쉽지만 갈 수 없는 도로 처리가 핵심이었던 문제.
갈 수 없는 도로에 대한 좌표도 도로는 다르나 좌표가 중복으로 주어질 수 있다는 점도 유의해야 함.

처음엔 4차원 배열로 해봤지만 역시나 메모리 초과...16MB 빡세지.
다음엔 벡터에 좌표를 담아서 매번 비교하는 방법으로 시도.
사실상 O(N^3)라서 좀 갸우뚱 했지만 N, M이 100이 최대라서 가능했던 듯.(최대 1'000'000 이니까?)


for(int i = 0;i<N+2;i++){
        for(int j = 0;j<M+2;j++){
            cout << dp[i][j] << ' ';
        }cout << '\n';
    }

dp[i][j] = dp[i-1][j] + dp[i][j-1];

if(visited[i][j] && visited[i-1][j])



*/