#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, K, a, b, c, parent[1001], sum = 0, mx = 0, mxnode = 0;
bool vis[1001];
vector <t3> spg;
vector <pii> gr[1001];

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) parent[y] = x;
}

vector <t3> kruskal(){
    vector <t3> mst;

    for(int i = 0;i<spg.size();i++){
        int w = get<0>(spg[i]);//가중치
        int f = get<1>(spg[i]);//정점1
        int s = get<2>(spg[i]);//정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외
        //cout << w << '\n';
        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == N - 1) return mst;
    }
}

void dfs(int x, int cur){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int cost = gr[x][i].second;

        if(!vis[nx]){
            vis[nx] = 1;
            dfs(nx, cur + cost);
            if(cur + cost > mx){
                mx = cur + cost;
                mxnode = nx;
            }
            vis[nx] = 0;
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1;i<N+1;i++) parent[i] = i;

    for(int i = 1;i<K+1;i++){
        cin >> a >> b >> c;
        spg.push_back({c,a,b});
    }
    sort(spg.begin(), spg.end());

    vector <t3> mst = kruskal();

    for(t3 val: mst) {
        int w = get<0>(val); int f = get<1>(val); int s = get<2>(val);
        gr[f].push_back({s,w});
        gr[s].push_back({f,w});
        sum += w;
    }

    vis[0] = 1;
    dfs(0,0);
    vis[0] = 0;

    vis[mxnode] = 1;
    dfs(mxnode,0);
    vis[mxnode] = 0;

    cout << sum << '\n' << mx;
}

/*r

*/