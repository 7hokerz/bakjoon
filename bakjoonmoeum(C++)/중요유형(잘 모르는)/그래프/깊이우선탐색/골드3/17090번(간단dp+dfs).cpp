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
#define mod 1'000'000'007

int N, M, cnt = 0; string input;
int visited[502][502], ans[502][502];
char map[502][502];

//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 ,1};

int dfs(int x, int y){ //cout << y << ' ' << x << '\n';
    if(visited[y][x]) return -1;
    int dx, dy;
    visited[y][x] = true;
    
    //현재 문제는 해당 요소의 글자에 방향이 정해져 있으므로 이런 식으로 나눈다.
    if(map[y][x] == 'L') dx = -1, dy = 0;
    else if(map[y][x] == 'R') dx = 1, dy = 0;
    else if(map[y][x] == 'U') dx = 0, dy = -1;
    else dx = 0, dy = 1;

    int nx = x + dx; int ny = y + dy;

    if(nx < 1 || ny < 1 || nx > M || ny > N || ans[ny][nx] == 1){//탈출 가능한 경우
        ans[y][x] = 1; return 1;
    }
    else if(ans[ny][nx] == -1){ans[y][x] = -1; return -1;}
    return ans[y][x] = dfs(nx,ny);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            map[i][j] = input[j-1];
        }
    }
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(!visited[i][j]) dfs(j,i);
        }
    }
    
    int total = 0;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            if(ans[i][j] > 0) total++;
        }
    }
    cout << total;
}
/*
이 문제의 경우는 해당 좌표의 문자에 따라 방향이 정해진다. 
그리고 모든 좌표에 대해 탐색하지 않고 방문하지 않은 곳만 탐색하면서 나갈 수 있으면 1 없으면 -1을 좌표에 기록하는 방식이다.

for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
*/