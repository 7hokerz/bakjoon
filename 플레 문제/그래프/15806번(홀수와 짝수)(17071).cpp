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

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1}; int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int N, M, K, t, visited[301][301][2];
int one, two;
queue <lpii> q;//x,y,cnt
vector <pii> vt;//검사 좌표 저장

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        int chk = 0;
        q.pop();

        if(cnt == t) continue;

        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > N) {
                chk++; continue;
            }
            if(!visited[ny][nx][(cnt + 1) % 2]){
                visited[ny][nx][(cnt + 1) % 2] = 1;
                q.push({{nx,ny}, cnt + 1});
            }
        }
        if(chk == 8){//모든 방향이 범위를 벗어나는 경우
            visited[y][x][cnt % 2] = 0;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> t;
    for(int i = 0;i<M;i++){
        cin >> one >> two;
        q.push({{one, two},0});
        visited[two][one][0] = 1;
    }
    for(int i = 0;i<K;i++){
        cin >> one >> two;//x,y
        vt.push_back({one, two});
    }
    bfs();
    //printmap3(N,N,0,visited); printmap3(N,N,1,visited);

    for(int i = 0;i<vt.size();i++){
        int x = vt[i].first;
        int y = vt[i].second;
        if(visited[y][x][t % 2]) {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
}
/*
움직이는 방향이 나이트와 같다.
어느 지점에서 최초로 도착했을 때 시간이 n이면 n+2 n+4...에도 도달 가능함을 알 수 있다.
즉 짝수는 다음 번째 짝수, 홀수는 다음 홀수에도 도달 가능하다는 것이다.
중요한 건 짝수/홀수만 되는 게 아닌 둘 다 가능한 칸도 존재할 수 있다.

예외 처리 부분의 경우 맵의 범위를 벗어나면 해당 요소는 사라지는 것으로 취급한다는 것.
따라서 8방향 중 하나라도 맵의 범위에 들지 못할 경우 방문 표시를 취소해야한다.
*/