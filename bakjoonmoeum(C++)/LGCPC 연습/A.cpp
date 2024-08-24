#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, K, Q, P, L, inp, ret = 0;
int parent[1001];

vector <t3> spg, mst;

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) parent[y] = x;
}

void kruskal(){
    for(int i = spg.size() - 1;i >= 0;i--){
        auto[w, f, s] = spg[i];//가중치, 정점1, 정점2
        
        //사이클 발생 시 제외
        if(find(f) == find(s)) continue;
        mst.push_back({w,f,s});
        //cout << w << ' ' << f << ' ' << s  << '\n';
        uni(f,s);

        if(mst.size() == N-1) return;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    int x, y;

    for(int i = 1;i<M+1;i++){
        cin >> x >> y;
        spg.push_back({i,x,y});
    }
    sort(spg.rbegin(), spg.rend());

    while(K--){
        for(int i = 1;i<N+1;i++) parent[i] = i;
        kruskal();

        for(t3 val: mst) ret += get<0>(val);
        spg.pop_back();

        if(mst.size() == N-1) cout << ret << ' ';
        else cout << 0 << ' ';

        ret = 0;
        mst.clear();
    }
}
/*

*/