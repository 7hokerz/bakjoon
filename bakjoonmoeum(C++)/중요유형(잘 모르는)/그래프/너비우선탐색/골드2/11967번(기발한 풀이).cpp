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
int M, N, x, y, a, b, can[101][101], visited[101][101], maxcnt = 1;
//can이 1이면 켜진 상태, 아니면 X, visited의 3차원은 불의 총 켜진 개수
vector <pii> light[101][101];//현 좌표에서 킬 수 있는 스위치
queue <pii> q;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());

        q.pop();

        for(int i = 0;i<light[y][x].size();i++){//스위치 탐색(불 켜기)
            int nx = light[y][x][i].first;
            int ny = light[y][x][i].second;

            if(!can[ny][nx]){//불을 킨 적이 없다면
                can[ny][nx] = 1;
                maxcnt++;
                //불이 켜진 위치에서 4방향 탐색(즉, 4방향 탐색하여 갈 수 있는 길이 존재하는지 확인)
                for(int k = 0;k<4;k++){
                    int nnx = nx + dx[k];
                    int nny = ny + dy[k];

                    if(nnx < 1 || nny < 1 || nnx > N || nny > N) continue;

                    if(visited[nny][nnx]){//이전에 이 곳과 인접한 칸에 방문한 적 있으면(거기서 올 수 있다는 뜻)
                        q.push({nnx,nny});
                    }
                }
            }
        }

        for(int i = 0;i<4;i++){//갈 수 있는 곳 탐색
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            
            if(!visited[ny][nx] && can[ny][nx]){//불이 켜져있고 방문한 적 없으면
                visited[ny][nx] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> y >> x >> b >> a;
        light[y][x].push_back({a, b});
    }
    visited[1][1] = 1;
    can[1][1] = 1;
    q.push({1,1});
    bfs();
    //printmap(N,N,can);
    cout << maxcnt;
}
/*
신박한 풀이 방법(다른 풀이 참고)(풀긴 했으나 시간이 많이 걸린 거 같아 참고함)

처음에는 3차원 배열로 불 카운트를 잡고 풀었는데, 시간이 다른 사람에 비해 너무 많이 걸렸다.

내 풀이와 다른 점
불을 키는 데 그치지 않고, 불이 켜진 곳의 주변 4방향을 탐색한다.
그리고 방문한 적이 있는 곳이 존재하면 큐를 해당 방향으로 삽입한다.

나머지의 경우 불이 켜져 있고 방문한 적이 없는 경우가 존재하는 곳에 대한 풀이는 똑같았다.

위의 풀이가 통하는 이유? 불이 켜졌지만 주변에 방문 흔적이 없다고 쳐도,
나중에 갈 수 있는 길이라 방문 가능하기 때문.
어차피 갈 수 있는 길만 가기 때문이다.

내 풀이가 시간이 많이 걸린 건 카운트가 1번 갱신될 때마다 방문 배열이 초기화되는 효과를 가지므로,
다시 모든 곳을 탐색하기 때문에 오래 걸리는 것이다.
*/