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
#define INF 1'999'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }\

int N, dp[100001][3];//0: 넣지 않는 경우, 1: 넣는 경우

void calc(){
    for(int i = 2;i<N+1;i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][2]; dp[i][0] %= 9901;
        dp[i][1] = dp[i-1][0] + dp[i-1][2]; dp[i][1] %= 9901;
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2]; dp[i][2] %= 9901;
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1; 
    calc();
    /*for(int i = 1;i<N+1;i++){
        cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
    }*/
    int sum = 0;
    for(int i = 0;i<3;i++){
        sum += dp[N][i]; sum %= 9901;
    }
    cout << sum;
}
/*
xo ox xx 의 3가지 경우가 존재한다.

*/