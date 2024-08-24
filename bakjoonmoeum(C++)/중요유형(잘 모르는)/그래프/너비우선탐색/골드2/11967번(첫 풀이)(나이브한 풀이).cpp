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
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int M, N, x, y, a, b, can[101][101], visited[101][101][10001], maxcnt = 0;
//can이 1이면 켜진 상태, 아니면 X, visited의 3차원은 불의 총 켜진 개수
vector <pii> light[101][101];
queue <t3> q;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());

        q.pop(); //cout << y << ' ' << x << '\n';

        if(cnt < maxcnt) continue;

        for(int i = 0;i<light[y][x].size();i++){
            int nx = light[y][x][i].first;
            int ny = light[y][x][i].second;
            if(!can[ny][nx]){
                can[ny][nx] = 1;
                cnt++;
            }
        }
        maxcnt = max(maxcnt, cnt);

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            
            if(!visited[ny][nx][cnt] && can[ny][nx]){
                visited[ny][nx][cnt] = 1;
                q.push(make_tuple(nx,ny,cnt));
            }
        }
    }
    
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> x >> y >> a >> b;
        light[y][x].push_back({a, b});
    }
    can[1][1] = 1;
    q.push(make_tuple(1,1,1));
    bfs();
    cout << maxcnt;
}
/*

*/