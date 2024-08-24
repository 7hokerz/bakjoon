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

int dx[] = {1, -1, 0, 0}; int dy[] = {0, 0, -1, 1};
int dx2[] = {1, -1, -1, 1}; int dy2[] = {1, 1, -1, -1};

int N, M, K, R, C, D, m[3001][3001], visited[3001][3001], res = -1;

queue <lpii> q;//x,y,cnt

void bfs(){
    visited[1][1] = 1;
    q.push({{1,1},0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if(x == M && y == N){
            res = cnt;
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(!visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({{nx,ny}, cnt + 1});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for(int i = 0;i<K;i++){
        cin >> R >> C >> D;//y, x, 거리
        int nx = C; int ny = R - D;
        visited[R][C] = 2;//필수

        for(int h = 0;h<4;h++){//기발하다...
            for(int k = 0;k<D;k++){
                nx += dx2[h]; ny += dy2[h];

                if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

                visited[ny][nx] = 2;
            }
        }
    }
    bfs();
    //printmap(N, M, visited);
    if(res == -1) cout << "NO";
    else cout << "YES" << '\n' << res;
}
/*
1.
단순 모든 불가능 지역 채우기 및 bfs >> 60퍼 틀림
이유: 먼저 채운 지역이 방문처리되어 나중에 들어오는 모든 입력값이 무시됨.(그게 더 큰 범위를 차지할지라도)

2.
깨닫고 카운트를 이용해 위의 경우도 채우도록 허용 >> 1% 시간초과
이유: 채우는 부분이 너무 오래 걸림...

**3.(봄)
안을 채울 필요 없이 테두리만 체크하는 아이디어.
위 경우는 bfs가 아닌 별 찍기? 처럼 직접 표시해줘야 함.
단, D가 0일 땐 위 반복문이 작동하지 않으므로 기본적으로 시작점은 당연히 채워주기
통과~~

기발한 아이디어다. 맨해튼 거리와 관련 있는지? 모르겠는데 위와 같은 일정한 범위로 퍼지는 bfs는 
테두리만 채워주면 시간을 크게 절약할 수 있다는 걸 알게됨.

요약: 테두리만 체크해도 안은 어차피 못들어가니까 굳이 다 채워서 시간초과 하지말자.
*/