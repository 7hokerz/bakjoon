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
#define INF 2'000'000'001

int dx[] = {1,-1, 0, 0}; int dy[] = {0, 0, 1, -1};
int dx2[] = {1,1,-1,-1,2,2,-2,-2}; int dy2[] = {2,-2,2,-2,1,-1,1,-1};

int K, W, H, input, m[201][201], visited[201][201][31], res = -1;
queue <piiii> q;//x,y,cnt,K

void bfs(){
    if(m[1][1] == 0){
        q.push({{1,1},{0,0}});
        visited[1][1][0] = 1;
    }
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int Kcnt = q.front().second.second;
        
        q.pop();

        if(x == W && y == H){
            res = cnt;
            return;
        }

        for(int i = 0;i<8;i++){
            int nx = x + dx2[i];
            int ny = y + dy2[i];

            if(nx < 1 || ny < 1 || nx > W || ny > H) continue;

            if(m[ny][nx] == 0 && Kcnt + 1 <= K && (!visited[ny][nx][Kcnt + 1] || visited[ny][nx][Kcnt + 1] > cnt + 1)){
                visited[ny][nx][Kcnt + 1] = cnt + 1;
                q.push({{nx,ny},{cnt + 1, Kcnt + 1}});
            }
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > W || ny > H) continue;

            if(m[ny][nx] == 0 && (!visited[ny][nx][Kcnt] || visited[ny][nx][Kcnt] > cnt + 1)){
                visited[ny][nx][Kcnt] = cnt + 1;
                q.push({{nx,ny},{cnt + 1, Kcnt}});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> W >> H;
    for(int i = 1;i<H+1;i++){
        for(int j = 1;j<W+1;j++){
            cin >> input;
            m[i][j] = input;
        }
    }
    bfs();
    cout << res;
}
/*
K에 따른 3차원 배열을 만들어서 진행했다. 다만 K를 하는 경우와 하지 않는 경우에 대한
이동 기전이 다르므로 추가로 나이트 방향 배열을 만들어서 진행해야 한다.
먼저 도착한 bfs가 최단 거리이므로 바로 리턴해주면 된다.
*/