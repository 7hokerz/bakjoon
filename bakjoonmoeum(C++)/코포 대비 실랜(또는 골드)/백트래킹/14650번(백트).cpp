#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, ret = 0;
vector <int> vt;

void dfs(int x, int cnt){
    if(cnt == N){
        int num = 0;
        for(int i = vt.size() - 1;i>=0;i--){
            num += vt[i] * (N - i);
        }
        if(!(num % 3)) ret++;
        return;
    }

    vt.push_back(0);
    dfs(0,cnt + 1);
    vt.pop_back();

    vt.push_back(1);
    dfs(1,cnt + 1);
    vt.pop_back();

    vt.push_back(2);
    dfs(2,cnt + 1);
    vt.pop_back();
}
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    vt.push_back(1);
    dfs(1,1);
    vt.pop_back();

    vt.push_back(2);
    dfs(2,1);
    vt.pop_back();
    
    cout << ret;
}
/*

*/