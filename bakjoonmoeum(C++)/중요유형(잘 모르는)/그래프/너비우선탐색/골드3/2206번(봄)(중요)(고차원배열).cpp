#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
//북,동,남,서
//총 4 방향 탐색
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

int map[1001][1001]; int visited[1001][1001][2];//visited 배열은 벽을 부순 경우1, 부수지 않은 경우에 대해 나눈 것
int N, M, minlength = 1'000'001; string input;

int bfs(int x, int y){
    queue <pair<pair<int,int>,int>> q;
    q.push({{x,y},0});//처음엔 벽을 깨지 않은 상태이므로 0에 대해 작성
    visited[y][x][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;

        if(x == M && y == N) return visited[y][x][wall];
        
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
            
            if(visited[ny][nx][wall] == 0 && map[ny][nx] == 0){//갈 수 있는 길이면서 방문하지 않은 경우
                visited[ny][nx][wall] = visited[y][x][wall] + 1;
                q.push({{nx,ny}, wall});
            }

            if(wall == 0 && map[ny][nx] == 1){//벽인데 다른 벽을 한 번도 부수지 않은 경우
                visited[ny][nx][wall + 1] = visited[y][x][wall] + 1;
                q.push({{nx,ny}, wall + 1});
            }
        }
    }
    return -1;//찾지 못한 경우 -1 출력
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            map[i][j] = input[j-1] - '0';
        }
    }
    cout << bfs(1,1);
}
/*(봄)
벽을 부순 상태와 부수지 않은 상태를 나누기 위해 3차원 배열을 사용해야만 했다.


*/