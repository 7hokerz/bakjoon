#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, a, b, t;

int dist[1001], dp[1001], visited[1001];
vector <pii> gr[1001];

void dij(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        auto [cost, x] = pq.top();

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            auto [nx, ncost] = gr[x][i];
            ncost += cost;

            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({ncost, nx});
            }
        }
    }
}

void dfs(int x){
    if(x == 2) return;
    
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        //탐색 및 값 누적은 항상 합리적인 이동경로인 경우에만 진행한다.
        if(!visited[nx] && dist[x] > dist[nx]){
            visited[nx] = 1;
            dfs(nx);
        }//방문한 경우는 경우의 수 계산이 완료된 상태이므로
        if(dist[x] > dist[nx]) dp[x] += dp[nx];
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&dist[0], 1001, INF);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> a >> b >> t;
        gr[a].push_back({b,t});
        gr[b].push_back({a,t});
    }
    
    dij(2);//T = 2에서 각 노드의 최단거리를 구한다. 
    
    dp[2] = 1;//도착 지점 dp 초기화

    dfs(1);
    cout << dp[1];
} 
/*
DP는 해도 해도 떠올리기 어렵다. 이번 문제는 운이 좋아 한 방 컷!이지 않을까나...
//for(int i = 1;i<N+1;i++) cout << dist[i] << ' '; cout << '\n';
//for(int i = 1;i<N+1;i++) cout << dp[i] << ' ';
*/