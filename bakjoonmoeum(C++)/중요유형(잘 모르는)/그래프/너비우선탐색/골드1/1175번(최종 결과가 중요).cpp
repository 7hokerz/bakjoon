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
typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef pair<int,int> pii; typedef pair<pii,int> lpii; typedef pair<int,pii> rpii;
typedef pair<pii,pii> piiii;//더블 pii
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, visited[51][51][3][4], res = -1;//y,x,curp,loc
int stx, sty, g1x, g1y, g2x, g2y;
char m[51][51];
queue <pair<piiii, int>> q;//x,y, cnt, loc
string input;

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first.first;
        int y = q.front().first.first.second;
        int cnt = q.front().first.second.first;
        int loc = q.front().first.second.second;
        int curp = q.front().second;

        q.pop();

        if(curp == 2){
            if(res == -1) res = cnt; 
            else res = min(res, cnt);
            return;
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > M || ny > N || i == loc) continue;

            if(m[ny][nx] == '.' && !visited[ny][nx][curp][i]){
                visited[ny][nx][curp][i] = 1;
                q.push({{{nx,ny},{cnt + 1, i}}, curp});
            }

            if(m[ny][nx] == 'C' && !visited[ny][nx][curp + 1][i]){
                if((curp == 0 && nx == g1x && ny == g1y) || (curp == 1 && nx == g2x && ny == g2y)){
                    visited[ny][nx][curp + 1][i] = 1; 
                    q.push({{{nx,ny},{cnt + 1, i}}, curp + 1});
                }
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    bool chk = false;
    for(int i = 1;i<N+1;i++){ cin >> input;
        for(int j = 1;j<M+1;j++){
            m[i][j] = input[j-1];
            if(m[i][j] == 'S'){ stx = j; sty = i; m[i][j] = '.';}
            if(m[i][j] == 'C'){
                if(!chk) { g1x = j; g1y = i; chk = true;}
                else { g2x = j; g2y = i;}
            }
        }
    }

    q.push({{{stx,sty},{0,-1}},0});//처음엔 모든 방향 가능하므로
    bfs();

    fill_n(&visited[0][0][0][0], 51*51*3*4, 0);
    while(!q.empty()) q.pop();
    swap(g1x, g2x); swap(g1y, g2y);

    q.push({{{stx,sty},{0,-1}},0});//처음엔 모든 방향 가능하므로
    bfs();
    cout << res;
}
/*
첫 선물을 얻은 경우가 빠르다고 다음 2번째 선물을 얻은 경우가 더 빠르지는 않다는 것을 봐야하는 중요한 사례.
처음 최단 거리가 전체 최단 거리라고 보장할 수 없음.

4 8
#...S...
.....#.#
......CC
........
위와 같은 예제에서 9가 잘 나올 수 있는 이유?
접근 방향이 다르기 때문이다.

처음 먼저 잡는 건 7일 때 C의 왼쪽에서 오는 경우지만
8일 때 C의 아래에서 오는 경우가 존재하고 이는 겹치지 않는다. 즉 방문 처리가 따로 된다.
7 >> 10이 되고, 8 >> 9가 되므로 먼저 두 번째에 방문한 9가 출력된다.

(하지만 비트마스킹 풀이가 더 낫지롱...)
*/