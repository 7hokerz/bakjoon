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

#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select][0] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {1, -1, 0, 0}; int dy[] = {0, 0, -1, 1};

int N, M, K, m[1001][1001], visited[1001][1001][11], res = -1;
string input;
queue <piiii> q;//x,y,K,cnt(0이 낮, 1이 밤)

void bfs(){
    visited[1][1][0] = 1;
    q.push({{1,1}, {0,0}});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int Kcnt = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        if(x == M && y == N){res = cnt + 1; return;}

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

            if(m[ny][nx] == 1 && Kcnt < K && !visited[ny][nx][Kcnt + 1]){
                if(cnt % 2 == 0){
                    visited[ny][nx][Kcnt + 1] = 1;
                    q.push({{nx,ny},{Kcnt + 1,cnt + 1}});
                }
                else q.push({{x,y},{Kcnt,cnt + 1}}); 
            }

            if(m[ny][nx] == 0 && !visited[ny][nx][Kcnt]){
                visited[ny][nx][Kcnt] = 1;
                q.push({{nx,ny},{Kcnt,cnt + 1}});
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1] - 48;
        }
    } 
    bfs();
    //printmap3(N,M,1,visited);
    cout << res;
}
/*
시간도 그렇고 좀 많이 복잡한거 같아서 다른 사람 코드 참고하며 푼 문제.

중요! cnt + 2와 같이 특정 조건에서 조건을 만족하려고 이처럼 많이 내가 풀었었는데, 이는 
좋지 않은 방식. 너비 우선 탐색은 항상 첫 번째 조건이 최단 경로를 만족하는 특성을 지니는데
위처럼 해버리면 특성이 사라진다고 볼 수 있다. 따라서 진짜 모르겠는게 아닌 이상 
cnt + 2같은 방식은 사용하지 말자...

day를 4차원에 넣지 않고 어차피 cnt의 나머지 연산 특성을 이용하여 day를 가려낼 수 있다.
*/