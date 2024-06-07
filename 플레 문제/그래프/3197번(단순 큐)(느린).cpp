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
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 9'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, visited[1501][1501], day[1501][1501], stx = -1, sty, goalx, goaly, res = INF, maxday = 0;
char m[1501][1501];
string input;
queue <pii> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();//cout << x << ' ' << y << '\n';
        maxday = max(maxday, day[y][x]);
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] == 'X' && !day[ny][nx]){
                day[ny][nx] = day[y][x] + 1;
                q.push({nx,ny});
            }
        }
    }
}

void bfs2(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        if(x == goalx && y == goaly){
            res = min(res, visited[y][x]); continue;
        }
        if(res != INF && visited[y][x] >= res) continue;
        cout << x << ' ' << y << '\n';

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx] || visited[ny][nx] > visited[y][x]){
                int val = max(visited[y][x], day[ny][nx]);

                if(visited[ny][nx] && visited[ny][nx] <= val) continue;
                
                if(visited[y][x] == maxday) continue;

                visited[ny][nx] = val; q.push({nx,ny});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'L'){
                if(stx == -1){stx = j; sty = i;}
                else{goalx = j; goaly = i;}
            }
        }
    }
    
    for(int i = 1;i<N+1;i++){ 
        for(int j = 1;j<M+1;j++){
            if(m[i][j] == 'X'){
                for(int k = 0;k<4;k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

                    if(m[ny][nx] != 'X') {
                        q.push({j,i}); day[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    bfs(); //printmap(N, M, day);
    visited[sty][stx] = 1; q.push({stx, sty}); 
    bfs2();//printmap(N, M, visited);

    cout << res;
}
/*
첫 정답인 단순 큐 사용 풀이
우큐와 다른 점은 먼저 도달해도 최솟값이라는 보장이 없으므로 모든 도달하는 값을 확인하여 min을 출력한다는 것이다.
때문에 우큐 풀이보다 시간이 조금 더 걸린다.

4 11
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...

day 배열
00121000100
010121000L0
00001210010
10L00121000
*/
