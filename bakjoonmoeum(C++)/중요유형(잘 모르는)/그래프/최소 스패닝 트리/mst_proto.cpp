#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, P, C, S, E, L, res = 0;
int parent[1001];

vector <int> cost;

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
    for(int i = 0;i<spg.size();i++){
        auto[w, f, s] = spg[i];//가중치, 정점1, 정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외
        //cout << f << ' ' << s << ' ' << w << '\n';
        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == N-1) return;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> P;
    for(int i = 1;i<N+1;i++){
        parent[i] = i;
        cin >> C;
        cost.push_back(C);
    }
    for(int i = 1;i<P+1;i++){
        cin >> S >> E >> L;

    }



    kruskal();

    for(t3 val: mst) res += get<0>(val);
    
    cout << res;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3;


int V, E, A, B, C, parent[10001];
ll res = 0;
vector <t3> gr, mst;

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) parent[y] = x;
}

void Prim(){



    
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> V >> E;
    for(int i = 1;i<V+1;i++) parent[i] = i;

    for(int i = 0;i<E;i++){
        cin >> A >> B >> C;
        gr.push_back({C,A,B});//w, 정점 1, 정점 2
    }
    sort(gr.begin(), gr.end());//가중치 순 정렬


}


*/