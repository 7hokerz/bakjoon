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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007
//int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int N, par, ch, weight, mx = 0, startnum = 0, endnum = 0;

vector <pair<int,int>> gr[10001];//노드 및 가중치
int visited[10001];

void dfs(int x, int sum){
    if(gr[x].size() == 1 && startnum != x){
        if(sum > mx){
            mx = sum;
            endnum = x;
        }
        return;
    }

    for(int i = 0;i<gr[x].size();i++){
        if(!visited[gr[x][i].first]){
            visited[gr[x][i].first] = 1;
            dfs(gr[x][i].first, sum + gr[x][i].second);
            visited[gr[x][i].first] = 0;
        }
    }
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N-1;i++){
        cin >> par >> ch >> weight;
        gr[par].push_back({ch, weight});
        gr[ch].push_back({par, weight});
    }

    visited[1] = 1; startnum = 1;
    dfs(startnum, 0);
    visited[1] = 0;

    visited[endnum] = 1;
    startnum = endnum;
    dfs(startnum, 0);

    cout << mx;
}
/*

 for(int i = 1;i<N+1;i++){
        if(gr[i].size() == 1){
            visited[i] = 1;
            startnum = i;
            dfs(startnum, 0); break;
        }
    }
모든 리프 노드에 대한 완탐: 360ms

공식 이용: 4ms

공식: 
어떤 노드에서 가장 먼 노드를 A,
A에서 가장 먼 노드를 B라고 하면

A와 B사이의 거리가 트리의 지름(최대 거리)이 됨.

즉, 아무 노드 하나를 선택해 가장 먼 노드를 구하고, 가장 먼 노드에서 가장 먼 노드를 구하면 됨.
*/ 