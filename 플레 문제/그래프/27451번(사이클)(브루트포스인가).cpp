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
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, A, B, C, s, e, res = -1, goal = -1;

vector <int> gr[45], route[3];
int visited[45][3][3001][2];//노드, ABC, 지나간 횟수, (방문 표시(0), 이전 노드(1)pre)
queue <lpii> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int person = q.front().first.second;
        int cnt = q.front().second;
        if(cnt > 3000) return;
        q.pop();
        
        if(visited[x][0][cnt][0] && visited[x][1][cnt][0] && visited[x][2][cnt][0]){
            goal = x;
            res = cnt;
            return;
        }

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];
            if(!visited[nx][person][cnt + 1][0]){
                visited[nx][person][cnt + 1][0] = 1; visited[nx][person][cnt + 1][1] = x; 
                q.push({{nx, person}, cnt + 1});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> A >> B >> C;
    for(int i = 0;i<M;i++){
        cin >> s >> e;
        gr[s].push_back(e);
    }

    q.push({{A,0},0}); q.push({{B,1},0}); q.push({{C,2},0});
    visited[A][0][0][0] = visited[B][1][0][0] = visited[C][2][0][0] = 1;
    visited[A][0][0][1] = visited[B][1][0][1] = visited[C][2][0][1] = -1;
    bfs();
    if(res == -1) { cout << -1; return 0; }
    cout << goal << ' ' << res << '\n';
    
    for(int i = 0;i<3;i++){
        int prv = goal;
        int cnt = res;
        while(prv != -1){
            route[i].push_back(prv);
            prv = visited[prv][i][cnt--][1];
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = route[i].size()-1;j>=0;j--){
            cout << route[i][j] << ' ';
        }cout << '\n';
    }
}
/*
사이클이 존재하는 테스트 케이스가 존재한다. 이 말은 영원히 만나지 못하는 경우가 있음.
N과 M의 범위가 크지 않아서 그런지 cnt 제한을 두고 브루트포스로 풀면 풀린다.

다만 사이클을 표시하고 사이클을 1번 이상 모두 돈 경우에 리턴하는 방법을 모색해보고 싶은데,
구현을 하지 못하겠다. 나중에 생각해보자.(사이클 찾기 방법도 연습하자.)


과정: 배열은 4차원으로 만들고, 그래프 벡터와, 나중에 루트를 출력할 벡터도 만든다.
1. 초기 방문 처리 및 선행 노드 설정
2. bfs()
2-1. 방문하지 않은 지점에 대해 방문 표시 및 선행 노드 삽입
2-2. 2-1을 반복하다가 어느 순간에 같은 카운트 값이 3명 모두가 방문 처리되는 경우 리턴
3. 번호와 경로 출력 후 루트 출력을 위해 나머지 작업
*/