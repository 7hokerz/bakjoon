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

int n, w, u, v;
int dp1[10001], dp2[10001], visited[10001];//선택한 경우, 선택하지 않은 경우
vector <int> gr[10001], selected[10001][2], res;
//selected0 : 선택한 경우일 때, selected1: 선택하지 않은 경우일 때
//selected 벡터에는 경우에 따른 선택된 노드(다음에 연결된 노드만)가 담겨있음.

void dfs(int x){
    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i];
        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx);
            dp1[x] += dp2[nx];//x를 선택하는 경우(nx는 선택하지 않음)
            
            for(int j = 0;j<selected[nx][1].size();j++){
                selected[x][0].push_back(selected[nx][1][j]);
            }
            
            //x를 선택하지 않는 경우
            if(dp1[nx] > dp2[nx]){//nx를 넣는 게 더 크면
                dp2[x] += dp1[nx];
                selected[x][1].push_back(nx);//nx를 선택함.
            }
            else{//nx를 넣지 않는 게 더 크면
                dp2[x] += dp2[nx];
                for(int j = 0;j<selected[nx][1].size();j++){
                    selected[x][1].push_back(selected[nx][1][j]);//nx를 선택하지 않음.
                }
            }   
        }
    }//cout << x << ' ' << dp1[x] << ' ' << dp2[x] << '\n';
}

void trace(int x, int val){//선택된 노드를 역추적(DFS)
    for(int i = 0;i<selected[x][val].size();i++){
        int nx = selected[x][val][i];
        if(!visited[nx]){
            visited[nx] = 1;
            res.push_back(nx);
            trace(nx, 0);
        }
    }//노드 1이 선택되지 않은 경우에만 val = 1이 오고, 이후로는 항상 val = 0이다.
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<n+1;i++) cin >> dp1[i]; 
    
    for(int i = 1;i<n;i++){
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    visited[1] = 1;
    dfs(1);
    fill(visited, visited+10001, 0);

    if(dp1[1] > dp2[1]) {//1이 더 커서 선택하면
        cout << dp1[1] << '\n';
        res.push_back(1);
        trace(1, 0);
    }else{//1을 선택하지 않으면
        cout << dp2[1] << '\n';
        trace(1, 1);
    }

    sort(res.begin(),res.end());
    for(int i = 0;i<res.size();i++) cout << res[i] << ' ';
}
/*
역추적 문제. 역추적 구하기 오래 걸렸다. 어려워...

처음에는 노드에 따라서 단순 이전 선택된 다음 노드를 담는 걸 구상했으나 여러 개 존재할 때 
한 번에 담지 못하여 실패했다.

selected 벡터를 통해 해결했다.
selected에는 현재 x일 때의 선택된 요소 중 다음 연결된 요소를 가지고 있다.
0은 x가 선택된 경우, 1은 x가 선택되지 않은 경우


dfs함수는 총 세 가지의 경우로 나눈다.
1. x가 선택됐을 때
x가 선택됐으면 nx는 선택될 수 없으므로 dp2[nx]를 더하고,
nx가 선택되지 않았을 때의 선택된 노드를 가져온다.

2. x가 선택되지 않았을 때
2-1. nx를 선택하는 경우
nx를 선택하는 경우가 선택하지 않는 경우보다 더 클 때를 말한다.
이 때는 nx는 선택되었으므로 nx를 삽입한다.

2-2. nx를 선택하지 않는 경우
nx가 선택되지 않았을 떄의 선택된 노드를 가져온다.

위 과정이 끝나면 노드 1에 대해서 경우를 구한 후
역추적을 진행한다.

노드 1을 제외하고는 항상 선택된 노드에 대해서만 역추적을 진행한다.

+ 한 노드의 역추적 벡터에 여러 개의 노드가 담긴 경우는 여러 갈림길이 존재하는 경우로 보면 된다.
*/