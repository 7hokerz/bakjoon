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

int N, res, startx, starty, w, h; string input;
int map[1006][1006]; bool visited[1006][1006];
queue <pair<pair<int,int>, int>> q;

void bfsfire(){  
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        visited[y][x] = true;

        q.pop();
        for(int k = 0;k<4;k++){
        
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 1 || ny < 1 || nx > w || ny > h) continue;
            if(!visited[ny][nx] && map[ny][nx] == -2){
                map[ny][nx] = time+1;
                visited[ny][nx] = true;
                q.push({{nx,ny},time+1});
            }
        }
    }
    fill(visited[0],visited[1001],0);
}

int bfs(){
    q.push({{startx,starty},0});
    visited[starty][startx] = true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        
        q.pop();
        
        for(int k = 0;k<4;k++){//갈 수 있는 방향에 대한 조사
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 1 || ny < 1 || nx > w || ny > h){//탈출 가능하면
                return time+1;
            }

            if(map[ny][nx] > time+1 || map[ny][nx] == -2){//벽이나 불이 아니고 방문하지 않은 경우
                if(!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({{nx,ny},time + 1});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int z = 0;z<N;z++){
        cin >> w >> h;
        int firecount = 0;

        for(int i = 1;i<h+1;i++){
            cin >> input;
            for(int j = 1;j<w+1;j++){
                if(input[j-1] == '.') map[i][j] = -2;
                
                else if(input[j-1] == '#') map[i][j] = -1;
                
                else if(input[j-1] == '*'){
                    q.push({{j,i},0}); firecount++;
                }
                else if(input[j-1] == '@'){
                    startx = j; starty = i; map[i][j] = -2;
                }
            }
        }
        if(firecount > 0) bfsfire();

        res = bfs();
        
        if(res == -1) cout << "IMPOSSIBLE" << '\n';
        else cout << res << '\n';

        fill(map[0],map[1005],0); fill(visited[0],visited[1005],0);
        while(!q.empty()) q.pop();
    }
}
/*
'.': 빈 공간 >> -2
'#': 벽 >> -1
'@': 상근이의 시작 위치 >> 시작 지점으로 설정
'*': 불 >> 너비우선탐색으로 시간 설정(단, 매번 퍼져나가는 형식)

조건: 
1.불이 옮겨진 칸, 옮겨질 칸으로 이동할 수 없음. 

for(int i = 1;i<h+1;i++){
    for(int j = 1;j<w+1;j++){
        cout << map[i][j] << ' ';
    }
    cout << '\n';
}
*/