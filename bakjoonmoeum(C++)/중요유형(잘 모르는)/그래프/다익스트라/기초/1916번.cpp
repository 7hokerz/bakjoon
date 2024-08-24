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
int N, M, one, two, len, st, en;

vector <pair<int,int>> gr[1001];
vector <int> dist(1001, INF);

void dij_pq(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
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
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0;i < M;i++){
        cin >> one >> two >> len;
        gr[one].push_back({two,len});
    }
    cin >> st >> en;
    dij_pq(st);
    
    cout << dist[en];
}
/*
for(int i = 1;i<N+1;i++){
        cout << dist[i] << '\n';
    }
*/