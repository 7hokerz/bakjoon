#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void bfs(int v, bool visited[], vector <int> graph[]){
    queue <int> q; q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();
        //cout << x << ' ';
        for(int i = 0;i<graph[x].size();i++){
            if(!visited[graph[x][i]]){
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, input, max = 0, min = 0;
    cin >> N;
    int map[N][N];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> input;
            max = (input>max)?input:max;
            min = (input<min)?input:min;
            map[i][j] = input;
        }
    }

    int maxres = 0;
    for(int h = min-1;h<max;h++){
        int tmpmap[N][N];
        int k = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(map[i][j] > h) tmpmap[i][j] = ++k;
                else tmpmap[i][j] = 0;
            }
        }

        bool visited[k+1];
        for(int i = 0;i<k+1;i++) visited[i] = false;
        vector <int> graph[k+1];
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(j+1<N && tmpmap[i][j] != 0 && tmpmap[i][j+1]){
                    graph[tmpmap[i][j]].push_back(tmpmap[i][j+1]);
                    graph[tmpmap[i][j+1]].push_back(tmpmap[i][j]);
                }
                if(i+1<N && tmpmap[i][j] != 0 && tmpmap[i+1][j]){
                    graph[tmpmap[i][j]].push_back(tmpmap[i+1][j]);
                    graph[tmpmap[i+1][j]].push_back(tmpmap[i][j]);
                }
            }
        }

        for(int i = 0;i<N;i++) for(int j = 0;j<N;j++) if(tmpmap[i][j] != 0 && !visited[tmpmap[i][j]]) bfs(tmpmap[i][j], visited, graph);
        cout << cnt << ' ';
        maxres = (cnt>maxres)?cnt:maxres;
        cnt = 0;
    }
    cout << maxres;
}
/*


*/