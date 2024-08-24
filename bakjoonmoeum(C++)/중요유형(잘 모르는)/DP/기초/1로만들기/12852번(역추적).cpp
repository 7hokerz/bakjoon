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
typedef long long ll; typedef unsigned long long ull;
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
    }cout << '\n'; \

#define printmap3(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][0] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N;
int dp[1'000'001][2];

void calc(int n){
    if(dp[n][0] == 0){
        dp[n][0] = dp[n-1][0] + 1; 
        dp[n][1] = n-1;
        if(n % 2 == 0){
            if(dp[n/2][0] + 1 < dp[n][0]){
                dp[n][0] = dp[n/2][0] + 1;
                dp[n][1] = n/2;
            }
        }
        if(n % 3 == 0){
            if(dp[n/3][0] + 1 < dp[n][0]){
                dp[n][0] = dp[n/3][0] + 1;
                dp[n][1] = n/3;
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for(int i = 2;i<N+1;i++){
        calc(i);
    }
    cout << dp[N][0] << '\n';
    int num = N;
    while(num != 0){
        cout << num << ' ';
        num = dp[num][1];
    }
}
/*
원래 문제에서 역추적으로 모든 요소에 대해 출력하는 과정만 추가된 문제
*/