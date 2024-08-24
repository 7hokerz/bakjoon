#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int v, bool visited[], vector <int> graph[]){
    visited[v] = true;
    cout << v << ' ';

    for(int i = 0;i<graph[v].size();i++){
        int y = graph[v][i];
        if(!visited[y]) dfs(y, visited, graph);
    }
}

void bfs(int v, bool visited[], vector <int> graph[]){
    queue <int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for(int i = 0;i<graph[x].size();i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, V;
    int f, s;
    cin >> N >> M >> V;
    bool visited[N+1];
    for(int i = 1;i<N+1;i++) visited[i] = false;//중요! 초기화는 필수다... 방심하지 말자
    vector <int> graph[N+1];

    for(int i = 0;i<M;i++){
        cin >> f >> s;
        graph[f].push_back(s);
        graph[s].push_back(f);
    }
    for(int i = 1;i<N+1;i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V, visited, graph);
    cout << '\n';
    for(int i = 1;i<N+1;i++) visited[i] = false;
    bfs(V, visited, graph);
}
/*
그래프의 기본 문제.

간선이 연결하는 두 정점의 번호를 받아서 해당 벡터에 넣어주면 된다. 1 2면 graph[1] << 2 하고, graph[2] << 1도 필수!
중요한 점은 간선 입력값은 항상 정렬된 순서가 되진 않으므로 벡터에 모두 넣어준 후 각 벡터마다 정렬시켜야 한다.
*/
