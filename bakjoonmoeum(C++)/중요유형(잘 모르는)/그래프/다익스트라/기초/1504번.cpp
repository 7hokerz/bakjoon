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
#define INF 1'999'999'999
int N, E, a, b, c, v1, v2, sum1 = 0, sum2 = 0;

vector <pair<int,int>> gr[801];
int dist[801];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        //cout << cur << '\n';
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0;i<gr[cur].size();i++){
            int nx = gr[cur][i].first;
            int ncost = cost + gr[cur][i].second;

            if(dist[nx] > ncost){
                dist[nx] = ncost;
                pq.push({dist[nx], nx});
            }
        }
    }
}

int res;
int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(dist, dist+801, INF);
    cin >> N >> E;
    bool flag1, flag2;//해당 경로가 존재하는지 구별하는 변수
    flag1 = flag2 = true;

    for(int i = 0;i < E;i++){
        cin >> a >> b >> c;
        gr[a].push_back({b,c});
        gr[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    dijkstra(1);

    //INF인 경우 도달하지 못한 경우로 다음부터 다익스트라 호출 제외
    sum1 = dist[v1]; sum2 = dist[v2];
    if(sum1 == INF) flag1 = false;
    if(sum2 == INF) flag2 = false;
    fill(dist, dist+801, INF);

    dijkstra(v1);//v2까지의 최단 경로 구하기

    if(flag1) sum1 += dist[v2];
    if(flag2) sum2 += dist[v2] + dist[N];
    //1 >> v2 >> v1 >> N이므로 v1 >> N을 다시 중복해서 나중에 호출할 필요가 없음.
    fill(dist, dist+801, INF);

    dijkstra(v2);//v2 >> N
    if(flag2) sum1 += dist[N];

    if(!flag1 && !flag2) res = -1;//두 경로 모두 불가능
    else{
        res = min(sum1, sum2);//두 경우 중 최단 경로 선택
    }

    if(res >= INF) res = -1;//INF보다 큰 경우 불가능한 경로가 중간에 존재하는 경우임.

    cout << res;
}
/*
1에서 4로 갈 때, 2 3 반드시 방문하는 최단 경로

                1     (3)     2


                    (5)2,4
             (4)    (5)1,3   (3)


                4     (1)     3

갈 수 있는 경로 2가지 존재
1 >> v1 >> v2 >> n
1 >> v2 >> v1 >> n

1)
1. 1 >> v1까지의 최단 경로 : 3
2. 1 >> v2까지의 최단 경로 : 5

2)
v1 >> v2까지의 최단 경로: 

3)
1. v1 >> n까지의 최단 경로:
2. v2 >> n까지의 최단 경로:
for(int i = 1;i<N+1;i++){
            cout << dist[i] << ' ';
        }cout << '\n';
*/ 