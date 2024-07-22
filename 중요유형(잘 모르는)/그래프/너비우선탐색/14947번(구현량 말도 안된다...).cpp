#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1

#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};

int visited[3][501][501];//1*1
char m[501][501];
int N, M, res = -2;

struct info{
    int sx, sy, ex, ey, stat, cnt;//stat:1*3일 때 상자의 회전 상태(0: 가로로, 1: 세로로)
};

queue <info> q;

void bfs(){
    while(!q.empty()){
        auto [sx,sy,ex,ey,stat,cnt] = q.front();
        
        q.pop(); //cout << sy << ' ' << sx << ' ' << ey << ' ' << ex << ' ' << stat << ' ' << cnt << '\n';

        if(stat == 2){//1*1
            if(m[sy][sx] == '3'){ res = cnt; return;}
        }else{
            if(m[sy][sx] == '3' || m[ey][ex] == '3' || m[(sy + ey) / 2][(sx + ex) / 2] == '3'){ res = cnt; return;}
        }

        if(stat == 2){//1*1
            for(int i = 0;i<4;i++){
                int nsx = sx + dx[i], nsy = sy + dy[i];
                int nex = ex + dx[i] * 3, ney = ey + dy[i] * 3;
                int nstat; 
                if(i % 2) nstat = 1;
                else nstat = 0;

                if(nsx < 1 || nsy < 1 || nsx > M || nsy > N || nex < 1 || ney < 1 || nex > M || ney > N) continue;

                if(!visited[nstat][(nsy+ney)/2][(nsx+nex)/2]){
                    if((m[nsy][nsx] != '0' && m[ney][nex] != '0') || m[(nsy+ney)/2][(nsx+nex)/2] != '0'){
                        visited[nstat][(nsy+ney)/2][(nsx+nex)/2] = 1;
                        q.push({nsx,nsy,nex,ney,nstat,cnt + 1});
                    }
                }
            }
        }//1*3
        else{
            for(int i = 0;i<4;i++){//
                int nsx = sx, nsy = sy; 
                int nex = ex, ney = ey;
                int nstat = stat;

                if(stat){
                    if(i == 1){
                        if(nsy > ney) {nsy += dy[i] * 3; ney += dy[i];}
                        else {nsy += dy[i]; ney += dy[i] * 3;}
                    }else if(i == 3){
                        if(nsy < ney) {nsy += dy[i] * 3; ney += dy[i];}
                        else {nsy += dy[i]; ney += dy[i] * 3;}
                    }
                    else if(i == 0 || i == 2){ nsx += dx[i]; nex += dx[i];}
                }
                else{
                    if(i == 0){
                        if(nsx > nex) {nsx += dx[i] * 3; nex += dx[i];}
                        else {nsx += dx[i]; nex += dx[i] * 3;}
                    }
                    else if(i == 2){
                        if(nsx < nex) {nsx += dx[i] * 3; nex += dx[i];}
                        else {nsx += dx[i]; nex += dx[i] * 3;}
                    }
                    else if (i == 1 || i == 3){ nsy += dy[i]; ney += dy[i];}
                }

                if(nsx < 1 || nsy < 1 || nsx > M || nsy > N || nex < 1 || ney < 1 || nex > M || ney > N) continue;
                //cout << nsy << ' ' << nsx << ' ' << ney << ' ' << nex << '\n';

                if(nsx == nex && nsy == ney){//1*1
                    if(m[nsy][nsx] != '0' && !visited[2][nsy][nsx]){
                        visited[2][nsy][nsx] = 1;
                        q.push({nsx,nsy,nex,ney,2,cnt + 1});
                    }
                }
                else{//1*3
                    if(!visited[nstat][(nsy+ney)/2][(nsx+nex)/2]){
                        if((m[nsy][nsx] != '0' && m[ney][nex] != '0') || m[(nsy+ney)/2][(nsx+nex)/2] != '0'){
                            visited[nstat][(nsy+ney)/2][(nsx+nex)/2] = 1;
                            q.push({nsx,nsy,nex,ney,nstat,cnt + 1});
                        }
                    }
                }
            }
        } 
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j<M+1;j++){
            cin >> m[i][j];
            if(m[i][j] == '2'){
                visited[2][i][j] = 1;
                q.push({j,i,j,i,2,0});
                m[i][j] = '1';
            }
        }
    }

    bfs();
    cout << res << '\n';//printmap(N,M,m);
}
/*
양 면이 1, 한 면은 3의 길이를 가진 상자를 뜻하나?맞음.

구현량...실수...엄청나네...ㅋㅋㅋ

결정적인 역할은 아마도 방문 배열에서 stat을 기준으로 조정한 게 큰 듯 하다.
그 전엔 방향 값으로 설정했으나 그냥 무심코 다른 블로그 보고 어 이렇게 했네? 싶어서 
함 해봤더니 바로 통과...왜지??? 뭔 상관이노...
*/