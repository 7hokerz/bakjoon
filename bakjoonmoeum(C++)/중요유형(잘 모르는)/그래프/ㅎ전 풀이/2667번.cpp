#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

int bfs(int v, bool visited[], vector <int> graph[]){
    int cnthome = 0;
    queue <int> q; q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();
        
        for(int i = 0;i<graph[x].size();i++){
            if(!visited[graph[x][i]]){
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }
        cnthome++;
    }
    cnt++;
    return cnthome;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, k = 0;
    string input;
    cin >> N;
    int map[N][N];
    for(int i = 0;i<N;i++){
        cin >> input;
        for(int j = 0;j<N;j++){
            if(input[j] == '1') map[i][j] = ++k;
            else map[i][j] = 0;
        }
    }
    bool visited[k+1];
    for(int i = 1;i<k+1;i++) visited[i] = false;
    vector <int> graph[k+1];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(j+1<N && map[i][j] != 0 && map[i][j+1] != 0){
                graph[map[i][j]].push_back(map[i][j+1]);
                graph[map[i][j+1]].push_back(map[i][j]);
            }
            if(i+1<N && map[i][j] != 0 && map[i+1][j] != 0){
                graph[map[i][j]].push_back(map[i+1][j]);
                graph[map[i+1][j]].push_back(map[i][j]);
            }
        }
    }

    vector <int> res;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            if(map[i][j] != 0 && !visited[map[i][j]]) res.push_back(bfs(map[i][j], visited, graph));
    sort(res.begin(), res.end());
    cout << cnt << '\n';
    for(int i = 0;i<cnt;i++) cout << res[i] << '\n';
}
/*


*/