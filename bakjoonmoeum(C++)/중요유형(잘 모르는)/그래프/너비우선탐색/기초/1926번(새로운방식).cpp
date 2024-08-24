#include <iostream>
#include <queue>
using namespace std;
//앞으로는 이런 형식으로 그래프 문제를 풀도록 하자
//세로 x(행), 가로 y(열) 기준 표는 아래로 내려간다. 헷갈릴 확률 99%
//북,동,남,서
//총 4 방향 탐색
//앞으로 이동해야할 위치의 조건을 두려면 요 값을 변경해주면 된다.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int map[501][501] = {0};
bool visited[501][501] = {0};
int n,m;
int cnt = 0, maxnum = 0, ncount = 0;//그림의 개수


void bfs(int x, int y){
    queue <pair<int,int>> q;
    q.push({x,y});

    visited[x][y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];

            if(next_x >= 0 && next_x<n && next_y >= 0 && next_y < m){
                if(map[next_x][next_y] == 1 && !visited[next_x][next_y]){//총 4개의 방향 중 방문하지 않은 1이 있는지 확인하여 있으면 큐에 삽입
                    
                    visited[next_x][next_y] = true;
                    q.push({next_x, next_y});
                }
            }
        }
        ncount++;
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int input;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!visited[i][j] && map[i][j] == 1){
                bfs(i,j);
                maxnum = (maxnum>ncount)?maxnum:ncount;
                ncount = 0;
            }
        }
    }
    cout << cnt << '\n';
    cout << maxnum;
}
/*


*/