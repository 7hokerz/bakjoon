#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int,int> t4;
#define INF 1e9

int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1}; int dy[] = {0, 1, 0, -1, -1, -1, 1, 1};
//WSEN NW NE SW SE
int N, M, a, b, t, res = 0, minn = INF, comp = 0, cant1 = 0, cant2 = 0;

int dist[1001], pre[1001];
vector <pii> gr[1001];

void dij(bool mod){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0; pre[1] = -1;
    
    while(!pq.empty()){
        auto [cost, x] = pq.top();

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            auto [nx, ncost] = gr[x][i];
            ncost += cost;

            if((x == cant1 && nx == cant2) || (x == cant2 && nx == cant1)) continue;

            if(dist[nx] > ncost){
                dist[nx] = ncost; 
                if(mod) pre[nx] = x;
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
    dij(true);
    minn = min(dist[N], minn);

    int prenode = N;
    while(prenode != -1){
        cant1 = prenode;
        for(int i = 0;i<gr[prenode].size();i++){
            cant2 = gr[prenode][i].first;
            if(cant2 != pre[prenode]) continue;
            fill_n(&dist[0], 1001, INF);
            dij(false);
            comp = max(comp, dist[N]); //cout << cant1 << ' ' << cant2 << '\n';
        }//cout << '\n';

        prenode = pre[prenode];
    }
    //cout << minn << ' ' << comp << '\n';
    if(comp == INF) cout << -1;
    else cout << comp - minn;
}
/*
    

*/