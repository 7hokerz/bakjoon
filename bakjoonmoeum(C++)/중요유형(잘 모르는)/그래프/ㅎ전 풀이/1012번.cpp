#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int v, bool visited[], vector <int> graph[], int& cnt){
    queue <int> q;
    q.push(v);
    if(visited[q.front()]) return;
    visited[v] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        //cout << x << ' ';
        
        for(int i = 0;i<graph[x].size();i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
    //cout << "함수 ";
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0;i<T;i++){
        int M, N, K, f, s;
        cin >> M >> N >> K;
        vector <int> graph[K+1];
        bool visited[K+1]; for(int i = 0;i<K+1;i++) visited[i] = false;
        int map[N][M];
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                map[i][j] = 0;
        for(int i = 1;i<K+1;i++){
            cin >> f >> s;
            map[s][f] = i;
        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                if(j+1 < M && map[i][j] != 0 && map[i][j+1] != 0){
                    graph[map[i][j]].push_back(map[i][j+1]);
                    graph[map[i][j+1]].push_back(map[i][j]);
                }
                if(i+1 < N && map[i][j] != 0 && map[i+1][j] != 0){
                    graph[map[i][j]].push_back(map[i+1][j]);
                    graph[map[i+1][j]].push_back(map[i][j]);
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                if(map[i][j] != 0) bfs(map[i][j], visited, graph, cnt);
        cout << cnt << '\n';
    }
}
/*
연결 요소에 관한 문제.
중요!
1. visited 배열 초기화 필수
2. 원래 4방향 다 인접한 노드가 있는지 찾는 게 기본이지만 아래, 오른쪽 방향만 찾는다면 서로의 인접 노드를 넣어주자!
(1,4) (4,1) 둘 다 넣어주란 말
*/