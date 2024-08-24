#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int v, bool visited[], vector <int> graph[], int &cnt){
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
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, f, s;
    cin >> N >> M;
    bool visited[N+1];
    for(int i = 1;i<N+1;i++) visited[i] = false;
    vector <int> graph[N+1];

    for(int i = 0;i<M;i++){
        cin >> f >> s;
        graph[f].push_back(s);
        graph[s].push_back(f);
    }
    
    int cnt = 0;
    for(int i = 1;i<N+1;i++){
        bfs(i, visited, graph, cnt);
    }
    cout << cnt;
}
/*

*/