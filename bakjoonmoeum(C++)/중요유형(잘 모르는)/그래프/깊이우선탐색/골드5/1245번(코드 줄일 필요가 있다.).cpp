#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007

int N, M, res = 0;
int map[101][71], input;
bool visited[101][71], ans[101][71];
//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0 ,1, 1, -1, -1, 1};

void dfs(int x, int y){
    visited[y][x] = true;

    for(int k = 0;k<8;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;//범위를 벗어난 경우
        if(map[ny][nx] < map[y][x]) continue;//높이가 낮은 경우
        if(map[ny][nx] > map[y][x] /*|| (map[ny][nx] == map[y][x] && ans[ny][nx] == 1)*/) {
            //높이가 높으면 봉우리가 될 수 없으므로 표시
            ans[y][x] = 1;
        }
        if(!visited[ny][nx]){//방문하지 않은 노드에 대해 같은 높이일 때 dfs 재귀호출
            if(map[ny][nx] == map[y][x]) dfs(nx,ny); 
        }
        if(map[ny][nx] == map[y][x] && ans[ny][nx] == 1) {//요기다 해야 답(dfs로 갱신된 결과가 다를 수도 있기 때문)
            //높이가 같은 인접한 봉우리가 봉우리가 될 수 없다고 표시된 경우 현재 봉우리도 될 수 없음.
            ans[y][x] = 1;
        }
    }
}

void scan(int x, int y){
    if(ans[y][x] != 0) return;

    int ab = 1;
    for(int k = 2;k < 6;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;//범위를 벗어난 경우
        ab = ab && (ans[y][x] == 0 && ans[ny][nx] != 0);
    }
    if(ab){//cout << y << ' ' << x << '\n';
        res++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int j = 1;j<N+1;j++)
        for(int i = 1;i<M+1;i++)
            dfs(i,j);
    
    for(int j = 1;j<N+1;j++)
        for(int i = 1;i<M+1;i++)
            scan(i,j);
    
    cout << res;
}
/*
어떤 산봉우리 주변에 보다 큰 높이의 격자가 존재하면 산봉우리가 아님.
또한 위의 조건을 만족하는 같은 크기의 모든 인접한 봉우리들은 봉우리가 될 수 없다.
for(int i = 1;i<N+1;i++){
    for(int j = 1;j<M+1;j++){
        cout << ans[i][j] << ' ';
    }
    cout << '\n';
}
*/