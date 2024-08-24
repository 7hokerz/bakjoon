#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, res = 0;
char m[21][21];
int visited[4][21][21][4][21][21];

struct info{
    int x, y, cnt, curdic, subx, suby, subdic, curstat, substat;
};

queue <info> q;

void rot(int dic, int cnt, int x, int y, int curdic, int subx, int suby, int subdic, int curstat, int substat){
    int ndic = (curdic + dic) % 4;
    int subndic = (subdic + dic) % 4;
    int nx = x + dx[ndic]; int ny = y + dy[ndic]; 
    int subnx = subx + dx[subndic]; int subny = suby + dy[subndic];

    if(curstat) {nx = x; ny = y;} if(substat) {subnx = subx; subny = suby;} 

    if(nx < 1 || ny < 1 || nx > N || ny > N || m[ny][nx] != 'E'){nx = x, ny = y;}
    if(subnx < 1 || subny < 1 || subnx > N || subny > N || m[subny][subnx] != 'E') {subnx = subx, subny = suby;}
    
    if(!visited[ndic][ny][nx][subndic][subny][subnx]) {
        q.push({cnt + 1, x, y, ndic, subx, suby, subndic, curstat, substat});
    }
}

void bfs(){//(위 방향을 기준, 오른쪽 방향은 서브로 둔다.)
    for(int i = 0;i<4;i++)
        for(int j = 0;j<4;j++)
            visited[i][N][1][j][N][1] = 1;
         
    q.push({0,1,N,3,1,N,2,0,0});

    while(!q.empty()){
        auto [cnt, x, y, curdic, subx, suby, subdic, curstat, substat] = q.front();

        q.pop(); //cout << cnt << ' ' << y << ' ' << x << ' ' << curdic << ' ' << suby << ' ' << subx << ' ' << subdic <<'\n';

        if(x == N && y == 1 && !curstat) curstat = 1;
        if(subx == N && suby == 1 && !substat) substat = 1;

        if(curstat && substat){ res = cnt; return;}

        //전진
        int nx = x + dx[curdic]; int ny = y + dy[curdic];
        int subnx = subx + dx[subdic]; int subny = suby + dy[subdic];

        if(curstat) {nx = x; ny = y;} 
        if(substat) {subnx = subx; subny = suby;} 

        if(nx < 1 || ny < 1 || nx > N || ny > N || m[ny][nx] != 'E') {nx = x; ny = y;}
        if(subnx < 1 || subny < 1 || subnx > N || subny > N || m[subny][subnx] != 'E') {subnx = subx; subny = suby;}

        if(!visited[curdic][ny][nx][subdic][subny][subnx]) {
            visited[curdic][ny][nx][subdic][subny][subnx] = 1;
            q.push({cnt + 1, nx, ny, curdic, subnx, subny, subdic, curstat, substat});
        }

        //우회전
        rot(3, cnt, x, y, curdic, subx, suby, subdic, curstat, substat);
        
        //좌회전
        rot(1, cnt, x, y, curdic, subx, suby, subdic, curstat, substat);
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<N+1;j++)
            cin >> m[i][j];
        
    bfs();
    cout << res;
}
/*
6차원 방문 배열을 쓰는 문제(5차원까진 줄일 수 있는 듯 하기도 하다?)
6차원 방문 배열을 써야한다는 걸 참고하긴 해서 사실상 힌트를 본 문제다...쉽지 않어
*/