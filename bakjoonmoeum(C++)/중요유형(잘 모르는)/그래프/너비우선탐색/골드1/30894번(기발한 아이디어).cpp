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
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;
#define INF 0x7f7f7f7f7f7f7
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[select][i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {0, -1, 0, 1}; int dy[] = {1, 0, -1 ,0};

int N, M, res = -1, sx, sy, ex, ey;
bool can[4][201][201], visited[4][201][201];
char m[201][201];
queue <t3> q;

void bfs(){
    visited[0][sx][sy] = 1;
    q.push(make_tuple(sy,sx,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop(); //cout << y << ' ' << x << ' ' << cnt << '\n';
        
        if(x == ey && y == ex){res = cnt; return;}

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
            
            if(m[ny][nx] == '.' && !can[cnt % 4][ny][nx] && !visited[(cnt + 1) % 4][ny][nx]){
                visited[(cnt + 1) % 4][ny][nx] = 1;
                q.push(make_tuple(nx,ny,cnt + 1));
            }   
        }

        if(!can[cnt % 4][y][x] && !visited[(cnt + 1) % 4][y][x]){
            visited[(cnt + 1) % 4][y][x] = 1;
            q.push(make_tuple(x,y,cnt + 1));
        }
    }
}

void update(int num, int x, int y){
    for(int i = 0;i<4;i++){
        int nx = x + dx[num % 4];
        int ny = y + dy[num % 4];
        while(1){
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] != '.') break;
            
            can[i][ny][nx] = 1;
            nx += dx[num % 4]; ny += dy[num % 4];
        }
        num++;
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> sx >> sy >> ex >> ey;
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<M+1;j++)
            cin >> m[i][j];
        
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<M+1;j++)
            if(m[i][j] != '#' && m[i][j] != '.')update(m[i][j] - 48, j, i);
    
    bfs();
    
    if(res == -1) cout << "GG";
    else cout << res;
}
/*
주기가 4이고, 이를 이용한 나머지 연산을 이용하면 된다.
기발한 점은 현재 유령이 보는 지점이 아닌 다음 턴에 유령이 볼 지점을 표시해야 한다는 것이다.
*/