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

int N, M, root, leftn, rightn, visited[10001], levelminmax[10001][2];
int loc = 1, maxlevel = 1;
vector <int> gr[10001];

void dfs(int rt, int level){
    maxlevel = max(maxlevel, level);
    int nxleft = gr[rt][0];
    if(nxleft != -1 && !visited[nxleft]){
        visited[nxleft] = 1;
        dfs(nxleft, level + 1);
    }

    if(!levelminmax[level][0]){ levelminmax[level][0] = loc; levelminmax[level][1] = loc++;}
    else levelminmax[level][1] = max(levelminmax[level][1], loc++); 
    
    int nxright = gr[rt][1];
    if(nxright != -1 && !visited[nxright]){
        visited[nxright] = 1;
        dfs(nxright, level + 1);
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int rootnode = N*(N+1)/2;
    for(int i = 0;i<N;i++){
        cin >> root >> leftn >> rightn;
        if(leftn != -1) rootnode -= leftn;
        if(rightn != -1) rootnode -= rightn;
        gr[root].push_back(leftn);
        gr[root].push_back(rightn);
    }
    
    visited[rootnode] = 1;
    dfs(rootnode, 1);

    int level = 1, w = 1;
    for(int i = 1;i<maxlevel + 1;i++){
        if(levelminmax[i][1] - levelminmax[i][0] + 1 > w){
            //아... if문 안에서 +1 안붙여서 계속 틀리다니 줫같네...
            w = levelminmax[i][1] - levelminmax[i][0] + 1;
            level = i;
        }
    }
    cout << level << ' ' << w;
}
/*
중위 순회를 이용한 탐색 문제.

다만 루트 노드가 1이라는 보장이 없으므로 루트 노드를 직접 구한 후 탐색해야 한다.

루트 노드에서 탐색을 시작해 중위 순회로 탐색을 이어간다.
이때 처음 레벨에 대한 좌표값은 항상 작으므로 [0] 및 [1]에 대입,
그 이후부터는 값을 비교하며 [1]에 최대값이 오도록 만든다.

그리고 레벨 최대 - 레벨 최소 + 1의 값이 가장 큰 경우를 출력한다.
*/