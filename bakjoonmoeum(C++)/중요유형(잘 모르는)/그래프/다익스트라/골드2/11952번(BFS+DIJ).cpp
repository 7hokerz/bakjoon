#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 0x7F7F7F7F7F
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int N, M, K, S, P, Q, f, s;
int bad[100001];
ll dist[100001];
vector <int> gr[100001];

void dij(){
    fill(dist, dist+100001, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto[cost,x] = pq.top();

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];
            ll ncost = cost;

            if(bad[nx] == 2) continue;

            if(nx != N){
                if(bad[nx]) ncost += Q;
                else ncost += P;
            }
            
            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({ncost, nx});
            }
        }
    }
}

queue <pii> q;

void defbad(){
    while(!q.empty()){
        auto [x, cnt] = q.front();

        q.pop();

        if(cnt == S) continue;

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i];

            if(!bad[nx]){
                bad[nx]++;
                q.push({nx, cnt + 1});
            }
        }
    }
    dij();
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K >> S >> P >> Q;
    for(int i = 1;i<K+1;i++){
        cin >> f; 
        bad[f] = 2; q.push({f, 0});
    }

    for(int i = 1;i<M+1;i++){
        cin >> f >> s;
        gr[f].push_back(s);
        gr[s].push_back(f);
    }
    defbad();
    cout << dist[N];
}
/*





*/