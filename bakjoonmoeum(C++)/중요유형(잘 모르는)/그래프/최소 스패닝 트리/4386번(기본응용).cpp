#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<double,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N,  parent[101];
double A, B, res = 0;
vector <pair<double, double>> lis;
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
        double w = get<0>(gr[i]);//가중치
        int f = get<1>(gr[i]);//정점1
        int s = get<2>(gr[i]);//정점2

        if(find(f) == find(s)) continue;//사이클 발생 시 제외

        mst.push_back({w,f,s});

        uni(f,s);

        if(mst.size() == N - 1) return mst;
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N+1;i++) parent[i] = i;

    for(int i = 1;i<N+1;i++){
        cin >> A >> B;
        lis.push_back({A,B});
    }

    for(int i = 1;i<N+1;i++){
        for(int j = i+1;j<lis.size()+1;j++){
            double x = lis[j-1].first - lis[i-1].first;
            double y = lis[j-1].second - lis[i-1].second;
            double w = sqrt(pow(x,2) + pow(y,2));
            //cout << w << '\n';
            gr.push_back({w,i,j});
        }
    }
    sort(gr.begin(),gr.end());

    vector <t3> mst = kruskal();

    for(t3 val: mst) res += get<0>(val);
    
    cout << fixed << setprecision(2) << res;
}

/*

*/