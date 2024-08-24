#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, a, b, t, ret = 0, cant1, cant2;

int dist[1001], prenode[1001];
vector <pii> gr[1001];

void dij(bool mod){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0; 
    if(mod) prenode[1] = -1;
    
    while(!pq.empty()){
        auto [cost, x] = pq.top();

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            auto [nx, ncost] = gr[x][i];
            ncost += cost;

            if(!mod && ((x == cant1 && nx == cant2) || (x == cant2 && nx == cant1))) continue;

            if(dist[nx] > ncost){
                dist[nx] = ncost; 
                if(mod) prenode[nx] = x;
                pq.push({ncost, nx});
            }
        }
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
    dij(1);

    int pre = N;

    while(prenode[pre] != -1){
        fill_n(&dist[0], 1001, INF);

        cant1 = pre; cant2 = prenode[pre];
        dij(0);
        ret = max(ret, dist[N]);
        pre = prenode[pre];
    }
    cout << ret;
} 
/*

*/