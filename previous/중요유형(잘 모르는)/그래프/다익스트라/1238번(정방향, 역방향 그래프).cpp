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
#define printmap(row, col, map)        \
    for (int i = 1; i < (row) + 1; i++)   \
        for (int j = 1; j < (col) + 1; j++)  \
            cout << (map)[i][j] << ' ';  \
        cout << '\n';                   \

#define printdist(N, dist)        \
    for (int k = 1; k < (N) + 1; k++){ \
        cout << (dist)[k] << ' ';           \
    }cout << '\n';  \
    
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int M, N, X, s, e, t;

int dist[1001];
vector <pii> gr[1001], rgr[1001];//정방향, 역방향

void dijkstra(vector <pii> graph[]){//그래프 입력 받음
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,X});//항상 X에서 시작
    dist[X] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;
        
        pq.pop();

        if(dist[x] < cost) continue;

        for(int i = 0;i<graph[x].size();i++){
            int nx = graph[x][i].first;
            int ncost = cost + graph[x][i].second;

            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({dist[nx], nx});
            }
        }
    }
}
vector <int> sum;
int mx = 0;
int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 1;i<M+1;i++){
        cin >> s >> e >> t;
        gr[s].push_back({e,t});//정방향
        rgr[e].push_back({s,t});//역방향
    }
    fill(dist, dist + 1001, INF);
    dijkstra(gr);//정방향 그래프 수행
    
    for(int i = 1;i<N+1;i++) sum.push_back(dist[i]);
    
    fill(dist, dist + 1001, INF);
    dijkstra(rgr);//역방향 그래프 수행

    for(int i = 1;i<N+1;i++){
        sum[i-1] += dist[i];
        mx = max(mx, sum[i-1]);
    }

    cout << mx;
}
/*                         
입력값을 정방향 그래프 형태로 주어진다고 보면,
그에 대해 반대로 연결한 그래프를 역방향 그래프라고 볼 수 있음.
rgr이라는 다른 그래프 배열을 만들어 해당 벡터에 저장하면 됨.

이때 다익스트라는 항상 "X"노드에서 시작한다.

먼저 gr을 돌리게 되면 X에서 i까지의 모든 최단 거리를 구할 수 있다.
즉, "X에서 i"까지 돌아오는 것에 대한 거리

그 후 rgr을 돌리게 되면 이는 역방향 그래프가 되는데, 
마찬가지로 X노드에서 시작하지만,
이는 gr과 반대로 "i에서 X"까지 오는 거리로 해석할 수 있다.
*/ 