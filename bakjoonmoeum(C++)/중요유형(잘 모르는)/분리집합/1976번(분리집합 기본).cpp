#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, inp, res = 0;
int parent[201], node_rank[201], listgo[1001];

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void union_root(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y){
        if(node_rank[x] < node_rank[y]) parent[x] = y;
        else if(node_rank[x] > node_rank[y]) parent[y] = x;
        else{
            parent[y] = x;
            node_rank[x]++;
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++) parent[i] = i;
    
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> inp;
            if(inp == 1) union_root(i,j);
        }
    }
    for(int i = 1;i<M+1;i++) cin >> listgo[i];
    
    for(int i = 2;i<M+1;i++) {
        if(find(listgo[i]) != find(listgo[i-1])){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}
/*

*/