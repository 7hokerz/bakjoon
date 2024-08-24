#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int stcnt = 0, time = 0, cnt = 0;

void bfs(int start[], bool visited[], vector <int> graph[]){
    
    queue <pair<int,int>> q; 
    for(int i = 0;i<stcnt;i++){
        q.push({start[i], time});
        visited[start[i]] = true;
    }

    while(!q.empty()){
        int x = q.front().first; time = q.front().second; q.pop();
        //cout << x << ' ';
        
        for(int i = 0;i<graph[x].size();i++){
            int y = graph[x][i];

            if(!visited[y]){
                q.push({y,time+1}); visited[y] = true;
            }
        }
        cnt++;
    }
    //cout << "함수 ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N, input, k = 0;
    cin >> M >> N;
    int map[N][M], start[N*M];//1인 좌표를 저장할 배열
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> input;
            if(input == 1){
                map[i][j] = ++k;
                start[stcnt++] = k;
            } 
            else if(input == 0) map[i][j] = ++k;//갈 수 있는 노드 개수 저장
            else if(input == -1) map[i][j] = -1;//갈수 없는 곳은 -1로 처리
        }
    }

    bool visited[k+1];
    for(int i = 1;i<k+1;i++) visited[i] = false;
    vector <int> graph[k+1];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){//4방향 인접 리스트 저장
            if(j+1 < M && map[i][j] > 0 && map[i][j+1] > 0){
                graph[map[i][j]].push_back(map[i][j+1]);
                graph[map[i][j+1]].push_back(map[i][j]);
            }
            if(i+1 < N && map[i][j] > 0 && map[i+1][j] > 0){
                graph[map[i][j]].push_back(map[i+1][j]);
                graph[map[i+1][j]].push_back(map[i][j]);
            }
            //이거 안 써도 된다. 시간도 줄어들고 좋다!
            //안써도 되는 이유: 어차피 배열을 완전 순회하면서 아래, 오른쪽을 조사하기도 하고, 서로 연결되기도 하므로 그렇다.
            /*if(i-1 >= 0 && map[i][j] > 0 && map[i-1][j] > 0){
                graph[map[i][j]].push_back(map[i-1][j]);
                graph[map[i-1][j]].push_back(map[i][j]);
            }
            if(j-1 >= 0 && map[i][j] > 0 && map[i][j-1] > 0){
                graph[map[i][j]].push_back(map[i][j-1]);
                graph[map[i][j-1]].push_back(map[i][j]);
            }*/
        }
    }

    bfs(start, visited, graph);
    if(cnt != k){
        cout << -1;
        return 0;
    }

    cout << time;
}
/*

*/