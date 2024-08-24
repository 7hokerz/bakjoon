#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }\

int map[1001][3];//빨초파
int dp[3][1001][3];

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 0;j<3;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int j = 0;j<3;j++){
        memcpy(dp[j], map, sizeof(map));
        for(int i = 0;i<3;i++){
            if(i == j) continue;
            dp[j][1][i] = INF;
        }
        dp[j][2][j] = dp[j][N][j] = INF;

        for(int i = 2;i<N+1;i++){
            dp[j][i][0] += min(dp[j][i-1][1], dp[j][i-1][2]);
            dp[j][i][1] += min(dp[j][i-1][0], dp[j][i-1][2]);
            dp[j][i][2] += min(dp[j][i-1][0], dp[j][i-1][1]);
        }
    }
    int minn = INF;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            minn = min(minn, dp[i][N][j]);
        }
    }
    
    cout << minn;
}
/*
for(int j = 1;j<N+1;j++){
        cout << dp[0][j][0] << ' ' << dp[0][j][1] << ' ' << dp[0][j][2] << '\n';
    }cout << '\n';
    for(int j = 1;j<N+1;j++){
        cout << dp[1][j][0] << ' ' << dp[1][j][1] << ' ' << dp[1][j][2] << '\n';
    }cout << '\n';
    for(int j = 1;j<N+1;j++){
        cout << dp[2][j][0] << ' ' << dp[2][j][1] << ' ' << dp[2][j][2] << '\n';
    }cout << '\n';

dp[2][2] += dp[1][j];


26 INF INF
INF 86 83
INF 89+83 99+86

INF 40 INF
89 INF 97
110 INF 89+99

INF INF 83

dp[2][1] += dp[1][j];
dp[2][2] += dp[1][j];


*/