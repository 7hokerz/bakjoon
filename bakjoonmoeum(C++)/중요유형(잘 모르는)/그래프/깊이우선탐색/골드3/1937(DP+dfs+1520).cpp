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

int N, input, one, two, maxcnt = 0;
int visited[501][501], map[501][501], ans[501][501];

//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 ,1};

int dfs(int x, int y){
    //cout << y << ' ' << x << '\n';
    visited[y][x] = true;

    bool chk = false;
    for(int k = 0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
        if(map[ny][nx] > map[y][x]){//갈 수 있는 조건을 만족하는 경우,
            //방문했었고, 저장된 누적 합이 0 이상인 경우(max로 비교하는 이유는 4방향 탐색을 하기 때문)
            if(visited[ny][nx] && ans[ny][nx] > 0) ans[y][x] = max(ans[y][x], ans[ny][nx] + 1);
            //방문한 적이 없으면 dfs로 값을 구한다.
            else if(!visited[ny][nx]) ans[y][x] = max(ans[y][x], dfs(nx,ny) + 1);
            chk = true;
        }
    }

    if(!chk) {//해당 지점이 갈 수 없는 경우로 둘러싸여있는 경우 경우의 수는 1
        ans[y][x]++; 
    } return ans[y][x];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cin >> input;
            map[i][j] = input;
        }
    }
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            if(!visited[i][j]){//방문하지 않은 경우만 탐색하여 시간 줄이기
                maxcnt = max(maxcnt, dfs(j,i));//여러 경우가 나올 수 있으므로 그 중 제일 큰 값만 저장
            }  
        }
    }
    cout << maxcnt;
}
/*
1520과 유사한? 방식으로 풀었다. 다만 조금은 달랐던 것? 같다.
자세한 설명은 위에 참조

for(int i = 1;i<N+1;i++){
        for(int j = 1;j<N+1;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
*/