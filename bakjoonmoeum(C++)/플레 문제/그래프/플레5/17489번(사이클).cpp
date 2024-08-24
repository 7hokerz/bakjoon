#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};//WSEN

string inp, input;
int N, M, L, K = 0, mxcnt = -1; pii en;
bool vis[2][101][101];
char m[101][101];

void dfs(int x, int y, int cnt){ //cout << y << ' ' << x << ' ' << cnt << '\n';

    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
        //cout << ny << ' ' << nx << ' ' << cnt + 1 << '\n';

        if(m[ny][nx] == inp[(cnt + 1) % L]){//순서에 맞는 글자를 확인한 경우
            
            if(!vis[0][ny][nx]) vis[0][ny][nx] = 1;

            else if(!vis[1][ny][nx]) vis[1][ny][nx] = 1;

            else{//사이클이 존재하면 -1 출력
                cout << -1; exit(0);
            } 
            
            dfs(nx,ny,cnt + 1);
            mxcnt = max(mxcnt, cnt + 1); 
            K = max(K,(cnt + 2) / L);

            if(K*L-1 == cnt + 1){
                en.first = nx, en.second = ny;
            }

            if(vis[1][ny][nx]) vis[1][ny][nx] = 0;
            else vis[0][ny][nx] = 0;
        }
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> L >> inp;

    for(int i = 1;i<N+1;i++) for(int j = 1;j<M+1;j++) cin >> m[i][j];
    
    vis[0][1][1] = 1;
    dfs(1,1,0);

    if(K == 0){
        if(N == 1 && M == 1 && L == 1 && inp[0] == m[1][1]){
            cout << 1 << '\n' << 1 << ' ' << 1 << '\n';
        }
        else cout << -1;
    }
    else cout << K << '\n' << en.second << ' ' << en.first << '\n';
}
/*
방문 배열 0>> 처음 방문 시, 1>> 두 번째 방문 시
0과 1이 모두 방문 처리된 경우에 다시 방문하면 사이클이 존재한다고 간주하고 -1 처리
*/