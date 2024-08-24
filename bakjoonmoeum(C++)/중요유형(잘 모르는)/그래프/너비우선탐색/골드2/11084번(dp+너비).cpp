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
#include <map>
#include <set>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 9'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \
//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}; int dy[] = {2, -2, 2 ,-2, 1, -1, 1, -1};

int N, M, visited[401][401], val = -1, accu[401][401];
queue <lpii> q;

void bfs(){
    visited[1][1] = accu[1][1] = 1;
    q.push({{1,1}, 1});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        
        q.pop();

        if(x == M && y == N && !visited[N][M]){
            visited[N][M] = cnt; continue;
        }
        if(visited[N][M] && cnt >= visited[N][M]) continue;
        
        //cout << x << ' ' << y << ' ' << cnt << '\n';

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx]){
                visited[ny][nx] = cnt + 1;
                accu[ny][nx] += accu[y][x] % mod; accu[ny][nx] %= mod;
                q.push({{nx,ny}, cnt + 1});
                continue;
            }

            if(visited[ny][nx] == cnt + 1){
                accu[ny][nx] += accu[y][x] % mod; accu[ny][nx] %= mod;
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    bfs();
    //printmap(N,M,visited); printmap(N,M,accu);
    if(accu[N][M] == 0) cout << "None";
    else cout << visited[N][M] - 1 << ' ' << accu[N][M] % mod;
}
/*
dp + 너비는 처음 풀어본다. 뭔가 참 신기한 조합이라고 생각함. dp + 깊이는 많이 풀어봤는데, 이건 좀 새로운 느낌이 든다.

처음엔 최단 거리를 구하고, 목표 지점에 도착한 것들 중 카운트가 같은 경우 개수를 더해 경우의 수를 구하면 된다 생각했지만, 당연히 시간초과지...

고민 끝에 생각해낸 건 역시 dp+깊탐과 비슷하게 accu 배열을 사용해 경우의 수를 매번 누적시켜주는 것이었다.

방문 배열은 카운트(최단 거리)를 세는 용도로 사용하고, accu는 경우의 수를 세는 용도로 사용하였다.

먼저 새로운 지점에 도착한 경우는 항상 최단 거리이므로, 이 때의 카운트를 기록하고 
추후에 이 지점에 도착하는 bfs중 카운트가 같은 경우만 경우의 수를 더해주었다.
어차피 카운트가 증가하는 순으로 bfs가 순환하므로 이런 식으로 더해줘도 문제 없다.

그리고 최초로 목표 지점에 도착할텐데 위와 같은 과정으로 경우의 수를 구별해서 세주면 답을 얻을 수 있다.

s 0 0 0
0 0 1 0
0 1 0 0
0 0 0 g(2)

1 0 0 0
0 0 2 0
0 2 0 0
0 0 0 g

s 0 0 0 0
0 0 1 2 0
0 1 0 0 0
0 0 0 0 g(3)

1 0 0 0 0
0 0 2 3 0
0 1 0 0 0
0 0 0 0 g

최단 거리(카운트)가 일치해야함.
*/
