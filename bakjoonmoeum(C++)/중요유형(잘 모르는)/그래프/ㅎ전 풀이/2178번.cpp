#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int v, bool visited[], vector <int> graph[], int goal, int& time){
    queue <pair<int,int>> q; q.push({v, time});
    if(visited[q.front().first]) return;
    visited[v] = true;

    while(!q.empty()){
        int x = q.front().first; time = q.front().second; q.pop();
        //cout << x << ' ';
        
        for(int i = 0;i<graph[x].size();i++){
            int y = graph[x][i];
            if(y == goal) return;
            if(!visited[y]){
                q.push({y,time+1}); visited[y] = true;
            }
        }
    }
    //cout << "함수 ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, k = 0, goal;
    cin >> N >> M;
    int map[N][M];
    string input;
    for(int i = 0;i<N;i++){
        cin >> input;
        for(int j = 0;j<M;j++){
            if(input[j] == '1'){
                map[i][j] = ++k;
            } 
            else map[i][j] = 0;
            if(i == N - 1 && j == M - 1) goal = map[i][j];
        }
    }
    bool visited[k+1];
    for(int i = 1;i<k+1;i++) visited[i] = false;
    vector <int> graph[k+1];
    for(int i = 0;i<N;i++)
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
    int cnt = 1;
    
    bfs(map[0][0], visited, graph, goal, cnt);
    cout << cnt+1;
}
/*
미로 탈출 문제다.
최단 경로를 구하는데에는 bfs가 항상 최단 경로를 구할 수 있으므로 bfs를 이용했다.(dfs는 처음 노드 도착했을 때가 최단 경로가 아닐 수도 있음)

꽤나 고민했던 건 최단 경로값을 어떻게 출력시키냐였는데, 다른 분의 도움으로 해결했다.
**바로 큐에 시간 값을 저장해주는 것이다.

처음 time=1이고, 첫 삽입된 큐는 time=1을 갖고 있다.
**그리고 큐에서 제거되고 time = q.front().second 하여 해당 큐의 시간대를 받고, 해당 노드의 인접 노드가 있을 것 아닌가?
**인접 노드를 큐에 넣을 땐 time+1과 같이 삽입해준다. 이렇게 하면 단순 cnt++로 정점의 개수를 구하는 것과 다르게 최단 경로(시간값)
을 구할 수 있게 된다.

****한 줄 요약: 큐에 시간 값을 같이 저장하고, 인접 노드를 큐에 넣을 땐 time(=q.front().second)+1을 넣어주자.

+ 그리고 미로찾기니까 이중 for문 쓸 필요 없다. 출발점은 하나니까!!!
*/