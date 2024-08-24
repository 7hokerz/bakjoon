#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)
#define mod 1'000'000'009

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp;
ll ret = 0;
string str;
char arr[3001][3001];
ll dp[3001][3001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> arr[i][j];
        }
    }
    dp[N][M] = 1;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(i != 1){
                if(arr[i-1][j] == 'S' || arr[i-1][j] == 'B'){
                    dp[i][j] += dp[i-1][j] + 1;
                }
                dp[i][j] %= mod;
            }
            if(j != 1){
                if(arr[i][j-1] == 'E' || arr[i][j-1] == 'B'){
                    dp[i][j] += dp[i][j-1] + 1;
                }
                dp[i][j] %= mod;
            }
        }
    }
    
    cout << dp[N][M];
}
/*
for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cout << dp[i][j] << ' ';
        }cout << '\n';
    }

*/