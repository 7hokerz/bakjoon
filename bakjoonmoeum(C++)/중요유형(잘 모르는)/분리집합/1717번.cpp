#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int n, m, num, a, b, parent[1'000'001];

int find_root(int x){
    if(x == parent[x]) return x;//x가 root면 x를 반환
    
    return parent[x] = find_root(parent[x]); //아니면 부모 노드에서 루트 노드 찾기를 반복. 이 때 x의 부모 노드를 루트 노드로 갱신하기.
}

void union_root(int x, int y){ //x와 y의 루트 노드를 찾는다.
    x = find_root(x);
    y = find_root(y);

    if(x != y){ //서로 다른 트리에 속하면 한 쪽의 트리를 다른 쪽에 붙임.
        parent[x] = y;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i<n+1;i++) parent[i] = i;
    
    for(int i = 0;i<m;i++){
        cin >> num >> a >> b;
        if(num == 1){
            int roota = find_root(a);
            int rootb = find_root(b);
            if(roota == rootb) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
        else union_root(a, b);
    }
}

/*



*/