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
priority_queue<rpii, vector<rpii>, greater<rpii>> pq;

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
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cnt = pq.top().first;
        
        pq.pop();

        if(x == goalx && y == goaly){
            res = visited[y][x]; return;
        }
        if(res != INF && visited[y][x] >= res) continue;
        //cout << x << ' ' << y << '\n';

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx] || visited[ny][nx] > visited[y][x]){
                int val = max(visited[y][x], day[ny][nx]);
                if(visited[ny][nx] && visited[ny][nx] <= val) continue;

                visited[ny][nx] = val; pq.push({val,{nx,ny}});
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
    visited[sty][stx] = 1; pq.push({1,{stx, sty}}); 
    bfs2();//printmap(N, M, visited);

    cout << res;
}
/*
pq를 이용한 풀이가 내가 할 수 있는 선에서 최대로 시간을 줄이는 방법 같다.

과정:
1. 우선 물에 인접하는 모든 X를 큐에 삽입한다.
이때 day배열은 해당 블록이 없어질 때까지의 날짜이다.

2. 모든 X를 탐색하여 day배열에 날짜를 기록한다.

3. 시작점을 한 개 잡고, bfs를 돌린다.
이때 pq를 사용하는데, 걸리는 날은 최소가 되야 하므로 최솟값을 우선적으로 검사하기 위해서이다.

4. day의 값을 확인하여 visited에 삽입하는데, 이때 max 조건을 두어 목표 지점에 도착할 때까지 최댓값이 유지되도록 한다.

5. pq를 통해 최소 날짜가 우선적으로 검사되므로 목표지점에 도착하면 바로 리턴하면 된다.


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
