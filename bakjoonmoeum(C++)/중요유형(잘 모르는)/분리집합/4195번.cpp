#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int T, F;
string a, b;
map<string, string> parent;
map<string, int> node_rank, cnt;

string find(string x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void union_root(string x, string y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(node_rank[x] < node_rank[y]) {
            parent[x] = y; cnt[y] += cnt[x];
        }
        else if(node_rank[x] > node_rank[y]) {
            parent[y] = x; cnt[x] += cnt[y];
        }
        else{
            parent[y] = x;
            cnt[x] += cnt[y];
            node_rank[x]++;
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    for(int j = 0;j<T;j++){
        cin >> F;
        for(int i = 0;i<F;i++){
            cin >> a >> b;
            if(parent[a].empty()) { parent[a] = a; cnt[a]++;}
            if(parent[b].empty()) { parent[b] = b; cnt[b]++;}
            union_root(a, b); 
            cout << cnt[find(a)] << '\n';//부모 맵에 접근하는 게 아니라 find 함수로 접근하기 필수
        }
        parent.clear(); node_rank.clear(); cnt.clear();
    }
}
/*
cnt[parent[x]] 형식으로 접근할 때 parent[x]는 항상 갱신되었다는 보장이 없다.
따라서 find(x)로 갱신된 부모 값을 받을 수 있도록 하자.
즉 직접 parent에 접근하지 말고 find 함수로 접근하자.
*/