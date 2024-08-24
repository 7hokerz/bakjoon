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
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

//1차원 dist배열 출력
#define printdist1(N, dist)     \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k] << ' ';    \
    }cout << '\n';  \

//2차원 dist배열 출력(2차원 원소는 num으로 선택)
#define printdist2(N, dist, num)   \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k][num] << ' ';     \
    }cout << '\n';  \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, s, e, t;
int dist[201][2], m[201][201];
vector <pii> gr[1001];

void dij(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,start});
    dist[start][0] = 0;
    dist[start][1] = -1;

    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;

        pq.pop();

        if(dist[x][0] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;
            int ncost = cost + gr[x][i].second;

            if(dist[nx][0] > ncost){
                dist[nx][0] = ncost; dist[nx][1] = x;
                pq.push({dist[nx][0], nx});//가중치 합(최단 거리), 노드 
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<M;i++){
        cin >> s >> e >> t;
        gr[s].push_back({e,t});
        gr[e].push_back({s,t});
    }
    
    for(int i = 1;i<N+1;i++){
        fill(dist[0], dist[201], INF);

        dij(i);

        for (int k = 1; k < N + 1; k++) m[k][i] = dist[k][1];
    }
    for (int i = 1; i < N + 1; i++){
        for (int j = 1; j < N + 1; j++){
            if(m[i][j] == -1) cout << "- ";
            else cout << m[i][j] << ' ';
        }cout << '\n';
    }
}
/*                         

*/ 

