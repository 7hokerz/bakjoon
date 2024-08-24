#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;
#define mod 1'000'000'009
#define INF 2'000'000'001

int T, N, M, u, v, D, visited[1001], dp[1001];

void dfs(int x, vector <pii> gr[]){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int ncost = gr[x][i].second;

        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx, gr);

            if(dp[nx] != 0 && dp[nx] < ncost){
                dp[x] += dp[nx];
            }
            else{
                dp[x] += ncost;
            } 
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int j = 0;j<T;j++){
        cin >> N >> M;
        vector <pii> gr[1001];
        for(int i = 0;i<M;i++){
            cin >> u >> v >> D;
            gr[u].push_back({v, D});
            gr[v].push_back({u, D});
        }

        visited[1] = 1;
        dfs(1, gr);
        
        cout << dp[1] << '\n';

        fill(visited,visited+1001,0); fill(dp,dp+1001,0);
    }
}
/*
가중치의 합을 최소가 될 때 그 가중치를 출력
for(int i = 1;i<N+1;i++){
            cout << dp1[i] << '\n';
        }


*/