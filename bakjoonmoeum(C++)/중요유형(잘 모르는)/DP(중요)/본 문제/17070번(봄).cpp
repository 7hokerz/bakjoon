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

//1차원 dist배열 출력
#define printdist1(N, dist)     \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k] << ' ';    \
    }cout << '\n';  \

//2차원 dist배열 출력(2차원 원소는 num으로 선택)
#define printdist2(N, dist, num)   \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k][num] << ' ';     \
    }cout << '\n';  \


int map[17][17], N, inp, dp[17][17][4];//1 == 가로, 2 == 세로, 3 == 대각선
//값: 경우의 수(방향에 따른)

void calc(){
    for(int i = 1;i<N+1;i++){
        for(int j = 3;j<N+1;j++){
            if(map[i][j] == 0){
                if(i == 1 && j == 2) continue;
                dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][3];
                dp[i][j][2] = dp[i-1][j][2] + dp[i-1][j][3];

                if(map[i-1][j] != 1 && map[i][j-1] != 1){
                    dp[i][j][3] = dp[i-1][j-1][3] + dp[i-1][j-1][2] + dp[i-1][j-1][1];
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> inp;
            map[i][j] = inp;
        }
    }
    dp[1][2][1] = 1;
    calc();
    
    cout << dp[N][N][1] + dp[N][N][2] + dp[N][N][3];
}
/*
dp값에는 모든 방향에 따라 올 수 있는 값을 저장한다.
상태에 따라 값이 달라진다.

경우의 수를 여러가지로 나눌 수 있음.
가로, 세로, 대각선

[i][j][1]: 현재 상태가 가로이고, 올 수 있는 경우의 수
>> [i][j-1][1](한 칸 앞 가로 상태였던 것) + [i][j-1][3](한칸 앞 대각선 상태였던 것)
*/
/*
for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << dp[i][j][1] << ' ';
        }cout << '\n';
    }cout << '\n';
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << dp[i][j][2] << ' ';
        }cout << '\n';
    }cout << '\n';
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << dp[i][j][3] << ' ';
        }cout << '\n';
    }cout << '\n';



*/