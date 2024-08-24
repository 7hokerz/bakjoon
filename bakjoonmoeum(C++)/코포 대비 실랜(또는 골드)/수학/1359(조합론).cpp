#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, M, K, total = 0, win = 0;

vector <int> vt, vt2;

void dfs(int x, int cnt){
    if(cnt == M){
        int cant = 0, num1[9], num2[9];
        for(int i = 0;i<N+1;i++) {num1[i] = num2[i] = 0;}
        
        for(int i = 0;i<vt.size();i++){ num1[vt[i]]++; num2[vt2[i]]++; }
        
        for(int i = 1;i<N+1;i++) cant += abs(num1[i] - num2[i]);

        if(K <= M - cant / 2) win++;

        total++;
        //cout << M - cant / 2 << ' ' << win << ' ' << total << '\n';
        return;
    }

    for(int i = x + 1;i<N+1;i++){
        vt.push_back(i);
        dfs(i, cnt + 1);
        vt.pop_back();
    }
}

void dfs2(int x, int cnt){
    if(cnt == M){
        for(int i = 1;i<N+1;i++) {
            vt.push_back(i);
            dfs(i,1);
            vt.pop_back();
        }
        return;
    }

    for(int i = x + 1;i<N+1;i++){
        vt2.push_back(i);
        dfs2(i, cnt + 1);
        vt2.pop_back();
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++) {
        vt2.push_back(i);
        dfs2(i,1);
        vt2.pop_back();
    } //cout << total << ' ' << win << '\n';
    cout.precision(11);
    cout << (double)win / (double)total;
}
/*

*/