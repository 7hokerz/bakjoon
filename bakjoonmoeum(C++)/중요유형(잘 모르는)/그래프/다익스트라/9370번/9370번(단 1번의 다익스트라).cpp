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
#define INF 1'999'999'990
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
//vector <pii> gr[2001];

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
        vector <pii> gr[2001];
        vector <int> res;
        
        fill(dist, dist+2001, INF);
        cin >> N >> M >> t >> s >> g >> h;
        //교차로, 도로, 목적지 후보 개수
        for(int i = 1;i<M+1;i++){//도로
            cin >> a >> b >> d;
            //g와 h사이의 도로는 -1로 빼주어 홀수로 나타남(+1로 하지 않은 이유는 같은 g,h를 지나지 않는 
            //같은 거리가 존재할 때 +1을 할 시 g,h를 지나지 않는 도로에 대해 최단 경로가 입력되기 때문...)
            if((a == g && b == h) || (a == h && b == g)){
                gr[a].push_back({b, d*2 - 1});
                gr[b].push_back({a, d*2 - 1});
            }
            else{
                gr[a].push_back({b, d*2});
                gr[b].push_back({a, d*2});
            }
        }

        dijkstra(s, gr);
        //printdist2(N, dist);
        for(int i = 0;i<t;i++){
            cin >> d;
            if(dist[d] % 2 == 1) res.push_back(d);
        }
        sort(res.begin(),res.end());
        for(int i = 0;i<res.size();i++){
            cout << res[i] << ' ';
        }cout << '\n';
    }
}