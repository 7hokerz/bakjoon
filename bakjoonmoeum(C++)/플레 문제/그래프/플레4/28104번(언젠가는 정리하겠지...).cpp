#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

int N, M, Q, res = -1, xs, ys, ts, x2, y2, t2, grnum = 1;
int iscycle[62501][2], visited[2][501][501][2];
//iscycle: 1 >> 해당 그룹의 사이클 유무, 2 >> 최대 카운트
//visited: nt,ny,nx,(0 >> 그룹 번호, 1 >> 카운트)
char m[501][501];

void dfs(int x, int y, int t, int cnt, bool mod);

void check(int nx, int ny, int nt, int cnt, bool mod){
    if(visited[nt][ny][nx][0] == -1){
        visited[nt][ny][nx][0] = grnum; visited[nt][ny][nx][1] = cnt + 1;

        if(mod) visited[nt][ny][nx][1] = -visited[nt][ny][nx][1];
        //사이클이 아니고 시작점이 가장자리가 아닌 중간일 때 카운트를 올바르게 출력하기 위해 사용
        //부호를 반대로 하여 총 길이를 올바르게 출력함.
        dfs(nx,ny,nt,cnt + 1,mod);
    }
    else if(!visited[nt][ny][nx][1] && cnt != 1) {
        iscycle[grnum][0] = 1; iscycle[grnum][1] = cnt + 1;
    }
}

void dfs(int x, int y, int t, int cnt, bool mod){//cout << y << ' ' << x << ' ' << t << ' ' << cnt << '\n';
    int nx = x, ny = y, nt = t;

    if(m[y][x] == 'N'){
        if(t == 0){// N 또는 E
            nx = x + dx[3]; ny = y + dy[3]; nt = 1;
            
            if(nx > 0 && ny > 0 && nx <= M && ny <= N) check(nx,ny,nt,cnt,mod);

            if(cnt == 0) mod = 1;

            nx = x + dx[2]; ny = y + dy[2];
            if(nx > 0 && ny > 0 && nx <= M && ny <= N){
                if(m[ny][nx] == 'Z') nt = 0;
                check(nx,ny,nt,cnt,mod);
            }
        }
        else{// S 또는 W
            nx = x + dx[1]; ny = y + dy[1]; nt = 0;
        
            if(nx > 0 && ny > 0 && nx <= M && ny <= N) check(nx,ny,nt,cnt,mod);

            if(cnt == 0) mod = 1;

            nx = x + dx[0]; ny = y + dy[0];
            if(nx > 0 && ny > 0 && nx <= M && ny <= N) {
                if(m[ny][nx] == 'Z') nt = 1;
                check(nx,ny,nt,cnt,mod);
            }
        }
    }
    else{
        if(t == 0){// N 또는 W
            nx = x + dx[3]; ny = y + dy[3]; nt = 1;
        
            if(nx > 0 && ny > 0 && nx <= M && ny <= N) check(nx,ny,nt,cnt,mod);

            if(cnt == 0) mod = 1;

            nx = x + dx[0]; ny = y + dy[0];
            if(nx > 0 && ny > 0 && nx <= M && ny <= N){
                if(m[ny][nx] == 'N') nt = 0;
                check(nx,ny,nt,cnt,mod);
            }
        }
        else{// S 또는 E
            nx = x + dx[1]; ny = y + dy[1]; nt = 0;
        
            if(nx > 0 && ny > 0 && nx <= M && ny <= N) check(nx,ny,nt,cnt,mod);

            if(cnt == 0) mod = 1;

            nx = x + dx[2]; ny = y + dy[2];
            if(nx > 0 && ny > 0 && nx <= M && ny <= N){
                if(m[ny][nx] == 'N') nt = 1;
                check(nx,ny,nt,cnt,mod);
            }
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    fill_n(&visited[0][0][0][0], 2*501*501*2, -1);
    cin >> N >> M >> Q;
    for(int i = 1;i<N+1;i++) for(int j = 1;j<M+1;j++) cin >> m[i][j];
    
    for(int i = 1;i<N+1;i++)
        for(int j = 1;j<M+1;j++)
            for(int k = 0;k<2;k++)
                if(visited[k][i][j][0] == -1){
                    visited[k][i][j][0] = grnum; visited[k][i][j][1] = 0;
                    dfs(j,i,k,0,0); grnum++;
                }
            
    for(int i = 1;i<Q+1;i++){
        cin >> ys >> xs >> ts >> y2 >> x2 >> t2;
        
        if(visited[ts][ys][xs][0] != visited[t2][y2][x2][0]) cout << -1 << '\n';
        else{
            int maxcnt = max(visited[ts][ys][xs][1], visited[t2][y2][x2][1]);
            int mincnt = min(visited[ts][ys][xs][1], visited[t2][y2][x2][1]);
            //cout << maxcnt << ' ' << mincnt << ' ';
            res = maxcnt - mincnt;//총 거리(이동 횟수)
            if(iscycle[visited[ts][ys][xs][0]][0]) res = min(res, iscycle[visited[ts][ys][xs][0]][1] - res);
            //사이클이 존재하는 경우는 두 경우 중 작은 경우로 정한다.
            cout << res << '\n';
        }
    }
}

/*
코드가 적당히 드러워야 고칠지 말지 하지...아오....
처음에 너비 탐색으로 풀었다가 시간 초과로 퇴치 당함.
쿼리가 최대 30만개인데 매번 그걸 구하면 당연히...
그래서 DP + DFS로 모든 맵에 대해서 카운트 및 사이클 여부를 체크하고 
나중에 쿼리에 답할 때 위와 같은 계산으로 올바른 답을 출력하도록 함.
(코드가 뒤지게 드러운데 이거 맞나? ㅋㅋㅋ)
(아래는 패턴)

    N, t: 0(위)일 때, N 또는 E
    다음 위치
    N >> Z면 t = 1, N이면 t = 1
    E >> Z면 t = 0, N이면 t = 1

    N, t: 1(아래) S 또는 W
    S >> Z면 t = 0, N이면 t = 0
    W >> Z면 t = 1, N이면 t = 0


    Z, t: 0(위) N 또는 W
    N >> Z면 t = 1, N이면 t = 1
    W >> Z면 t = 1, N이면 t = 0

    Z, t: 1(아래) S 또는 E
    S >> Z면 t = 0, N이면 t = 0
    E >> Z면 t = 0, N이면 t = 1
*/