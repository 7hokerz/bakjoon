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
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007
#define INF 1'999'999'999
//2차원 map 출력
#define printmap(row, col, map)        \
    for (int i = 1; i < (row) + 1; i++)   \
        for (int j = 1; j < (col) + 1; j++)  \
            cout << (map)[i][j] << ' ';  \
        cout << '\n';                   \

//1차원 dist배열
#define printdist2(N, dist)        \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k] << ' ';           \
    }cout << '\n';  \

//2차원 dist배열
#define printdist3(N, dist)        \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k][0] << ' ';           \
    }cout << '\n';  \
    
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int M, N, t, s, g, h, a, b, d;

int dist[2001];//거리

void dijkstra(int start, vector <pii> gr[]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;
            int ncost = cost + gr[x][i].second;

            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({dist[nx], nx});  
            }
        }
    }
}
int T;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int k = 0;k<T;k++){
        int sum1 = 0, sum2 = 0;
        vector <pii> gr[2001];
        vector <pair<int,int>> can;
        vector <int> res;
        
        fill(dist, dist+2001, INF);
        bool flag1, flag2; flag1 = flag2 = true;
        cin >> N >> M >> t >> s >> g >> h;
        //교차로, 도로, 목적지 후보 개수
        for(int i = 1;i<M+1;i++){//도로
            cin >> a >> b >> d;
            gr[a].push_back({b, d});
            gr[b].push_back({a, d});
        }

        dijkstra(s, gr);
        for(int i = 0;i<t;i++){//목적지 후보에 대한 g와h에 상관없는 최단 거리 저장
            cin >> d;
            can.push_back({d, dist[d]});
        }
        printdist2(N, dist);

        sum1 = dist[g]; sum2 = dist[h];
        if(dist[g] == INF) flag1 = false;
        if(dist[h] == INF) flag1 = false;
        fill(dist, dist+2001, INF);
        dijkstra(g, gr);
        
        printdist2(N, dist);
        if(flag1) sum1 += dist[h];//start >> g >> h >> goal
        if(flag2) sum2 += dist[h];//start >> h >> g >> goal
        
        for(int i = 0;i<t;i++){
            if(can[i].second == dist[can[i].first] + sum2){
                res.push_back(can[i].first);
            }
        }
        fill(dist, dist+2001, INF);
        dijkstra(h, gr);
        //cout << sum1 << ' ' << sum2 << '\n';
        printdist2(N, dist);
        for(int i = 0;i<t;i++){
            if(can[i].second == dist[can[i].first] + sum1){
                res.push_back(can[i].first);
            }
        }
        sort(res.begin(), res.end());
        for(int i = 0;i<res.size();i++){
            cout << res[i] << ' ';
        }cout << '\n';
    }
}
/*                         
목적지 후보가 여러개 존재한다.
이 때 목적지 후보로 가는 최단 경로가 g와 h를 통과했는지를 확인하는 문제
g와 h를 통과한 최단 경로면 해당 목적지 노드 출력
*/ 