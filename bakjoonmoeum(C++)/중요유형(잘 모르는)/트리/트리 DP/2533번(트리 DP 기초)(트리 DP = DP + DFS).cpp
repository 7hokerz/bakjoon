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

int N, u, v, visited[1'000'001];
int dp1[1'000'001], dp2[1'000'001];//선택한 경우, 선택하지 않은 경우
vector <int> gr[1'000'001];

void dfs(int x){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];

        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
            dp1[x] += min(dp1[nx], dp2[nx]);//선택한 경우
            dp2[x] += dp1[nx];//선택하지 않은 경우 //cout << dp1[x] << ' ' << dp2[x] << ' ' << x << '\n';
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(dp1, dp1 + 1000001, 1);
    cin >> N;
    for(int i = 0;i<N-1;i++){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    visited[1] = 1;
    dfs(1);
    cout << min(dp1[1], dp2[1]); //cout << dp1[1] << ' ' << dp2[1];
}
/*
선택한 경우는 둘 중 하나가 되어도 상관없고, 
선택하지 않은 경우는 반드시 선택해야 함.

dp1 4 += 1,0 = 1
dp2 4 += 1 = 1

dp1 2 += 2
dp2 2 += 1 = 2
*/