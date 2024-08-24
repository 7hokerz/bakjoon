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
bool visited[101][71], chk = true;
//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0 ,1, 1, -1, -1, 1};

void dfs(int x, int y){
    visited[y][x] = true;

    for(int k = 0;k<8;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;//범위를 벗어난 경우 제외
        if(map[ny][nx] > map[y][x]) {
            chk = false;//높이가 높으면 될 수 없으므로 false
        }
        //방문하지 않은 노드에 대해 같은 높이일 때 dfs 재귀호출하여 상태 확인
        if(!visited[ny][nx] && map[ny][nx] == map[y][x]){
            dfs(nx,ny); 
        }
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
        for(int i = 1;i<M+1;i++){
            if(!visited[j][i]){//**중요! 기존에 방문하지 않은 지역에 대해서만 dfs
                chk = true;
                dfs(i,j);
                if(chk) res++;
            } 
        }  
    cout << res;
}