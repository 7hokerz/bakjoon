#include <iostream>
#include <queue>
using namespace std;
//앞으로는 이런 형식으로 그래프 문제를 풀도록 하자
//세로 x(행), 가로 y(열) 기준 표는 아래로 내려간다는 점을 명심하자. 헷갈릴 확률 99%

//총 4 방향 탐색
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int map[101][101] = {0}; bool visited[101][101] = {0};
int n, m;

void bfs(int x, int y){
    queue <pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;//필수

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout << x << ' ' << y << '\n';
        for(int i = 0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];

            if(next_x >= 0 && next_x<n && next_y >= 0 && next_y < m){//배열의 범위를 벗어나는 경우 방지
                if((map[next_x][next_y] == 1 && !visited[next_x][next_y])){//노드 및 방문 여부 확인
                    visited[next_x][next_y] = true;//필수
                    q.push({next_x, next_y});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    
}
/*


*/