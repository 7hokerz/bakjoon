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

int N, M, one, two, w, visited[1001];
vector <pii> gr[1001];

void dfs(int x, int sum){
    if(x == two){
        cout << sum << '\n';
        return;
    }

    for(int i = 0;i<gr[x].size();i++){
        int nx = gr[x][i].first;
        int ndist = gr[x][i].second;

        if(!visited[nx]){
            visited[nx] = 1;
            dfs(nx, sum + ndist);
            visited[nx] = 0;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<N-1;i++){
        cin >> one >> two >> w;
        gr[one].push_back({two,w});
        gr[two].push_back({one,w});
    }
    for(int i = 0;i<M;i++){
        cin >> one >> two;
        visited[one] = 1;
        dfs(one, 0);
        visited[one] = 0;
    }
}
/*
트리의 두 노드의 경로는 유일하다. 따라서 최단 경로를 구하려는 생각이 필요 없이 
단순 DFS로 돌리면 바로 거리를 구할 수 있다.
사실 N이 작은 것도 한 몫 한다.
N이 커지면 LCA(아직 안 배움)를 써야지만 시간 초과가 나지 않게 된다.
*/