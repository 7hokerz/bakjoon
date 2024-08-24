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
    for (int i = 0; i < (row) + 1; i++){   \
        for (int j = 0; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {0, -1, 0, 1}; int dy[] = {1, 0, -1 ,0};

int N, M, res = -1, A1x, A2x, B1x, B2x, A1y, A2y, B1y, B2y;
int maxx, minx, maxy, miny;
int visited[102][102][2];

queue <t3> q2;

void bfs2(int stx, int sty, int gox, int goy, int nstx, int nsty, int ngox, int ngoy){
    visited[sty][stx][1] = 0;
    q2.push(make_tuple(stx,sty,0));
    
    while(!q2.empty()){
        int x = get<0>(q2.front());
        int y = get<1>(q2.front());
        int cnt = get<2>(q2.front());
        
        q2.pop();

        if(x == gox && y == goy){
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx > N || ny > M) continue;
            if((nx == nstx && ny == nsty) || (nx == ngox && ny == ngoy)) continue;
            
            if(visited[ny][nx][1] == -1){//2 5 1 4 2<=y<=3 3<=x<=4, 
                //cout << y << ' ' << x << ' ' << ny << ' ' << nx << "  ";
                //cout << miny << ' ' << maxy << ' ' << minx << ' ' << maxx << '\n';
                if(!((x > minx && x < maxx) && (y > miny && y < maxy)) && (nx > minx && nx < maxx) && (ny > miny && ny < maxy)){
                    if(cnt == 1) continue;
                    visited[ny][nx][1] = visited[y][x][1] + 1;
                    q2.push(make_tuple(nx,ny,cnt + 1));
                }
                else if(!((nx > minx && nx < maxx) && (ny > miny && ny < maxy)) && (x > minx && x < maxx) && (y > miny && y < maxy)){
                    if(cnt == 1) continue;
                    visited[ny][nx][1] = visited[y][x][1] + 1;
                    q2.push(make_tuple(nx,ny,cnt + 1));
                }
                else{
                    visited[ny][nx][1] = visited[y][x][1] + 1;
                    q2.push(make_tuple(nx,ny,cnt));
                }
            } 
        }
    }
}

queue <pii> q;

void bfs(int stx, int sty, int gox, int goy, int nstx, int nsty, int ngox, int ngoy){
    if(stx > gox){maxx = stx; minx = gox;}
    else{maxx = gox; minx = stx;}

    if(sty > goy){maxy = sty; miny = goy;}
    else{maxy = goy; miny = sty;}

    visited[sty][stx][0] = 0;
    q.push({stx,sty});

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        
        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < minx || ny < miny || nx > maxx || ny > maxy) continue;
            if((nx == nstx && ny == nsty) || (nx == ngox && ny == ngoy)) {
                continue;
            }
            if(visited[ny][nx][0] == -1){
                visited[ny][nx][0] = visited[y][x][0] + 1;
                q.push({nx,ny});
            } 
        }
    }
    bfs2(nstx, nsty, ngox, ngoy, stx, sty, gox, goy);
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill_n(&visited[0][0][0], 102*102*2, -1);
    cin >> N >> M;//x,y
    cin >> A1x >> A1y >> A2x >> A2y >> B1x >> B1y >> B2x >> B2y; 
    bfs(A1x, A1y, A2x, A2y, B1x, B1y, B2x, B2y);
    printmap3(M, N, 0, visited);
    printmap3(M, N, 1, visited);

    if(visited[B2y][B2x][1] != -1) res = visited[A2y][A2x][0] + visited[B2y][B2x][1];
    cout << res << '\n';

    fill_n(&visited[0][0][0], 102*102*2, -1); 
    while(!q2.empty()) q2.pop();
    bfs(B1x, B1y, B2x, B2y, A1x, A1y, A2x, A2y);
    printmap3(M, N, 0, visited);
    printmap3(M, N, 1, visited);

    if(visited[A2y][A2x][1] != -1) res = visited[A2y][A2x][1] + visited[B2y][B2x][0];
    cout << res << '\n';
    

}
/*
중요한 점은 가로지르면 안된다는 것이다.

*/