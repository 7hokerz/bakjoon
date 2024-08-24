#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN
 
int N, M, O, Oi, res = INF;
bool can[(1 << 11)];
vector <int> stu[11];

void dfs(int num, int stucnt){//cout << num << ' ' << stucnt << ' ' << "in" << '\n';
    if(stucnt >= res) return;//이 문구 추가 시 32ms >> 0ms로 줄어든다.

    vector <int> cannum;

    for(int val: stu[num]){
        if(!can[1 << val]){
            cannum.push_back(val);
            can[1 << val] = 1;
        }   
    }

    bool chk = true;

    for(int i = 1;i<N+1;i++){
        if(!can[(1 << i)]){ chk = false;
            for(int j = num + 1;j<M+1;j++) dfs(j, stucnt + 1);
        }
    }

    if(chk) res = min(res, stucnt);

    for(int val: cannum) can[1 << val] = 0;
    //cout << num << ' ' << stucnt << ' ' << "out" << '\n';
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){ cin >> O;
        for(int j = 1;j<O+1;j++){
            cin >> Oi;
            stu[i].push_back(Oi);
        }
    }

    for(int i = 1;i<M+1;i++) dfs(i, 1);

    if(res == INF) cout << -1;
    else cout << res;
}
/*

*/