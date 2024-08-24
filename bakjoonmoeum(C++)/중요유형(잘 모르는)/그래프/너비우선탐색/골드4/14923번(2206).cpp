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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//북,동,남,서 총 4 방향 탐색
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int N, M, stx, sty, goalx, goaly, input;
int visited[1001][1001][2], map[1001][1001];

void bfs(int stx, int sty){
    queue <pair<pair<int,int>,int>> q;
    q.push({{stx,sty},0});
    visited[sty][stx][0] = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        //cout << y << ' ' << x << '\n';
        if(x == goaly && y == goalx){
            cout << visited[goalx][goaly][wall] << '\n'; 
            return;
        }

        q.pop();

        for(int k = 0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(visited[ny][nx][wall] == 0 && map[ny][nx] == 0){
                visited[ny][nx][wall] = visited[y][x][wall] + 1;
                q.push({{nx,ny},wall});
            }

            if(wall == 0 && map[ny][nx] == 1){
                visited[ny][nx][wall + 1] = visited[y][x][wall] + 1;
                q.push({{nx,ny},wall + 1});
            }
        }
    }
    cout << -1;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> stx >> sty >> goalx >> goaly;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    bfs(sty,stx);
}
/*
2206과 다른 점: 시작 지점과 끝 지점이 다름.
for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cout << visited[i][j][0] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cout << visited[i][j][1] << ' ';
        }
        cout << '\n';
    }
*/