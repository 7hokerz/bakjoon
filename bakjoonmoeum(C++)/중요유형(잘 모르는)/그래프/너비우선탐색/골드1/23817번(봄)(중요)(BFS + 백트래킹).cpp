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

int N, M, stx, sty, nodenum = 50, res = -1;
bool visited[1001][1001], nodevis[22][22], vis[22];
char m[1001][1001];
vector <pii> gr[22], loc;//시작점 및 모든 K
queue <t3> q;//x,y,cnt

//시작지점(S,K)에 대한 서로 다른 K에 대해 연결 및 최단 거리 저장
void bfs(int node){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());//이동 횟수

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == 'X') continue;

            if(!visited[ny][nx]){
                if(m[ny][nx] != '.'){//K만 통과하게 됨
                    int nnode;
                    if(m[ny][nx] - 48 < 10) nnode = m[ny][nx] - 48;//숫자
                    else nnode = m[ny][nx] - 65 + 10;//대문자
                    
                    if(!nodevis[node][nnode]){//정점 연결 및 방문 처리
                        gr[node].push_back({nnode, cnt + 1});
                        gr[nnode].push_back({node, cnt + 1});
                        nodevis[node][nnode] = 1; nodevis[nnode][node] = 1;
                    }
                }
                visited[ny][nx] = 1;
                q.push(make_tuple(nx,ny,cnt + 1));
            }
        }
    }
}
//S에서 출발하여 모든 K에 대해 백트래킹 하여 최단 시간 계산
void dfs(int x, int cost, int cnt){
    if(cnt == 5){//cout << cost << '\n';
        if(res == -1) res = cost;
        else res = min(res, cost);
        return;
    }

    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int ncost = gr[x][i].second;

        if(res != -1 && cost + ncost >= res) continue;

        if(!vis[nx]){
            vis[nx] = 1;
            dfs(nx, cost + ncost, cnt + 1);
            vis[nx] = 0;
        }
    }
}

void init(){fill(visited[0], visited[1001], 0);}//방문 배열 초기화

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == 'S'){
                stx = j; sty = i;
                m[i][j] = '.';
            }
            else if(m[i][j] == 'K'){
                loc.push_back({j,i});
                if(nodenum == 58) nodenum = 65;
                m[i][j] = nodenum++;
            }
        }
    }
    visited[sty][stx] = 1;
    q.push(make_tuple(stx,sty,0));
    bfs(1); init();

    for(int i = 0;i<loc.size();i++){
        visited[loc[i].second][loc[i].first] = 1;
        q.push(make_tuple(loc[i].first, loc[i].second, 0));
        bfs(i+2); init();
    }//printmap(N,M,m);

    vis[1] = 1;
    dfs(1, 0, 0);
    cout << res;
}
/*
풀이 방법 봄.(BFS + 백트래킹)

범위가 크므로 비트마스킹은 사용 불가...
우선 각 노드 끼리의 최소 거리를 구해줘야 함.

1. 먼저 S에서 서로 다른 모든 K에 대한 최단 거리를 구해서 연결 및 저장(인접 리스트 형태)
2. 서로 다른 모든 K에 대해 각각 bfs를 돌려 자신을 제외한 모든 K를 연결 및 저장
3. S에서 출발하여 모든 경우에 대해 백트래킹
1- cnt = 5면 res에 cost(최소 시간)을 저장하고 리턴
그 후 res != -1일 때 cost + ncost >= res면 스킵

*/