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
typedef tuple<int,int,int,int,int,int> t6;
#define mod 1'000'000'009
#define INF 2'000'000'001

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, res = -1, visited[8][8][(1<<8)][(1<<8)];
//행과 열을 따로 나눠 회전 상태 여부 표시
char m[8][8];
queue <t6> q;

void bfs(){
    visited[1][1][0][0] = 1;
    q.push(make_tuple(1,1,0,0,0,0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int rbit = get<3>(q.front());
        int cbit = get<4>(q.front());
        int rot = get<5>(q.front());

        q.pop(); //cout << y << ' ' << x << ' ' << cnt << ' ' << rbit << ' ' << cbit << '\n';

        if(x == M && y == N){
            res = cnt; return;
        }

        //회전하지 않은 경우
        if(rot == 0){//특정 비트에 대해 반전(XOR)
            int nrbit = rbit; nrbit ^= (1 << y);
            int ncbit = cbit; ncbit ^= (1 << x);
            //XOR의 특성을 이용하여 1이면 0, 0이면 1로 반전
            if(!visited[y][x][nrbit][ncbit]){
                visited[y][x][nrbit][ncbit] = 1;
                q.push(make_tuple(x,y,cnt + 1, nrbit, ncbit, 1));
            }//회전시킨 후 제자리에 큐 삽입
        }

        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int stat = ((rbit & (1<<y)) >> y ^ (cbit & (1<<x)) >> x);
            //현재 위치의 상태값(회전 상태인지 아닌지)
            int nstat = ((rbit & (1<<ny)) >> ny ^ (cbit & (1<<nx)) >> nx);
            //갈려는 위치의 상태값(회전 상태인지 아닌지)

            //현재 위치에서 갈 수 없는 곳(문이 존재 X)은 미리 통과
            if(m[y][x] == 'C'){
                if(i == 0 || i == 2) if(!stat) continue;
                else if(stat) continue;
            }
            if(m[y][x] == 'D'){
                if(i == 1 || i == 3) if(!stat) continue;
                else if(stat) continue;
            }
            
            if(nx < 1 || ny < 1 || nx > M || ny > N || m[ny][nx] == 'B') continue;
            
            if(!visited[ny][nx][rbit][cbit]){
                if(i == 0 || i == 2){
                    //갈려는 곳에 통과할 수 있는 문이 존재하는 지 확인
                    if(m[ny][nx] == 'C' && !nstat) continue;
                    if(m[ny][nx] == 'D' && nstat) continue;//왜 stat이라고 썼냐...
                }
                else{
                    if(m[ny][nx] == 'C' && nstat) continue;//왜 stat이라고 썼냐...
                    if(m[ny][nx] == 'D' && !nstat) continue;
                }

                visited[ny][nx][rbit][cbit] = 1;
                q.push(make_tuple(nx,ny,cnt + 1, rbit, cbit, 0));
            }
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
        }
    }
    bfs();
    cout << res;
}
/*
BFS + 비트마스킹 문제.
비트마스킹을 아직 잘 모르는 만큼 구현하기 까다로웠다. 실수도 잦았고.

튜플로 6개까지 담을 줄은 몰랐네...ㅋㅋㅋ
비트마스킹 중요한 부분
XOR 연산: 두 비트가 같으면 0, 다르면 1을 반환
특정 위치의 비트를 반전시킬 수 있음.
1100 ^ (1<<3) == 0100
1010 ^ (1<<3) == 1110

*/