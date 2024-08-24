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
    for (int i = 1; i < (row) + 1; i++) {  \
        for (int j = 1; j < (col) + 1; j++) { \
            cout << (map)[i][j] << ' ';  \
        }                               \
        cout << '\n';                   \
    }

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};


int M, N;
string input;

int dist[101][101], map[101][101];

void dijkstra(){
    priority_queue<rpii, vector<rpii>, greater<rpii>> pq;
    //최단 거리, (x, y)좌표
    
    pq.push({0,{1,1}});
    dist[1][1] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        pq.pop();

        if(x == M && y == N){
            cout << cost;
            return;
        }

        if(dist[y][x] < cost) continue;

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = cost + map[ny][nx];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(dist[ny][nx] > ncost){
                dist[ny][nx] = ncost;
                pq.push({dist[ny][nx],{nx,ny}});
            }
        }
    }
}

int res;
int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(dist[0], dist[101], INF);
    cin >> M >> N;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            map[i][j] = input[j-1] - 48;
        }
    }
    //printmap(N,M,map);
    dijkstra();
}
/*
다익스트라를 미로에 활용한 문제

너비 우선 탐색과 비슷하게 코드를 구성하면 된다.
차이점은 우선순위 큐를 사용했고, cost, <x,y> 의 형태로 큐를 구성했다는 것이다.

벽을 굳이 따지면 1의 가중치, 빈 공간은 0의 가중치라고 보면 된다.

나머지는 너비 우선 탐색과 비슷한 형태로 진행해나가면 된다.
*/ 