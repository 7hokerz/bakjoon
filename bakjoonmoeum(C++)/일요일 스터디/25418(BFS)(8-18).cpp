#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, A, K, inp, ret = 0;

bool visited[1'000'001];

queue <pii> q;

void bfs(){
    visited[A] = 1;
    q.push({A,0});
    
    while(!q.empty()){
        auto[x, cnt] = q.front();
        
        q.pop();

        if(x == K){
            cout << cnt; return;
        }

        int nx = x + 1;

        if(nx < 1'000'001 && !visited[nx]){
            visited[nx] = 1;
            q.push({nx, cnt + 1});
        }

        nx = x * 2;

        if(nx < 1'000'001 && !visited[nx]){
            visited[nx] = 1;
            q.push({nx, cnt + 1});
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> A >> K;
    bfs();
}
/*
A >> K로 풀었지만 사실은 K >> A로도 풀 수 있다.
*/