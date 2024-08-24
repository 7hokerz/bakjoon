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

int N, M, visited[51][51], accu[51][51][2];
string input;
char map[51][51];

void dfs(int x, int y){
    if(map[y][x] == 'H') return;
    
    for(int i = 0;i<4;i++){
        int nx = x + dx[i] * (map[y][x] - 48);
        int ny = y + dy[i] * (map[y][x] - 48);

        if(accu[y][x][0] + 1 <= accu[ny][nx][0]) continue;

        if(nx < 1 || ny < 1 || nx > M || ny > N) {
            accu[y][x][1] = 1; continue;
        }

        if(!visited[ny][nx]){
            visited[ny][nx] = 1;

            accu[ny][nx][0] = accu[y][x][0] + 1;

            dfs(nx,ny);

            visited[ny][nx] = 0;
        }
        else{
            cout << -1; exit(0);
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            map[i][j] = input[j-1];
        }
    }
    visited[1][1] = 1;
    dfs(1,1);
    //printmap(N, M, map); 
    //printmap3(N, M, accu); 
    int maxnum = 0;
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<M+1;j++)
            maxnum = max(maxnum, accu[i][j][0] + accu[i][j][1]);
        
    cout << maxnum;
}

/*

*/