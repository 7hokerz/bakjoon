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

int M, N, X, s, e, t, sn, en;

int dist[101001][2];//거리, 전 노드(prev)
vector <pii> gr[101001];

void dijkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,start});
    dist[start][0] = 0;
    dist[start][1] = -1;//시작 지점의 전 노드는 없으므로 -1

    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second;

        pq.pop();

        if(x <= N && dist[x][0] < cost) continue;//도시 노드만 조건 확인
        //버스 노드는 어차피 비용이 0이므로 고려하지 않음

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;
            int ncost = cost + gr[x][i].second;

            if(dist[nx][0] > ncost || nx > N){//버스 노드는 비용과 상관없이 통과
                dist[nx][0] = ncost; dist[nx][1] = x;
                pq.push({dist[nx][0], nx});  
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(dist[0], dist[101001], INF);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> s >> e >> t;
        gr[s].push_back({N+i,0});//출발도시 >> 버스
        gr[N+i].push_back({e,t});//버스 >> 도착도시
    }
    cin >> sn >> en;
    dijkstra(sn);
    //printdist3(N+M, dist);
    cout << dist[en][0] << '\n';//최단 거리
    
    int node = en;
    vector <int> res;
    while(node != -1){
        if(node < N+1) res.push_back(node);
        node = dist[node][1];
    }
    cout << res.size() << '\n';
    for(int i = res.size()-1;i>=0;i--){
        cout << res[i] << ' ';//최단 거리 경로
    }
}
/*                         
역추적 문제.
왜냐면 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력해야하기 때문.
이 부분은 생각이 안나서 슨생님께 물어봄.

dist 배열을 이용
1: 최단 거리
2: 이전 노드(현재 노드를 거치기 전)

버스를 노드로 생각한다. 
이때 출발도시 >> 버스 노드 (비용 0) , 버스 노드 >> 도착 도시 (비용 t)로 둔다.(5214번 방식)

시작 지점에서 다익스트라 호출.

dist[][1]에 저장된 값을 이용하여 벡터에 버스 노드를 제외한 도시 노드만 저장
역순으로 출력
*/ 