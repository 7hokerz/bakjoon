#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int v, bool visited[], vector <int> graph[], int& count){
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
    count++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        int map[h][w], input, n = 0, m = 0;//노드, 간선

        for(int i = 0;i<h;i++){//노드의 개수 추가
            for(int j = 0;j<w;j++){
                cin >> input;
                if(input == 1) map[i][j] = ++n;//노드 번호를 추가
                else map[i][j] = 0;
            }
        }

        bool visited[n+1];
        for(int i = 1;i<n+1;i++) visited[i] = false;
        vector <int> graph [n+1];

        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(j+1 < w && map[i][j] != 0 && map[i][j+1] != 0){
                    graph[map[i][j]].push_back(map[i][j+1]);
                    graph[map[i][j+1]].push_back(map[i][j]);
                }
                if(i+1 < h && map[i][j] != 0 && map[i+1][j] != 0){
                    graph[map[i][j]].push_back(map[i+1][j]);
                    graph[map[i+1][j]].push_back(map[i][j]);
                }
                if(i+1 < h && j+1 < w && map[i][j] != 0 && map[i+1][j+1] != 0){
                    graph[map[i][j]].push_back(map[i+1][j+1]);
                    graph[map[i+1][j+1]].push_back(map[i][j]);
                }
                if(j+1 < w && i-1 >= 0 && map[i][j] != 0 && map[i-1][j+1] != 0){
                    graph[map[i][j]].push_back(map[i-1][j+1]);
                    graph[map[i-1][j+1]].push_back(map[i][j]);
                }
            }
        }
        int cnt = 0;

        for(int i = 0;i<h;i++)
            for(int j = 0;j<w;j++)
                if(map[i][j] != 0) bfs(map[i][j], visited, graph, cnt);

        cout << cnt << '\n';
    }
}
/*

*/