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

int N, u, v, visited[10001];
int dp1[10001], dp2[10001];//우수 마을인 경우와 아닌 경우
vector <int> gr[10001];

void dfs(int x){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];

        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
            dp1[x] += dp2[nx];//주변에 일반 마을만 존재해야 함.
            dp2[x] += max(dp1[nx], dp2[nx]);//아닐 땐 둘 다 가능하므로
            //cout << x << ' ' << dp1[x] << ' ' << dp2[x] << '\n';
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> dp1[i];
    }
    for(int i = 0;i<N-1;i++){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    visited[1] = 1;
    dfs(1);
    //cout << dp1[1] << ' ' << dp2[1] << '\n';    
    cout << max(dp1[1], dp2[1]);
}
/*
우수 마을의 주민 수를 최대로


*/