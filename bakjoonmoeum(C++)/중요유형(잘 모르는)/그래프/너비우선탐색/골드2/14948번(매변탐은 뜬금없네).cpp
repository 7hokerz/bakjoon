#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {1, -1, 0, 0}; int dy[] = {0, 0, -1, 1};

int N, M, input, m[101][101], visited[101][101][2], res = -1;

queue <piiii> q;//x,y,mx,jmp

void bfs(){
    visited[1][1][0] = m[1][1];
    q.push({{1,1}, {m[1][1],0}});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int mx = q.front().second.first;
        int jmp = q.front().second.second;

        q.pop();

        if(x == M && y == N){
            if(res == -1) res = mx;
            else res = min(mx, res);
            continue;
        }
        if(res != -1 && res <= mx) continue;

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(visited[ny][nx][jmp] == -1 || visited[ny][nx][jmp] > max(mx, m[ny][nx])){
                visited[ny][nx][jmp] = max(mx, m[ny][nx]);
                q.push({{nx,ny},{visited[ny][nx][jmp],jmp}});
            }

            if(m[ny][nx] > mx){
                nx = nx + dx[i]; ny = ny + dy[i];

                if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

                if(!jmp && (visited[ny][nx][jmp + 1] == -1 || visited[ny][nx][jmp + 1] > max(mx, m[ny][nx]))){
                    visited[ny][nx][jmp + 1] = max(mx, m[ny][nx]);
                    q.push({{nx,ny},{visited[ny][nx][jmp + 1],jmp + 1}});
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> input;
            m[i][j] = input;
        }
    }
    fill_n(visited[0][0], 101*101*2, -1);//유용하다.
    bfs(); //printmap3(N, M, 0, visited); printmap3(N, M, 1, visited);
    cout << res;
}
/*
매변탐으로도 풀 수 있나보다. 그래프는 필수고.
하지만 아직 잘 모르니까 다음에...
입력값으로 0도 들어올 수 있다는 걸 몰랐다. 그래서 틀렸다.

visited를 -1로 초기값을 두면 해결

*/