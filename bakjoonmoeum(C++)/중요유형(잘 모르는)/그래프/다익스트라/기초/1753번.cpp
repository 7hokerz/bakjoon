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
#define mod 1'000'000'007
//int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
#define INF 999'999'999
int V, E, K, u, v, w;

vector <pair<int,int>> gr[20001];
vector <int> dist(20001, INF);

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        cout << cur << '\n';
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0;i<gr[cur].size();i++){
            int nx = gr[cur][i].first;
            int ncost = cost + gr[cur][i].second;

            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({dist[nx], nx});
            }
        }
        for(int i = 1;i<V+1;i++){
            cout << dist[i] << ' ';
        }cout << '\n';
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E >> K;

    for(int i = 0;i < E;i++){
        cin >> u >> v >> w;
        gr[u].push_back({v,w});
    }
    dijkstra(K);
    for(int i = 1;i<V+1;i++){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}
/*
중요! 이 문제는 방향 그래프임.

    3     <<(3)      1      <<(1)     5

    (6)아래           (2)아래

    4     <<(5)      2

시작점: 1
0 2 3 INF INF (1에서 5로 갈 수 없기 때문)
큐에 노드2, 3 삽입


거리가 짧은 2 노드 먼저 방문
0 2 3 7 INF
2+5 = 7의 값 도출
큐에 4 삽입


다음으로 3 방문
0 2 3 7 INF
3+6 = 9지만 
기록된 7이 더 작으므로 무시됨.


4 방문
연결된 노드 없으므로 종료
*/ 