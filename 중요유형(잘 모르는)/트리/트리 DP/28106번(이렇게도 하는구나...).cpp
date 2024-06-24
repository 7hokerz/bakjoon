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
#define INF 2'000'000'001
#define mod 998'244'353

int N, u, root, visited[2001], jump[2001], level[2001], dp[2001];
//현 노드에서 갈 수 있는 최대 거리, 레벨 값, 경우의 수 저장
vector <int> gr[2001];
vector <pii> can[2001];//현 노드의 모든 서브 노드 정보 저장

void dfs(int x){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];
        
        if(!visited[nx]){
            visited[nx] = 1;
            level[nx] = level[x] + 1;//레벨 값. 거리를 계산하는 용도
            dfs(nx);
            //자식 노드의 모든 서브 노드 담기
            for(int j = 0;j<can[nx].size();j++) can[x].push_back(can[nx][j]);
            
            can[x].push_back({nx, level[nx]});//자식 노드 담기
        }
    }

    for(int j = 0;j<can[x].size();j++){//위 반복문 안에서 하면 중복 계산이 발생함.
        if(can[x][j].second - level[x] <= jump[x]){//모든 서브 노드를 돌며 가능한 경우 해당 dp값을 더해줌.
            dp[x] += dp[can[x][j].first] % mod;
            dp[x] %= mod;
        }
    }

    if(x != root && gr[x].size() == 1) dp[x] = 1;//리프 노드에 대하여 기본 1로 초기화
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> u;
        if(u == 0) {root = i; continue;}
        gr[u].push_back(i);
        gr[i].push_back(u);
    }
    for(int i = 1;i<N+1;i++) cin >> jump[i];

    visited[root] = 1;
    dfs(root);
    if(N == 1) cout << 1;//노드가 1개만 있는 경우
    else cout << dp[root] % mod;
}
/*
ㅅㅂ 어케 풀지 하고 고민 많이 한 문제.(골드4였던 거 기여로 골3으로 올림 ㅋㅋ)

루트는 정해져있으므로 따로 root 변수에 저장했다.

우선 레벨 값을 처음 dfs할 때 부여하여 추후 거리 계산 용도로 사용할 수 있게 했다.
그리고 can벡터를 사용하여 모든 서브 노드를 저장했다.
즉 모든 서브 노드 중에서 도달 가능한 경우에 대해
해당 dp값을 현 dp값에 더해줌으로써 경우의 수를 누적시켰다.

////
현 정점의 강도가 a면 1이상 a이하의 거리까지 점프 가능
리프 노드에 도착할 수 있는 경우만 포함

2 (3,2) (4,2) (5,3)
dp[2] += dp[3] + dp[4] + dp[5]
        1 + 0 + 1
리프 노드에만 dp값 1로?

dp[1] += dp[2] + dp[3] + dp[4]
        2 + 1 + 0
dp[1] += dp[6]
=4
*/