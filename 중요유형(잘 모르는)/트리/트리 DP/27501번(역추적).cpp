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

int N, u, v, visited[500001], dp[500001][3];//R, G, B
vector <int> gr[500001];
vector <pii> tracking[500001][3], res;

void calc(int x, int nx, int select, int a, int b){
    if(dp[nx][a] > dp[nx][b]){
        dp[x][select] += dp[nx][a];
        tracking[x][select].push_back({nx, a});
    }
    else if(dp[nx][a] < dp[nx][b]){
        dp[x][select] += dp[nx][b];
        tracking[x][select].push_back({nx, b});
    }else{//굳이 같은 경우에 대해 처리할 필요가 없는 듯 하다.
    //어차피 색깔은 다르지만 둘 중 뭘 해도 값이 다르거나 하지 않기 때문?
        dp[x][select] += dp[nx][a];
        tracking[x][select].push_back({nx, a});
        tracking[x][select].push_back({nx, b});
    }
}

/*두 함수 모두 가능
void calc(int x, int nx, int select, int a, int b){
    if(dp[nx][a] > dp[nx][b]){
        dp[x][select] += dp[nx][a];
        tracking[x][select].push_back({nx, a});
    }
    else{
        dp[x][select] += dp[nx][b];
        tracking[x][select].push_back({nx, b});
    }
}*/

void dfs(int x){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];
        
        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
            calc(x, nx, 0, 1, 2);//x가 R일 때
            calc(x, nx, 1, 0, 2);//x가 G일 때
            calc(x, nx, 2, 0, 1);//x가 B일 때
        }
    }
}

void trace(int x, int color){
    for(int i = 0;i<tracking[x][color].size();i++){
        int nx = tracking[x][color][i].first;
        int ncolor = tracking[x][color][i].second;
        //cout << x << ' ' << color << ' ' << nx << ' ' << ncolor << '\n';
        if(!visited[nx]){
            visited[nx] = 1;
            res.push_back({nx, ncolor});
            trace(nx, ncolor);
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N-1;i++){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i = 1;i<N+1;i++) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    
    visited[1] = 1;
    dfs(1);
    fill(visited, visited+500001, 0);
    
    if(dp[1][0] >= dp[1][1] && dp[1][0] >= dp[1][2]){//등호 안붙이면 else로 가서 잘못된 답 나온다.
        res.push_back({1,0}); cout << dp[1][0] << '\n';
        trace(1, 0);
    }else if(dp[1][1] >= dp[1][0] && dp[1][1] >= dp[1][2]){
        res.push_back({1,1}); cout << dp[1][1] << '\n';
        trace(1, 1);
    }else{
        res.push_back({1,2}); cout << dp[1][2] << '\n';
        trace(1, 2);
    }

    sort(res.begin(), res.end());
    for(int i = 0;i<res.size();i++){
        if(res[i].second == 0) cout << 'R';
        else if(res[i].second == 1) cout << 'G';
        else cout << 'B';
    }cout << '\n';
}
/*
인접한 노드가 R,G,B 중 같지 않으면서 합이 최댓값이 되어야 하는 문제

2213번과 유사한 문제다. 하지만 개인적으로 고생을 덜 한 건 이 문제....

dp배열을 채우는 방법은 단순 DP문제인 RGB거리와 같은 방법이다.
한 색을 선택하면 다른 두 색 중 최댓값을 dp에 저장하는 것

하지만 중요한 건 역추적인데, 
어차피 3개 중 최댓값을 찾아 해당 배열만 역추적하면 된다.
저 tracking 벡터를 어떤식으로 만들고 세우냐가 문제지...

트리 DP에서 중요한 점
역추적을 할 때 값을 한 개만 저장하려고 하면 안 된다.
위와 같이 모든 경우의 수에 대해 벡터를 만들고 거기다가 저장하자. 

1 469 558 532
2 9 22 55
3 99 24 29
4 138 67 118
5 199 124 198
6 112 150 112
7 17 88 93
8 8 85 7
*/