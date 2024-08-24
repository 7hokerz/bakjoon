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

int N, M, input;
int map[501][501];
int visited[501][501];
int accu[501][501];

//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 ,1};

//DP없이 단순 dfs는 시간초과가 나므로 풀 수 없다. 16% 시간초과
//DP 시도 1. 누적 합 방식을 사용했으나 33% 시간초과(이유는 도달할 수 없는 경우에 대해 체크하지 않았기 때문 << 중복 계산 많음)
//DP 시도 2. 누적 합 방식에 도달할 수 없는 경우에 대해 체크하여 중복 계산 방지. 100% 틀림?!(이유는 1 2 / 1 1 같이 처음부터 못 가는 경우를 고려하지 않음)
//최종. ans[1][1]값이 -1인 경우 0으로 출력하도록 변경(통과)
int dfs(int x, int y){
    //cout << y << ' ' << x << '\n';
    if(x == N && y == M) {
        accu[y][x]++; return accu[y][x];//목표지점에 도달
    }
    visited[y][x] = true;

    for(int k = 0;k<4;k++){
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx < 1 || ny < 1 || nx > N || ny > M)continue;//범위를 벗어난 경우
        
        if(visited[ny][nx] == 0 && map[y][x] > map[ny][nx]){//방문하지 않았고 내리막길이면
            if(accu[ny][nx] > 0) accu[y][x] += accu[ny][nx];//누적 합이 존재하는 경우
            else if(accu[ny][nx] == 0){
                int chk = dfs(nx,ny);//누적 합이 0인 경우(방문해보지 않은 곳?)
                if(chk > 0) accu[y][x] += chk;
            } 
        }
    }
    visited[y][x] = false;
    if(accu[y][x] > 0) return accu[y][x];//누적 합 반환
    else{//모든 검사를 마쳤는데도 도달하지 못한 경우 -1을 반환(더이상 접근 불가능 하도록)
        return --accu[y][x];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for(int i = 1;i<M+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    dfs(1,1);

    if(accu[1][1] == -1) cout << 0;
    else cout << accu[1][1];
}
/*
목표 지점에 도달하면 해당 길에 카운트 + 1 및 반환

4 4
16 9 8 1
15 10 7 2
14 11 6 3
13 12 5 4

10 1 1 0
9 2 1 0
7 3 1 0
4 4 1 1

3 3
9 4 3
8 5 2
7 6 1

6 1 1
5 2 1
3 3 1
for(int i = 1;i<M+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << accu[i][j] << ' ';
        }
        cout << '\n';
    }


카운트가 1 이상인 좌표를 만나면, 이면 현재 좌표에 +1 카운트하고, 현재좌표에 대한 값을 리턴시킨다.
나중에 돌아올 때는 그 값이 점점 누적되어 좌표에 저장하게 된다.
최종적으로 max값, ans[1][1]이 답이 될 것
*/