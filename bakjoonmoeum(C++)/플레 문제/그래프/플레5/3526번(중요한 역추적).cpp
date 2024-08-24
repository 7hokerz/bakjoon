#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;
#define INF 1e9+1

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, a, b, c;
vector <pii> gr[100001];
vector <int> res;
int dist[100001];//N에서 모든 정점에 대한 거리가 기록됨.
bool visited[100001];

void bfs(){//N에서 시작하여 모든 정점에 대한 거리를 구한다.
    queue <pii> q;
    dist[N] = 0;
    q.push({N, 0});

    while(!q.empty()){
        auto [x, cnt] = q.front();

        q.pop(); //cout << x << ' ' << cnt << '\n';

        for(int i = 0;i<gr[x].size();i++){
            int nx = gr[x][i].first;

            if(dist[nx] == -1){
                dist[nx] = cnt + 1;
                q.push({nx, cnt + 1});
            }
        }
    }
}

void track(){//1에서 시작하여 N까지 가는 사전 순 최단 거리를 찾는다.
    queue <int> q;
    visited[1] = 1;
    q.push(1);

    while(!q.empty()){
        int size = q.size();

        int minw = INF;
        //현재 큐에 있는 모든 요소를 꺼내고, 요소의 nx에 대하여 조사하여
        //가장 작은 숫자 값을 확인한다.
        for(int j = 0;j < size;j++){
            auto x = q.front();

            q.pop(); //cout << x << '\n';

            for(int i = 0;i<gr[x].size();i++){
                int nx = gr[x][i].first;
                int ncolor = gr[x][i].second;

                if(dist[nx] == dist[x] - 1){
                    minw = min(minw, ncolor);
                }
            }
            q.push(x);
        }

        if(minw != INF) res.push_back(minw);
        
        //한 번도 방문하지 않고 minw와 같은 값이면서 최단 거리인 지점으로 이동한다.
        for(int i = 0;i < size;i++){
            auto x = q.front();

            q.pop();

            for(int i = 0;i<gr[x].size();i++){
                int nx = gr[x][i].first;
                int ncolor = gr[x][i].second;

                if(minw == ncolor && !visited[nx] && dist[nx] == dist[x] - 1){
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }
        //위와 같이 하면 모든 같은 cnt에 대해서 조사하고 조건을 만족하는 경우만 큐에 삽입하므로 
        //서로 같은 cnt만 큐에 삽입됨을 알 수 있다.
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&dist[0], 100001, -1);
    cin >> N >> M;

    for(int i = 1;i<M+1;i++){
        cin >> a >> b >> c;
        gr[a].push_back({b, c});
        gr[b].push_back({a, c});
    }

    bfs();//N에서 모든 노드의 최단 거리 구하기(여기서 이미 최단 거리는 구할 수 있다.)
    track();//1에서 N까지 조건을 만족하는 경로 구하기

    cout << dist[1] << '\n';

    for(int val: res) cout << val << ' ';
}
/*
과정:
1. BFS로 N에서 출발하여 모든 정점에 대한 최단 거리를 구해준다. (이때 1~N 최단거리를 이미 알 수 있다.)

2. 1에서 N으로 시작하는 BFS를 실행하는데,

2-1. 먼저 큐의 사이즈 만큼 반복문을 돌려 모든 큐에 대해 연결된 간선에 대해 
종이의 최솟값을 조사한다. 단, 최단 거리가 성립하는 지점일 때만.

2-2. 그리고 최솟값을 구한 후 다시 반복문을 돌려 모든 큐에 대해 
최솟값을 만족하고 방문하지 않은 최단 거리 목적지인 경우에만 방문처리하고 새롭게 큐에 삽입해준다.

매우 생각지도 못한 방식이다. 
보통 노드를 사전순으로 하는 최단 거리는 단순 정렬 후에 작업을 수행하면 되지만 
위와 같이 노드와 별개로 별도의 값에 대한 사전순 최단 거리는 해본 적도 없고 매우 낯설었다...

기억할 것:

1~N까지의 최단 거리는 1 >> N으로도 구할 수 있지만, N >> 1로도 구할 수 있는 것은 당연한데, 
여기서 다른 점은 
dist 배열에 기억해놓으면 다음에 1 >> N으로 다시 작업을 수행할 때 최단 거리에 대해 
크게 고려하지 않고 dist[cur] - 1 == dist[nx] 위와 같은 식을 만족하는지에 대해서 확인하기만 하면 된다.

그리고 노드와 별개의 값에 대해서 모든 간선을 조사하는 방법도 기억하자.
바로 큐의 요소에 대해 다음 cnt + 1 작업을 수행하려 하지 말고 
size 만큼(즉, 같은 cnt) 반복을 돌려 특정 조건을 만족하는 값을 구하고(min, max 등등..)
그 값을 기준으로 cnt + 1 즉 다음 노드로 이동 가능한 경우를 걸러내면 된다는 것이다.

역추적에 대해서 많은 걸 얻어갈 수 있는 문제다.

반례:
5 7
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 2
5 4 2

ans: 1 4 2
wrong: 2 3 2 등등...
*/