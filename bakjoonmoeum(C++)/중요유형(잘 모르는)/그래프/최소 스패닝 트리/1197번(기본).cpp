#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

/*
스패닝 트리(신장 트리): 그래프의 모든 정점을 잇지만 사이클이 없는 부분 그래프를 의미함.
즉 V개의 모든 정점을 연결하는 간선의 수는 V-1개

최소 스패닝 트리(MST): 간선 가중치 합이 최소가 되는 스패닝 트리

크루스칼 알고리즘: 그리디 알고리즘을 통해 구현
1. 선택되지 않은 간선들 중 최소 가중치인 간선을 선택.
2. 만약 그 간선을 선택했을 때 지금까지 구성된 스패닝 트리에 사이클이 없을 경우에만 선택.
3. 총 V-1개의 간선이 선택될 때까지 반복.
*/

int V, E, A, B, C, parent[10001];
ll res = 0;
vector <t3> gr;

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

    for(int i = 0;i<gr.size();i++){
        int w = get<0>(gr[i]);//가중치
        int f = get<1>(gr[i]);//정점1
        int s = get<2>(gr[i]);//정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외

        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == V - 1) return mst;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> V >> E;
    for(int i = 1;i<V+1;i++) parent[i] = i;

    for(int i = 0;i<E;i++){
        cin >> A >> B >> C;
        gr.push_back({C,A,B});//w, 정점 1, 정점 2
    }
    sort(gr.begin(), gr.end());

    vector <t3> mst = kruskal();
    
    for(int i = 0;i<mst.size();i++) res += get<0>(mst[i]);
    
    cout << res;
}