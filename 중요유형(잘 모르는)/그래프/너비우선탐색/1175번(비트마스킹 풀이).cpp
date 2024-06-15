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
#include <tuple>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, visited[51][51][3][4], res = -1;//y,x,curp,loc
int stx, sty, g1x = -1, g1y;
char m[51][51];
queue <t5> q;
string input;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int loc = get<3>(q.front());
        int curp = get<4>(q.front());

        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || i == loc) continue;

            if(m[ny][nx] == '.' && !visited[ny][nx][curp][i]){
                visited[ny][nx][curp][i] = 1;
                q.push(make_tuple(nx,ny,cnt + 1, i, curp));
            }

            if(m[ny][nx] == 'C'){
                int np = curp;
                if(nx == g1x && ny == g1y) np |= (1 << 0);
                else np |= (1 << 1);
                
                if(np == 3){ 
                    res = cnt + 1;
                    return;
                }

                if(!visited[ny][nx][np][i]){
                    visited[ny][nx][np][i] = 1;
                    q.push(make_tuple(nx,ny,cnt + 1, i, np));
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'S'){ stx = j; sty = i; m[i][j] = '.';}
            if(m[i][j] == 'C'){
                if(g1x == -1) { g1x = j; g1y = i;}
            }
        }
    }
    q.push(make_tuple(stx, sty, 0, -1, 0));//처음엔 모든 방향 가능하므로
    bfs();
    cout << res;
}
/*
첫 선물을 얻은 경우가 빠르다고 다음 2번째 선물을 얻은 경우가 더 빠르지는 않다는 것을 봐야하는 중요한 사례.

+ 비트마스킹 기초

C가 2개 있다고 할 때, C1 C2라 하면 2진수로 방문 상태를 표현할 수 있다.
즉 1이면 해당 C를 방문한 거고 0이면 방문하지 않은 것.

00 방문 X
01 1 방문
10 2 방문
11 1과 2 방문

1 << 0 1을 0번 왼쪽으로 옮긴 것. 01 = 1
1 << 1 1을 1번 왼족으로 옮긴 것. 10 = 2
1 << 3 1을 3번 왼쪽으로 옮긴 것. 1000 = 8
*/