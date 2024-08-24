#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, x, y, z, res = 0;
int parent[100'001];

vector <pii> xplanet, yplanet, zplanet;
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
        int w = get<0>(spg[i]);//가중치
        int f = get<1>(spg[i]);//정점1
        int s = get<2>(spg[i]);//정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외
        //cout << f << ' ' << s << ' ' << w << '\n';
        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == N-1) return;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        parent[i] = i;
        cin >> x >> y >> z;
        xplanet.push_back({x,i});
        yplanet.push_back({y,i});
        zplanet.push_back({z,i});
    }//x와 y와 z를 따로 받고 끼리끼리 정렬 및 가중치 계산
    //결국 모든 정점에 대해 3개의 간선이 담기게 된다. 
    //그리고 그 중 N/3개의 간선이 최소 스패닝 트리를 구성하게 된다.
    sort(xplanet.begin(), xplanet.end());
    sort(yplanet.begin(), yplanet.end());
    sort(zplanet.begin(), zplanet.end());

    for(int i = 1;i<N;i++){//N+1 해서 undefined behavior 일어나서 75% 틀렸었다...
        int costx = abs(get<0>(xplanet[i]) - get<0>(xplanet[i-1]));
        int costy = abs(get<0>(yplanet[i]) - get<0>(yplanet[i-1]));
        int costz = abs(get<0>(zplanet[i]) - get<0>(zplanet[i-1]));
        spg.push_back({costx, get<1>(xplanet[i]), get<1>(xplanet[i-1])});
        spg.push_back({costy, get<1>(yplanet[i]), get<1>(yplanet[i-1])});
        spg.push_back({costz, get<1>(zplanet[i]), get<1>(zplanet[i-1])});
    }
    sort(spg.begin(), spg.end());

    kruskal();

    for(t3 val: mst) res += get<0>(val);
    
    cout << res;
}
/*
간선을 모두 저장하면 메모리 초과 발생.
간선을 모두 (N^2) 저장하지 않고 일부(3N) 만 저장하는 방법에 대해서 배움. 
추후에도 쓰일 수 있는 좋은 테크닉이라고 생각이 든다.
*/