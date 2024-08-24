#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 999999999
//중요! 가중치 값에 -1가 들어가면 안됨.

int N, M, K, X;

vector <pair<int,int>> gr[300001];
vector <int> dist(300001,INF);//해당 정점까지의 최소 비용을 저장하는 배열

void dij_pq(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//현재 비용, 정점
    //비용이 낮은 게 우선시되어야 하므로 최소 힙

    pq.push({0,start});//현재 비용 정점
    dist[start] = 0;//시작점의 비용은 0

    while(!pq.empty()){
        int cost = pq.top().first;//현재 노드까지의 비용(가중치)
        int cur = pq.top().second;//현재 위치
        pq.pop();

        if(dist[cur] < cost) continue;//최단경로가 체크되어있는 경우 패스

        for(int i = 0;i<gr[cur].size();i++){

            int nx = gr[cur][i].first;//인접 노드
            int ncost = cost + gr[cur][i].second;//인접 노드로 가는 비용(현재 노드 비용 + 다음 노드 비용)

            if(dist[nx] > ncost){//해당 정점까지 가는 비용 중 최솟값을 저장
                dist[nx] = ncost;
                pq.push({dist[nx], nx});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> X;
    int one, two;
    for(int i = 0;i<M;i++){
        cin >> one >> two;
        gr[one].push_back({two,1});//인접 노드, 인접 노드로 가는 비용
    }
    dij_pq(X);

    bool chk = false;
    for(int i = 1;i<N+1;i++){
        //if(dist[i] == K) {cout << i << '\n'; chk = true;}
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    //if(!chk) cout << -1;
}